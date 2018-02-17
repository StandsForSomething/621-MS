#include "main.h"

const int LFDrive = 2;
const int RFDrive = 3;
const int RBDrive = 8;
const int LBDrive = 9;
const int mogoLift = 4;
const int arm = 6;

const int mogoPot = 8;

fbc_t mogoFBC;
fbc_pid_t mogoPID;

void initMotors() {
	blrsMotorInit(LFDrive, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(LBDrive, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(RFDrive, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(RBDrive, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(mogoLift, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(arm, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(1, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(5, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(7, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(10, false, DEFAULT_SLEW_RATE,  NULL);
	motorManagerInit();
	
	//set all motors to 0
	for(int i = 1; i < 10; i++) {
		blrsMotorSet(i, 0, true);
	}
}

void driveL(int power) {
	blrsMotorSet(LFDrive, power, false);
	blrsMotorSet(LBDrive, power, false);
}

void driveR(int power) {
	blrsMotorSet(RFDrive, power, false);
	blrsMotorSet(RBDrive, power, false);
}
void mogo(int power) {
	blrsMotorSet(mogoLift, power, false);
}

void armSet(int power) {
	blrsMotorSet(arm, power, false);

}

int mogoSense() {
	return analogRead(mogoPot);	
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