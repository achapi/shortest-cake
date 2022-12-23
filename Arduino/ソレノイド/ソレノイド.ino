void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(2, HIGH);
  delay(20);
  digitalWrite(2, LOW);
  delay(500);
}