#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


// Program State
#define OFF 1 
// Cruise State
#define ON 2
#define DISABLE 3 
#define STANDBY 4
#define SPEED_MIN 30.0
#define SPEED_MAX 150.0
#define PEDALS_MIN 3.0
#define SPEED_INC 2.5

float saturateThrottle(float throttleIn, bool* saturate);
float regulateThrottle(int isGoingOn, float cruiseSpeed, float vehicleSpeed);
