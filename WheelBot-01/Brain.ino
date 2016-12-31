void lookAroundAndTurn() {
  int leftDistance = getDistanceOnTheLeft();
  int rightDistance = getDistanceOnTheRight();
  int straightDistance = getDistanceInCm();

  // decide where to go
  if (straightDistance > leftDistance && straightDistance > rightDistance) {
    // stay straight
  } else if (leftDistance > rightDistance) {
    turnLeft();
  } else {
    turnRight();
  }
}

int getDistanceOnTheLeft() {
  int distanceOnTheLeftOne;
  int distanceOnTheLeftTwo;
  
  headRotateLeft();
  
  distanceOnTheLeftOne = getDistanceInCm();
  delay(10);
  distanceOnTheLeftTwo = getDistanceInCm();

  headRotateRight();

  return max(distanceOnTheLeftOne, distanceOnTheLeftTwo);
}

int getDistanceOnTheRight() {
  int distanceOnTheRightOne;
  int distanceOnTheRightTwo;
  
  headRotateRight();

  distanceOnTheRightOne = getDistanceInCm();
  delay(10);
  distanceOnTheRightTwo = getDistanceInCm();

  headRotateLeft();

  return max(distanceOnTheRightOne, distanceOnTheRightTwo);
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
