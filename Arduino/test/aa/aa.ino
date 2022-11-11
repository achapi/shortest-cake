#define pin1 A0 

void setup() {
  pinMode(pin1,INPUT);
  Serial.begin(9600);
}

void loop() {
  int r=analogRead(pin1);
  Serial.println(r);
}
