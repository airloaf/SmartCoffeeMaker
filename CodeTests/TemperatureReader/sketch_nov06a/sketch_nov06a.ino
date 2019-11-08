void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  float voltage = analogRead(A0) * 0.004882814;
  float degreesC = (voltage - 0.5) * 100.0;
  float farenheit = (degreesC * 9.0/5.0) + 32;

  Serial.print((float) millis()/1000.0f);
  Serial.print(',');
  Serial.println(farenheit);
  

}
