void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  analogWrite(6,255);
}
