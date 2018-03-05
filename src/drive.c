#include "main.h"

//the amount of counts + the master sensor value the slave should target.
//without this the master will start ahead of the slave
#define MASTER_SLAVE_OFFSET 350

//this defines how many iterations the slave's target sensor value should be
//ahead of the master. each iteration is 20ms so the time in ms is the number
//below multiplied by 20
#define MASTER_SLAVE_OFFSET_TIME 9990

fbc_t LDriveFBC;
fbc_t RDriveFBC;
fbc_t MDriveFBC;
fbc_pid_t LDrivePID;
fbc_pid_t RDrivePID;
fbc_pid_t MDrivePID;

Encoder rightEnc;
Encoder leftEnc;

//if true, the left side of the drive targets the sensor value of the right side
//of the drive
bool driveStraight;

//how many iterations of the PID task since driveStraight was set to true
int driveStraightLoops = 0;

int LDriveSense() {
  return encoderGet(leftEnc);
}

int RDriveSense() {
  return encoderGet(rightEnc);
}

void driveL(int power) {
	blrsMotorSet(LDrive, power, false);
}

void driveR(int power) {
	blrsMotorSet(RDrive, power, false);
}

void turn(int left, int right, bool blocking) {
  encoderReset(leftEnc);
  encoderReset(rightEnc);
  driveStraight = false;
  fbcSetGoal(&LDriveFBC, left);
  fbcSetGoal(&RDriveFBC, right);

  while(blocking && !fbcIsConfident(&LDriveFBC) && !fbcIsConfident(&RDriveFBC)) {
    delay(20);
  }
}

void driveTask(void *ignore) {
  encoderReset(leftEnc);
  encoderReset(rightEnc);
  int slaveGoal;
  while(1) {
    if(driveStraight) {
      slaveGoal = RDriveSense() + MASTER_SLAVE_OFFSET;
      driveStraightLoops++;
      if(RDriveSense() > abs(RDriveFBC.goal) - 175) {
        slaveGoal = RDriveSense();
      }
      fbcSetGoal(&LDriveFBC, slaveGoal);
    }

    if(isAutonomous()) {
      fbcRunContinuous(&LDriveFBC);
      fbcRunContinuous(&RDriveFBC);
    }
    delay(20);
  }
}

void initDrive() {
  rightEnc = encoderInit(3, 4, true);
  leftEnc = encoderInit(5, 6, false);
	fbcInit(&LDriveFBC, &driveL, &LDriveSense, NULL, &fbcStallDetect, 10, 10, 25,
			1);
	fbcInit(&RDriveFBC, &driveR, &RDriveSense, NULL, &fbcStallDetect, 10, 10, 25,
			1);

	fbcPIDInitializeData(&LDrivePID, 0.4, 0, 70, 0, 0);
	fbcPIDInitializeData(&RDrivePID, 0.4, 0, 70, 0, 0);
	fbcPIDInit(&LDriveFBC, &LDrivePID);
  fbcPIDInit(&RDriveFBC, &RDrivePID);
  taskCreate(driveTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
}


