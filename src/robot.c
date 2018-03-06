#include "main.h"

const int LDrive = 2;  //power expander A
const int RDrive = 3;  //power expander B
const int mogoLift = 4;  //power expander C
const int armLeft = 5;
const int armRight = 6;
const int intake = 7;  //power expander D

const int mogoPot = 8;
const int autonSelection = 5;

Encoder armEnc;

fbc_t mogoFBC;
fbc_pid_t mogoPID;

fbc_t armFBC;
fbc_pid_t armPID;

void initMotors() {
	blrsMotorInit(LDrive, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(RDrive, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(mogoLift, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(armLeft, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(armRight, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(intake, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(1, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(10, false, DEFAULT_SLEW_RATE,  NULL);
	motorManagerInit();
	
	//set all motors to 0
	for(int i = 1; i < 10; i++) {
		blrsMotorSet(i, 0, true);
	}
}

void mogo(int power) {
	blrsMotorSet(mogoLift, power, false);
}

void armSet(int power) {
	blrsMotorSet(armLeft, power, false);
	blrsMotorSet(armRight, power, false);
}

void intakeSet(int power) {
	blrsMotorSet(intake, power, false);
}

int intakeSetState(int state) {
	switch(state) {
		case OUTAKE_CONE:
			intakeSet(-127);
		break;
		
		case INTAKE_CONE:
			intakeSet(127);
		break;
		
		case HOLD_CONE:
			intakeSet(20);
		break;
			
		case EMPTY:
			intakeSet(0);
		break;
	}
	
	return state;
}

int mogoSense() {
	return analogRead(mogoPot);	
}

int armSense() {
	return encoderGet(armEnc);	
}

int autonSelect() {
	return analogRead(autonSelection);	
}

void fbcTask(void *ignore) {
	while(1) {
		fbcRunContinuous(&mogoFBC);
		fbcRunContinuous(&armFBC);
		delay(20);
	}
	
}

void buildLCDMenu() {
  newItem("no auton", NULL);
  newItem("auton 1", NULL);
}

void fbcInitControllers() {
  armEnc = encoderInit(7, 8, false);
	fbcInit(&armFBC, &armSet, &armSense, NULL, &fbcStallDetect, 1, 1, 50, 50);	
	fbcPIDInitializeData(&armPID, 3.3, 0, 70, 0, 0);
	fbcPIDInit(&armFBC, &armPID);
	
	fbcInit(&mogoFBC, &mogo, &mogoSense, NULL, &fbcStallDetect, 1, 1, 50, 50);	
	fbcPIDInitializeData(&mogoPID, 0.35, 0, 0, 0, 0);
	fbcPIDInit(&mogoFBC, &mogoPID);    
	
	taskCreate(&fbcTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
}
