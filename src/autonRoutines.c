#include "main.h"

//drive(genericInt-distance,TorF blocking)
//turn(genericInt-leftSideTurn,genericInt-rightSideTurn,TorF blocking)
//fbcSetGoal(&mogoFBC,genericInt-sensorValueTarget)
//1874 is the low whereas 3747 is the high for the mogo lift pot.

void auton_1(){
	//put lift down
	mogoSetGoal( 1874, true);
	delay(1000);
	//drive to put mogo into lift  
	drive(31, INCHES, true);
	delay(1000);
	//lift mogo into hold
	mogoSetGoal( 3774, true);
	//turn towards twenty point zone
	turn(-480, 480, true);
	delay(1200);
	//drive into 20 point zone 
	drive(53.5, INCHES, true);
	delay(1200);
	//drop mogo into 20 point zone
	mogoSetGoal( 2120, true);
	drive(-18.5, INCHES, true);
	delay(1200);
	turn(-250, 250, true);
	delay(1200);
	drive(6, INCHES, true);
	delay(1200);
	turn(-218, 218, true);
	delay(1200);
	mogoSetGoal( 1874, true);
	drive(55, INCHES, true);
	delay(1200);
	mogoSetGoal( 3774, true);
	delay(1200);
	drive(36, INCHES, true);
	delay(1200);
	turn(-75, 75, true);
	
	
	
	
    
	
	
	
}