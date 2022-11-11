#include <Wire.h>
#include <MadgwickAHRS.h>
Madgwick MadgwickFilter;
#define MPU6050_PWR_MGMT_1 0x6B
#define MPU_ADDRESS 0x68

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(MPU6050_PWR_MGMT_1);
  Wire.write(0x00);
  Wire.endTransmission();
  MadgwickFilter.begin(100);
}

void loop() {
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 14, true);
  while (Wire.available() < 14) {};
  int16_t axRaw, ayRaw, azRaw, gxRaw, gyRaw, gzRaw, Temperature;
  axRaw = Wire.read() << 8 | Wire.read();
  ayRaw = Wire.read() << 8 | Wire.read();
  azRaw = Wire.read() << 8 | Wire.read();
  Temperature = Wire.read() << 8 | Wire.read();
  gxRaw = Wire.read() << 8 | Wire.read();
  gyRaw = Wire.read() << 8 | Wire.read();
  gzRaw = Wire.read() << 8 | Wire.read();
  float acc_x = axRaw / 16384.0;
  float acc_y = ayRaw / 16384.0;
  float acc_z = azRaw / 16384.0;
  float gyro_x = gxRaw / 131.0;
  float gyro_y = gyRaw / 131.0;
  float gyro_z = gzRaw / 131.0;
  MadgwickFilter.updateIMU(gyro_x, gyro_y, gyro_z, acc_x, acc_y, acc_z);
  float roll = MadgwickFilter.getRoll();
  float pitch = MadgwickFilter.getPitch();
  float yaw = MadgwickFilter.getYaw();
  Serial.print(500);
  Serial.print(",");
  Serial.print(-500);
  Serial.print(",");
  Serial.print(roll);
  Serial.print(",");
  Serial.print(pitch);
  Serial.print(",");
  Serial.print(yaw);
  Serial.println("");
}