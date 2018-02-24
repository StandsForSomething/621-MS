#include "main.h"

//drive(genericInt-distance,TorF blocking)
//turn(genericInt-leftSideTurn,genericInt-rightSideTurn,TorF blocking)
//fbcSetGoal(&mobileGoalFBC,genericInt-sensorValueTarget)

void auton_1(){
	fbcSetGoal(&mogoFBC,200);
	turn(1120,1120,true);
	
}