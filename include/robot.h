#ifndef ROBOT_H_
#define ROBOT_H_

#define MOGO_LOWEST 1916
#define MOGO_TOP 3000

#define CLAW_OPEN_POSITION 127
#define CLAW_CLOSE_POSITION 0
//motor ports
const int LFDrive;
const int RFDrive;
const int RBDrive;
const int LBDrive;
const int mogoLift;

fbc_t mogoFBC;
fbc_t armFBC;

void initMotors();
void mogo(int power);
void armSet(int power);
void clawServoSet(int position);
int mogoSense();
int armSense();
int autonSelect();
void fbcInitControllers();


#endif


