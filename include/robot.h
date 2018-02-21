#ifndef ROBOT_H_
#define ROBOT_H_
//motor ports
const int LFDrive;
const int RFDrive;
const int RBDrive;
const int LBDrive;
const int mogoLift;

fbc_t mogoFBC;

void initMotors();
void mogo(int power);
void armSet(int power);
int mogoSense();
void fbcInitControllers();
#endif

