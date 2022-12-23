#define linepin0 A0
#define linepin1 A1
#define linepin2 A2
#define linepin3 A3
#define linepin4 A4
#define linepin5 A5

void setup() {
  pinMode(linepin0, INPUT);
  pinMode(linepin1, INPUT);
  pinMode(linepin2, INPUT);
  pinMode(linepin3, INPUT);
  pinMode(linepin4, INPUT);
  pinMode(linepin5, INPUT);
  
  Serial.begin(9600);
}
int* lineDetection(){
  int line[6];
  line[0]=analogRead(linepin0);
  line[1]=analogRead(linepin1);
  line[2]=analogRead(linepin2);
  line[3]=analogRead(linepin3);
  line[4]=analogRead(linepin4);
  line[5]=analogRead(linepin5);
  return line;
}
void loop() {

}
