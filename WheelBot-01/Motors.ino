void rotate() {
  brakeOff();
  leftForward(SPEED_LOW, 0);
  rightBackward(SPEED_LOW, 0);
  delay(790);
}

void turnRight() {
  brakeOff();
  leftForward(SPEED_LOW, 0);
  rightBackward(SPEED_LOW, 0);
  delay(500);
}

void turnLeft() {
  brakeOff();
  leftBackward(SPEED_LOW, 0);
  rightForward(SPEED_LOW, 0);
  delay(500);
}

void goForward(unsigned int speed, unsigned int time) {
  leftForward(speed - LEFT_DECREASE, 0);
  rightForward(speed - RIGHT_DECREASE, 0);
  if (time > 0) {
    delay(time);
  }
}
void leftForward(unsigned int speed, unsigned int time) {
  brakeOff();
  digitalWrite(LEFT_DIRECTION, HIGH);
  leftSpeed(speed);
  if (time > 0) {
    delay(time);
  }
}
void rightForward(unsigned int speed, unsigned int time) {
  brakeOff();
  digitalWrite(RIGHT_DIRECTION, LOW);
  rightSpeed(speed);
  if (time > 0) {
    delay(time);
  }
}

void goBackward(unsigned int speed, unsigned int time) {
  leftBackward(speed, 0);
  rightBackward(speed, 0);
   if (time > 0) {
    delay(time);
  }
}
void leftBackward(unsigned int speed, unsigned int time) {
  digitalWrite(LEFT_DIRECTION, LOW);
  leftSpeed(speed);
  if (time > 0) {
    delay(time);
  }
}
void rightBackward(unsigned int speed, unsigned int time) {
  digitalWrite(RIGHT_DIRECTION, HIGH);
  rightSpeed(speed);
  if (time > 0) {
    delay(time);
  }
}

void changeSpeed(unsigned int speed) {
  leftSpeed(speed);
  rightSpeed(speed);
}
void leftSpeed(unsigned int speed) {
  analogWrite(LEFT_SPEED, speed);
}
void rightSpeed(unsigned int speed) {
  analogWrite(RIGHT_SPEED, speed);
}

void brakeOn(unsigned int time) {
  leftBrakeOn(0);
  rightBrakeOn(0);
  if (time > 0) {
    delay(time);
  }
}
void leftBrakeOn(unsigned int time) {
  digitalWrite(LEFT_BRAKE, HIGH);
  if (time > 0) {
    delay(time);
  }
}
void rightBrakeOn(unsigned int time) {
  digitalWrite(RIGHT_BRAKE, HIGH);
  if (time > 0) {
    delay(time);
  }
}

void brakeOff() {
  leftBrakeOff();
  rightBrakeOff();
}
void leftBrakeOff() {
  digitalWrite(LEFT_BRAKE, LOW);
}
void rightBrakeOff() {
  digitalWrite(RIGHT_BRAKE, LOW);
}

int getLeftConsumption() {
  return analogRead(LEFT_SNS);
}
int getRightConsumption() {
  return analogRead(RIGHT_SNS);
}

void logCurrentConsumption(String msg) {
  Serial.print("Left motor current consumption ");Serial.print(msg);Serial.println(getLeftConsumption());
  Serial.print("Right motor current consumption ");Serial.print(msg);Serial.println(getRightConsumption());
}
