#include "main.h"

void _debugTask(void *ignore) {
  while(true) {
    printf("drive: %d, %d\n\r", LDriveSense(), RDriveSense());
    printf("arm: %d\n\r", armFBC.goal);
	printf("autonSelect %d\n\r", autonSelect());
	printf("mogoSense %d\n\r", mogoSense());	
    delay(500);
  }
}

void startDebug() {
  taskCreate(&_debugTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
}
