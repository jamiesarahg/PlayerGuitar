const char* PROGMEM test = "Globally declared in Flash mem";

void setup() {
  Serial.begin(19200);
}

void loop() {
  Serial.println(F("Inline Flash mem"));
  Serial.println(test);
 delay (1000); 
}
