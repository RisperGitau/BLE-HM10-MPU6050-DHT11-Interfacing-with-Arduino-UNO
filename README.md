# BLE-HM10-MPU6050-DHT11-Interfacing-with-Arduino-UNO.
BLE HM10 , MPU6050 , DHT11  Interfacing with Arduino UNO. 
This project was transmitting temperature and humidity data read from the dht 11 sensor via BLE HM10 module.
The MPU6050 gyroscope and accelerometer readings are also transmitted by the HM10 BLE module.
The sensors are interfaced with arduino UNO.

for the fritzing wiring diagram:

![image](https://user-images.githubusercontent.com/58802523/234358946-23f530b4-6695-446e-9573-15034877952b.png)

RUNNING THE CODE 

STEP 1 : Download the arduino IDE.
STEP 2 : Select the board Uno in the connection option .
STEP 3 : Ensure that the board is correctlt connected to a a com port
STEP 4 : Compile and Upoad the code to Arduino board that is well interfaced as shown on the fritzig wiring diagram.
STEP 5 : Open the serial monitor and see the sensor readind or data being transmitted.

TO VIEW THE READINGS ON AN APP

Use the Arduino Bluetooth Controller app .
Arduino Bluetooth Controller (HM10 Module) is an android application that is freely available
on Google Play Store. This application provides a simple interface for the HM-10 BLE Module
that can be used to view data transmitted from the UNO Device via Bluetooth


This is achieved by choosing the HM10 device. Click the search button on the home page
of the application and identify the BLE module by its name and MAC address. After selecting and pairing
the HM10 module, the sensor information of the BLE Tag can be viewed.

Sample view:


![image](https://user-images.githubusercontent.com/58802523/234378582-3ecc6b95-7177-4463-9532-63563456df66.png)
![image](https://user-images.githubusercontent.com/58802523/234378734-dcafb211-3c4f-43b1-82ca-41d804b9b02f.png)

