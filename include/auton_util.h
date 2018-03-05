#ifndef AUTON_UTIL_H_
#define AUTON_UTIL_H_
#define TICKS 0
#define INCHES 1
#define FEET 2
#define TILES 3

//wheel size in inches
#define WHEEL_SIZE 4
#define TICKS_PER_ROTATION 360
#define TICKS_PER_INCH TICKS_PER_ROTATION / (WHEEL_SIZE * 3.14)

double ticksToDistance(double ticks, int outputType);
double distanceToTicks(double input, int outputType);
void drive(double distance, int type, bool blocking);

#endif
