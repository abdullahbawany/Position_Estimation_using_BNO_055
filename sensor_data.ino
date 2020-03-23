#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <SoftwareSerial.h> 

#define BNO055_SAMPLERATE_DELAY_MS (100)

SoftwareSerial MyBlue(11 , 12); // RX | TX 
Adafruit_BNO055 myIMU = Adafruit_BNO055();
void setup() {
  // put your setup code here, to run once:

MyBlue.begin(9600);
Serial.begin(9600);
myIMU.begin();
delay(1000);
int8_t temp=myIMU.getTemp();
myIMU.setExtCrystalUse(true);

}

void loop() {
  // put your main code here, to run repeatedly:
imu::Vector<3> acc =myIMU.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
imu::Vector<3> gyro =myIMU.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
imu::Vector<3> mag =myIMU.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);

MyBlue.print("acceleration");
MyBlue.print(acc.x());
MyBlue.print("\n");
MyBlue.print(acc.y());
MyBlue.print("\n");
MyBlue.print(acc.z());
MyBlue.print("\n");

MyBlue.print("gyro");
MyBlue.print(gyro.x());
MyBlue.print("\n");
MyBlue.print(gyro.y());
MyBlue.print("\n");
MyBlue.print(gyro.z());
MyBlue.print("\n");

MyBlue.print("magnetic force");
MyBlue.print(mag.x());
MyBlue.print("\n");
MyBlue.print(mag.y());
MyBlue.print("\n");
MyBlue.print(mag.z());
MyBlue.print("\n");

delay(1000);
delay(BNO055_SAMPLERATE_DELAY_MS);
}
