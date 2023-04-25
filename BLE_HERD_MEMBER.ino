#include <dht.h>
#include <SoftwareSerial.h>
#include<Wire.h>
#define dataPin 7
SoftwareSerial HM10(2, 3); // TX = 2, RX = 3
char appData;  
String inData = "";
float t;
float h;
float g;
float a;

dht DHT;

const int MPU6050_addr=0x68;
int16_t AccX,AccY,AccZ,Temp,GyroX,GyroY,GyroZ;

int minVal=265;
int maxVal=402;
 
double x;
double y;
double z;


void setup()
{
  Serial.begin(9600);
  Serial.println("HM10 and DHT11 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
  pinMode(7, OUTPUT);

  //gyroscope
  Wire.begin();
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
//  Serial.begin(9600);
  
}
void loop()
{
    //humtemp();
  t=tempdht();
  h=h;
//  g=AccX,AccY,AccZ,Temp,GyroX,GyroY,GyroZ;
 
  Serial.println("Test");
  Serial.println(h);
  Serial.println(t);
  Serial.println(g);

//for gyroscope
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);
  AccX=Wire.read()<<8|Wire.read();
  AccY=Wire.read()<<8|Wire.read();
  AccZ=Wire.read()<<8|Wire.read();
  Temp=Wire.read()<<8|Wire.read();
  GyroX=Wire.read()<<8|Wire.read();
  GyroY=Wire.read()<<8|Wire.read();
  GyroZ=Wire.read()<<8|Wire.read();

  int xAng = map(AccX,minVal,maxVal,-90,90);
   int yAng = map(AccY,minVal,maxVal,-90,90);
   int zAng = map(AccZ,minVal,maxVal,-90,90);
 
   x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
   y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
   z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
 
  Serial.print("Acceleration \n");
  Serial.print("AccX = "); Serial.print(AccX);
  Serial.print(" || AccY = "); Serial.print(AccY);
  Serial.print(" || AccZ = "); Serial.print(AccZ);
  Serial. println();
//  Serial.print("Temperature \n");
//  Serial.print(" Temp = "); Serial.print(Temp/340.00+36.53);
//  Serial. println();
  Serial.print("Gyroscope \n");
  Serial.print("GyroX = "); Serial.print(GyroX);
  Serial.print(" || GyroY = "); Serial.print(GyroY);
  Serial.print(" || GyroZ = "); Serial.println(GyroZ);
Serial.print("Gyro. Angle \n");
Serial.print("AngleX= ");
Serial.println(x);
 
Serial.print("AngleY= ");
Serial.println(y);
 
Serial.print("AngleZ= ");
Serial.println(z);
Serial.println("-----------------------------------------");

//  delay(1000);
  
//  delay(1000);
  senddata();
  delay(10000);
 
}
void senddata(){
  HM10.listen();  // listen the HM10 port
  delay(1000);
  Serial.println("Bluetooth listening");
  HM10.available();
  while (HM10.available() > 0) {   // if HM10 sends something then read
    appData = HM10.read();
    inData = String(appData);  // save the data in string format
    Serial.write(appData);
  }
 
  if (Serial.available()) {           // Read user input if available.
    delay(10);
    HM10.write(Serial.read());
  }
  if ( inData == "h") {
    Serial.println("Test1");
    Serial.println(h);
   HM10.print("Humidity \n");
    HM10.print(DHT.humidity);
    //digitalWrite(13, HIGH); // switch OFF LED
    delay(5);
  }
  if ( inData == "t") {
    Serial.println("Test2");
    Serial.println(t);
  HM10.print("Temperature \n");
    HM10.print(t);
    //digitalWrite(13, LOW); // switch ON LED
    delay(5);  
   }  
   
    if ( inData == "g") {
    Serial.println("Test3");
    Serial.println(g);
//   HM10.print(Temp/340.00+36.53);
HM10.print("Gyro. Angle \n");
 HM10.print("AngleX= ");
    HM10.println(x);
 HM10.print("AngleY= ");
    HM10.println(y);
 HM10.print("AngleZ= ");
    HM10.println(z);

    
    delay(5);  } 

     if ( inData == "a") {
    Serial.println("Test4");
    Serial.println(a);
HM10.print("Acceleration \n");
  HM10.print("AccX= ");
    HM10.println(AccX);
    
  HM10.print("AccY= ");
    HM10.println(AccY);
    
  HM10.print("AccZ= ");
    HM10.println(AccZ);
    delay(5);  
   }  

  
}
float tempdht(){
  int readData = DHT.read11(dataPin); // DHT11
  float t = DHT.temperature; // Gets the values of the temperature
  float h = DHT.humidity; // Gets the values of the humidity
  // Printing the results on the serial monitor
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" ");
  Serial.print((char)176);//shows degrees character
  Serial.print("C | ");
  Serial.print((t * 9.0) / 5.0 + 32.0);//print the temperature in Fahrenheit
  Serial.print(" ");
  Serial.print((char)176);//shows degrees character
  Serial.println("F ");
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  Serial.println("");

      

  return t;

}
