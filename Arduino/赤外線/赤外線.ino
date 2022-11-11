void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}
int i = 0, sum = 0;
void loop() {
  // put your main code here, to run repeatedly:
  int r = digitalRead(A0);
  if (sum > 10000) {
    Serial.print(i);
    Serial.print(",");
    Serial.print(20000);
    Serial.print(",");
    Serial.print(10000);
    Serial.println("");
    i = 0;
    sum = 0;
  }
  i++;
  sum += r;
}