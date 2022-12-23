#define pin1 2
#define pin2 3
#define pin3 4
#define pin4 5
#define pin5 6
#define pin6 7

void setup() {
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, INPUT);
  pinMode(pin6, INPUT);
  Serial.begin(9600);
}
int red[10];
int i = 0;
void loop() {
  // put your main code here, to run repeatedly:
  red[0] += digitalRead(pin1);
  red[1] += digitalRead(pin2);
  red[2] += digitalRead(pin3);
  red[3] += digitalRead(pin4);
  red[4] += digitalRead(pin5);
  red[5] += digitalRead(pin6);
  if (i > 1000) {
    for (int j = 0; j < 6; j++) {
      int c=red[j];
      Serial.print(j);
      if(c<800){
        Serial.print(" Ok         ");
      }else{
        Serial.print("            ");
      }
      red[j] = 0;
      
    }
    /*
    Serial.print(1000);
    Serial.print(",");
    Serial.print(0);
    */
    Serial.println("");
    i = 0;
  }
  i++;
}