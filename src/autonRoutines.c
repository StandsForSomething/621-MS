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
	drive(28, INCHES, true);
	delay(600);
	
	//lift mogo into hold
	mogoSetGoal( 3600, false);
	delay(900);
	
	//turn towards twenty point zone
	turn(-1000, 1000, true);
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
	turn(-266, 266, true);
	delay(1200);
	
	//grab mogo
	mogoSetGoal(1874, true);
	drive(60, INCHES, true);
	delay(1000);
	mogoSetGoal(3774, true);
	
	//score mogo
	drive(36, INCHES, true);
	delay(1200);
	turn(-100, 100, true);
	delay(1200);
	drive(35, INCHES, true);
	
	//back out
	drive(-6, INCHES, true);
	delay(600);
	drive(8, INCHES, true);
	delay(600);
	drive(-23, INCHES, true);
}

void statGoal() {
	intakeSetState(HOLD_CONE);
	drive(-15, INCHES, true);
	delay(700);
	armSetGoal(172, false);
	delay(200);
	mogoSetGoal(1874, true);
	delay(300);
	intakeSetState(OUTAKE_CONE);
	delay(500);
	armSetGoal(25, true);
	delay(500);
	turn(0, 500, true);
	delay(700);
	drive(48, INCHES, true);
	mogoSetGoal(3774, true);
	delay(200);
	turn(-820, 820, true);
	delay(600);
	armSetGoal(255, true);
	drive(6, INCHES, true);
	delay(1000);
	drive(50, INCHES, true);
}
void test() {

drive(1000,TICKS, true);
 }
 
 void conePush() {
    armSetGoal(CAGE_CONE_HEIGHT, false);
	delay(2000);
    drive(-55,INCHES, true);
 }