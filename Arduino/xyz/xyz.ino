/*
===============================================================================================================
QMC5883LCompass.h Library XYZ Example Sketch
Learn more at [https://github.com/mprograms/QMC5883LCompass]

This example shows how to get the XYZ values from the sensor.

===============================================================================================================
Release under the GNU General Public License v3
[https://www.gnu.org/licenses/gpl-3.0.en.html]
===============================================================================================================
*/
#include <QMC5883LCompass.h>

QMC5883LCompass compass;
int xMax, xMin, yMax, yMin;
void setup() {
  Serial.begin(9600);
  compass.init();
  compass.read();
  int x, y, z;
  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();
  delay(200);
  xMax = x;
  xMin = x;
  yMax = y;
  yMin = y;
}
int xhoge = -630;
int yhoge = -70;
void loop() {
  int x, y, z;

  // Read compass values
  compass.read();

  // Return XYZ readings
  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();
  //xMax = max(x, xMax);
  //yMax = max(y, yMax);
  //xMin = min(x, xMin);
  //yMin = min(y, yMin);

  x += xhoge;
  y += yhoge;

  Serial.print(-1000);
  Serial.print(',');
  //Serial.print(atan(y / x) / M_PI * 180);
  Serial.print(atan2(y,x) / 3.14 * 180);
  Serial.print(",");
  //Serial.print(y);
  //Serial.print(",");
  /*Serial.print(xMax);
  Serial.print(',');
  Serial.print(xMin);
  Serial.print(',');
  Serial.print(yMax);
  Serial.print(',');
  Serial.print(yMin);
  Serial.print(',');
  /*
  Serial.print(x);
  Serial.print(',');
  Serial.print(y);
  Serial.print(',');
  Serial.print(z);
  Serial.print(',');
  //*/
  Serial.print(1000);
  Serial.println();
}