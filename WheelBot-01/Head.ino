CustomStepper stepper(STEPPER_1, STEPPER_2, STEPPER_3, STEPPER_4);

void initHead() {
  stepper.setRPM(12);
  stepper.setSPR(4075.7728395);
}

void headRotateRight() {
  stepper.setDirection(CW);
  stepper.rotateDegrees(90);
  while(!stepper.isDone()) {
    stepper.run();
  }
}

void headRotateLeft() {
  stepper.setDirection(CCW);
  stepper.rotateDegrees(90);
  while(!stepper.isDone()) {
    stepper.run();
  }
}

