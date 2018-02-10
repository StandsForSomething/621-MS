#include "main.h"

const int LFDrive = 2;
const int RFDrive = 3;
const int RBDrive = 8;
const int LBDrive = 9;

void initMotors() {
	blrsMotorInit(LFDrive, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(LBDrive, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(RFDrive, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(RBDrive, true, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(4, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(1, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(5, false, DEFAULT_SLEW_RATE, NULL);
	blrsMotorInit(6, false, DEFAULT_SLEW_RATE, NULL);
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

}

void arm(int power) {

}

