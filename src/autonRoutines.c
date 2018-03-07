#include "main.h"

//drive(genericInt-distance,TorF blocking)
//turn(genericInt-leftSideTurn,genericInt-rightSideTurn,TorF blocking)
//fbcSetGoal(&mogoFBC,genericInt-sensorValueTarget)
//1874 is the low whereas 3747 is the high for the mogo lift pot.

void progSkills(){
	//put lift down
	mogoSetGoal( 1874, true);
	delay(1200);
	//drive to put mogo into lift  
	drive(31, INCHES, true);
	delay(1000);
	//lift mogo into hold
	mogoSetGoal( 3600, false);
	delay(200);
	//turn towards twenty point zone
	turn(-670, 670, true);
	delay(1800);
	//drive into 20 point zone 
	drive(59.5, INCHES, true);
	delay(1200);
	//drop mogo into 20 point zone
	mogoSetGoal( 2200, false);
	delay(600);
	//back out
	drive(-23, INCHES, true);
	delay(1400);
	//line up on 2nd mogo
	turn(-250, 250, true);
	delay(1200);
	drive(13, INCHES, true);
	delay(1200);
	turn(-263, 263, true);
	delay(1200);
	//grab mogo
	mogoSetGoal(1874, true);
	drive(60, INCHES, true);
	delay(1000);
	mogoSetGoal(3774, true);
	drive(36, INCHES, true);
	delay(1200);
	turn(-100, 100, true);
	delay(1200);
	drive(35, INCHES, true);
	
	
	
	
	
	
    
	
	
	
}