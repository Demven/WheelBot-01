void lookAroundAndTurn() {
  int leftDistance = getDistanceOnTheLeft();
  int rightDistance = getDistanceOnTheRight();

  // decide where to go
  if (leftDistance > rightDistance) {
    turnLeft();
  } else {
    turnRight();
  }
}

int getDistanceOnTheLeft() {
  int distanceOnTheLeft;
  
  // turn backwards to left
  leftBackward(SPEED_MEDIUM, 0);
  rightBackward(SPEED_LOW, 0);
  delay(300);
  brakeOn(200);

  distanceOnTheLeft = getDistanceInCm();

  // get back to straight position
  leftForward(SPEED_MEDIUM, 0);
  rightForward(SPEED_LOW, 0);
  delay(300);
  brakeOn(200);

  return distanceOnTheLeft;
}

int getDistanceOnTheRight() {
  int distanceOnTheRight;
  
  // turn backwards to right
  leftBackward(SPEED_LOW, 0);
  rightBackward(SPEED_MEDIUM, 0);
  delay(300);
  brakeOn(200);

  distanceOnTheRight = getDistanceInCm();

  // get back to straight position
  leftForward(SPEED_LOW, 0);
  rightForward(SPEED_MEDIUM, 0);
  delay(300);
  brakeOn(200);

  return distanceOnTheRight;
}

boolean isStuck() {
  boolean stuck = false;
  int leftCurrent = getLeftConsumption();
  int rightCurrent = getRightConsumption();
  if (leftCurrent > CURRENT_CONSUMPTION_MAX || rightCurrent > CURRENT_CONSUMPTION_MAX) {
    stuck = true;
  }

  return stuck;
}
