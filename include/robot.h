#ifndef ROBOT_H_
#define ROBOT_H_
//motor ports
const int LFDrive;
const int RFDrive;
const int RBDrive;
const int LBDrive;

void initMotors();
void driveL(int power);
void driveR(int power);
void mogo(int power);
#endif

