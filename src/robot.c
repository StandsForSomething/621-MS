#include "main.h"

const int LFDrive = 2;
const int RFDrive = 3;
const int RBDrive = 8;
const int LBDrive = 9;
const int mogoLift = 4;
const int arm1 = 5;
const int arm2 = 6;
const int clawServo = 7;

const int mogoPot = 8;
const int autonSelection = 5;

fbc_t mogoFBC;
fbc_pid_t mogoPID;

void initMotors() {
	blrsMotorInit(LFDrive, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(LBDrive, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(RFDrive, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(RBDrive, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(mogoLift, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(arm1, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(arm2, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(clawServo, false, DEFAULT_SLEW_RATE, NULL);
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
	blrsMotorSet(arm1, power, false);
	blrsMotorSet(arm2, power, false);
}

void clawServoSet(int position) {
	blrsMotorSet(clawServo, position, false);
    
}

int mogoSense() {
	return analogRead(mogoPot);	
}

int autonSelect() {
	return analogRead(autonSelection);	
}


void fbcTask(void *ignore) {
	while(1) {
		fbcRunContinuous(&mogoFBC);
	}
}

void fbcInitControllers() {
	fbcInit(&mogoFBC, &mogo, &mogoSense, NULL, &fbcStallDetect, 1, 1, 50, 50);
	
	fbcPIDInitializeData(&mogoPID, 0.35, 0, 0, 0, 0);
	
	fbcPIDInit(&mogoFBC, &mogoPID);
	
	taskCreate(&fbcTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
}
