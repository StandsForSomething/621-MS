#ifndef ROBOT_H_
#define ROBOT_H_

#define MOGO_LOWEST 1916
#define MOGO_TOP 3000

#define OUTAKE_CONE 0
#define INTAKE_CONE 1
#define HOLD_CONE 2
#define EMPTY 3

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
void intakeSet(int power);
int intakeSetState(int state);
int mogoSense();
int armSense();
int autonSelect();
void fbcInitControllers();


#endif


