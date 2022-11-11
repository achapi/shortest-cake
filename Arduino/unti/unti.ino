#define pin1 8
#define pin2 9
#define pin3 10
#define pin4 11
#define pwm1 5
#define pwm2 6
void setup() {
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
}

void loop() {
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
  analogWrite(pwm1,100);
  analogWrite(pwm2,100);
}
