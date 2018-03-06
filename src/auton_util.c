#include "main.h"

double ticksToDistance(double ticks, int outputType) {
  double ret = 0;
  switch(outputType) {
  case TICKS:
    ret = ticks;
    break;

  case INCHES:
    ret = ticks / TICKS_PER_INCH;
    break;

  case FEET:
    ret = ticks / (TICKS_PER_INCH / 12);
    break;

  case TILES:
    ret = ticks / (TICKS_PER_INCH / 24);
    break;
  }

  return ret;
}

double distanceToTicks(double input, int inputType) {
  double ret = 0;

  switch(inputType) {
  case TICKS:
    ret = input;
    break;

  case INCHES:
    ret = input * TICKS_PER_INCH;
    break;

  case FEET:
    ret = input * (TICKS_PER_INCH * 12);
    break;

  case TILES:
    ret = input * (TICKS_PER_INCH * 24.5);
  }

  return ret;
}

void drive(double distance, int type, bool blocking) {
	encoderReset(leftEnc);
	encoderReset(rightEnc);
	fbcSetGoal(&RDriveFBC, distanceToTicks(distance, type));
	fbcSetGoal(&LDriveFBC, distanceToTicks(distance, type));
	while(blocking && !fbcIsConfident(&RDriveFBC)) {
    delay(20);
  }
}

void mogoSetGoal(int goal, bool blocking) {
  fbcSetGoal(&mogoFBC, goal);
  while(blocking && !fbcIsConfident(&mogoFBC)) {
    delay(20);
  }
}

void armSetGoal(int goal, bool blocking) {
  fbcSetGoal(&armFBC, goal);
  while(blocking && !fbcIsConfident(&armFBC)) {
    delay(20);
  }
}
