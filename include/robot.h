#ifndef ROBOT_H_
#define ROBOT_H_

#define MOGO_LOWEST 1916
#define MOGO_TOP 3000

#define OUTAKE_CONE 0
#define INTAKE_CONE 1
#define HOLD_CONE 2
#define EMPTY 3

#define CAGE_CONE_HEIGHT 217


//motor ports
const int LDrive;
const int RDrive;
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
void buildLCDMenu();
void fbcInitControllers();


#endif


