void setup() {
  // put your setup code here, to run once:
  pinMode(PC13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PC13, LOW);
  delay(50);
  digitalWrite(PC13, HIGH);
  delay(80);
  digitalWrite(PC13, LOW);
  delay(50);
  digitalWrite(PC13, HIGH);
  delay(1200);
}
