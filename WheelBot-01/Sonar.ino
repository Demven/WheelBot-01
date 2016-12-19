NewPing sonar(SONAR_PING_PIN, SONAR_PING_PIN, SONAR_MAX_DISTANCE);

void initSonar() {
  pinMode(SONAR_GROUND_PIN,OUTPUT);
  pinMode(SONAR_POWER_PIN,OUTPUT);
  digitalWrite(SONAR_GROUND_PIN, LOW);
  digitalWrite(SONAR_POWER_PIN, HIGH);
}

int getDistanceInCm() {
  return sonar.ping_cm();
}
