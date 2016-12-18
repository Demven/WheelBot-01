void initLogger() {
  #if DEBUG_MODE
    Serial.begin(DEBUG_RATE);
  #endif
}
