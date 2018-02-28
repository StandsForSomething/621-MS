/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

void operatorControl() {
	int turnDivisor = 4;
	int armSpeed;	
	bool clawOpen = false;
	bool armHold = false;
	
	while (1) {
		if(abs(joystickGetAnalog(1, 3)) > 15 || abs(joystickGetAnalog(1, 4)) > 15) {
			driveR(joystickGetAnalog(1, 3) - joystickGetAnalog(1,4) / turnDivisor);
			driveL(joystickGetAnalog(1, 3) + joystickGetAnalog(1,4) / turnDivisor);
		}
		else {
			driveR(0);
			driveL(0);
		}

		if(buttonGetState(JOY1_5U)) {
			turnDivisor = 1;
		}

		else {
			turnDivisor = 4;
		}
	
		if((!isJoystickConnected(2) && buttonIsNewPress(JOY1_5D)) ||
			buttonIsNewPress(JOY2_5D)) {
			if(clawOpen) {
				clawServoSet(CLAW_CLOSE_POSITION);
				clawOpen = false;
			}
		
			else if(!clawOpen) {
				clawServoSet(CLAW_OPEN_POSITION);
				clawOpen = true;
			}
		}
		
		fbcSetGoal(&mogoFBC, mogoSense() + (buttonGetState(JOY1_6U) * -600) +
										   (buttonGetState(JOY1_6D) * 600));
		if(!isJoystickConnected(2)) {
			armSpeed = -joystickGetAnalog(1, 2);
		}
		
		else {
			armSpeed = -joystickGetAnalog(2, 2); 
		}
		
		if(abs(armSpeed) > 15) {
			armHold = false;
			fbcSetGoal(&armFBC, armSense() + (armSpeed * 3));
		} 
		
		else if(!armHold) {
			fbcSetGoal(&armFBC,armSense());
			armHold = true;
		}
		
		//printf("mogoPot:%d\n\r", mogoSense());
		//printf("autonSelection:%d\n\r", autonSelect());
		printf("armSense:%d\n\r", armSense());
		delay(20);
	}
}
