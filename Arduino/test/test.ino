#include <math.h>
#define pinA1 33
#define pinA2 31
#define pinB1 35
#define pinB2 37
#define pinD1 23
#define pinD2 25
#define pinC1 27
#define pinC2 29
#define pwmA 2
#define pwmB 3
#define pwmD 4
#define pwmC 5
//CとDが入れ替わっているのは仕様
void motor(int m, int power = 0) {
  /*
     これはモーターを動かす関数であります。
     power=モーターのパワー(-255,255)
     m＝モーターの種類(A=1,B=2,C=3,D=4)
  */
  int p = (power >= 0) ? 0 : 1;
  int x[4] = { pinA1, pinB1, pinC1, pinD1 };
  int y[4] = { pinA2, pinB2, pinC2, pinD2 };
  int pwm[4] = { pwmA, pwmB, pwmC, pwmD };
  if (power == 0) {
    digitalWrite(x[m - 1], HIGH);
    digitalWrite(y[m - 1], HIGH);
    analogWrite(pwm[m - 1], 0);
  } else {
    digitalWrite(x[m - 1], LOW ^ p);
    digitalWrite(y[m - 1], HIGH ^ p);
    analogWrite(pwm[m - 1], abs(power));
  }
  return;
}

void stopMotor() {
  /*
     モーターを全て止める関数！
  */
  motor(1);
  motor(2);
  motor(3);
  motor(4);
  return;
}

double IRSensor() {
  /*
     IRSensorから取得した値から向ける角度を取得！
  */
  int c[8];
  for (int i = 0; i < 8; i++) c[i] = -1;
  for (int i = 0; i < 8; i++) {
    //IRSensorの値↓
    bool f = digitalRead(i /*something*/);
    if (f) {
      c[i] = (i - 4) * 45;
    }
  }
  double x = 0, y = 0;
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    if (c[i] != -1) {
      double t = c[i] * (M_PI / 180.0);
      x += cos(t);
      y += sin(t);
      cnt++;
    }
  }
  x /= cnt;
  y /= cnt;
  double r = atan2(y, x);
  r = (((r) / 2 / M_PI) * 360) + 180;  //角度に変換
  return r;
}

double nineAxis() {
  /*
     今向いている角度とボールとの角度の差分を取得して回しちゃおう
  */
  double r = digitalRead(0);
  double IR = IRSensor();
  double diff = IR - r;
  if (abs(diff) > 180) {
    diff = abs(diff) - 360;
  }
  return diff;
}


void checkMotorDebug() {
  //モーター1,2,3,4がどれか分かんなくなった用
  motor(1, 100);
  delay(500);
  stopMotor();
  motor(2, 100);
  delay(500);
  stopMotor();
  motor(3, 100);
  delay(500);
  stopMotor();
  motor(4, 100);
  delay(500);
  stopMotor();
  delay(1000);
}
void setup() {
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(pinC1, OUTPUT);
  pinMode(pinC2, OUTPUT);
  pinMode(pwmC, OUTPUT);
  pinMode(pinD1, OUTPUT);
  pinMode(pinD2, OUTPUT);
  pinMode(pwmD, OUTPUT);
}
void move(int speed, int r) {
  /*モーターを任意の角度に動かします。
    r=角度(0~360)
    speed=モーターのスピード(-255~255)
  */
  r = (r + 180) % 360;
  double rad = r * M_PI / 180.0;
  motor(1, speed * sin(rad - M_PI * 1 / 4));
  motor(2, speed * sin(rad - M_PI * 3 / 4));
  motor(3, speed * sin(rad - M_PI * 5 / 4));
  motor(4, speed * sin(rad - M_PI * 7 / 4));
}
void loop() {
  //checkMotorDebug();
}