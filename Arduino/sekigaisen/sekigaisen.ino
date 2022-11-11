void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int r=digitalRead(A0);
  Serial.println(r);
}
