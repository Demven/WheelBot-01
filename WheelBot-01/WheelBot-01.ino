#include <NewPing.h>
#include <CustomStepper.h>

#define DEBUG_MODE false
#define DEBUG_RATE 115200

#define STEPPER_1 22
#define STEPPER_2 24
#define STEPPER_3 26
#define STEPPER_4 28

#define SONAR_PING_PIN 39
#define SONAR_GROUND_PIN 43
#define SONAR_POWER_PIN 41
#define SONAR_MAX_DISTANCE 500
#define SONAR_MIN_DISTANCE 20

#define LEFT_DECREASE 2
#define RIGHT_DECREASE 0

#define LEFT_SPEED 11
#define LEFT_DIRECTION 13
#define LEFT_BRAKE 8
#define LEFT_SNS A1

#define RIGHT_SPEED 3
#define RIGHT_DIRECTION 12
#define RIGHT_BRAKE 9
#define RIGHT_SNS A0

#define SPEED_MAX 255
#define SPEED_MEDIUM 150
#define SPEED_LOW 80
#define SPEED_ZERO 0

#define CURRENT_CONSUMPTION_MAX 270

void setup() {
  initLogger();
  initSonar();
  initHead();
  
  pinMode(LEFT_BRAKE, OUTPUT);
  pinMode(LEFT_DIRECTION, OUTPUT);

  pinMode(RIGHT_BRAKE, OUTPUT);
  pinMode(RIGHT_DIRECTION, OUTPUT);
}

void loop() { 
  int currentDistance = getDistanceInCm();

  if (currentDistance > SONAR_MIN_DISTANCE || currentDistance == 0) {
    goForward(SPEED_LOW, 100);
    if (isStuck()) {
      brakeOn(200);
      goBackward(SPEED_MEDIUM, 300);
      brakeOn(100);
      lookAroundAndTurn();
    }
  } else if (currentDistance > 0) {
    brakeOn(100);
    goBackward(SPEED_MEDIUM, 150);
    brakeOn(100);
    lookAroundAndTurn();
  }
}
