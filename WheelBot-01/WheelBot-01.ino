#define DEBUG_MODE true
#define DEBUG_RATE 9600

#define LEFT_DECREASE 0
#define RIGHT_DECREASE 2

#define LEFT_SPEED 3
#define LEFT_DIRECTION 12
#define LEFT_BRAKE 9
#define LEFT_SNS A0

#define RIGHT_SPEED 11
#define RIGHT_DIRECTION 13
#define RIGHT_BRAKE 8
#define RIGHT_SNS A1

#define SPEED_MAX 255
#define SPEED_MEDIUM 150
#define SPEED_LOW 70
#define SPEED_ZERO 0

void setup() {
  initLogger();
  
  pinMode(LEFT_BRAKE, OUTPUT);
  pinMode(LEFT_DIRECTION, OUTPUT);

  pinMode(RIGHT_BRAKE, OUTPUT);
  pinMode(RIGHT_DIRECTION, OUTPUT);
}

void loop() {
  goForward(SPEED_LOW, 3500);
  brakeOn(500);
  
  rotate();
  brakeOn(1000);

  goForward(SPEED_LOW, 3500);
  brakeOn(500);

  while(1);
}
