#include "main.h"

//drive(genericInt-distance,TorF blocking)
//turn(genericInt-leftSideTurn,genericInt-rightSideTurn,TorF blocking)
//fbcSetGoal(&mogoFBC,genericInt-sensorValueTarget)

void auton_1(){
	
	fbcSetGoal(&mogoFBC,1874);
	delay(50);
	drive(31, INCHES, true);
	fbcSetGoal(&mogoFBC,3747);
}