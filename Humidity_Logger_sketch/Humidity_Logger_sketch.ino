/* Humidity Logger - Part of Giess-o-mat project
 * Logs Data of capacitive Sensor in a given time interval 
 */

#include <DS3231.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <I2CSensor_std.h>
#define CS 4
#define sensor 1
#define button 2
#define LED0 5
#define LED1 6
#define TimeDelayConst 5 //minutes, maximum: 1193*60

DS3231 Clock;
I2CSensor capSensor(0x71);

bool Century = false;
bool h12 = false;
bool PM = false;
unsigned long measureTimeDelay = TimeDelayConst * 60L; //minutes
unsigned long previousMillis = 0;
File dataFile;

// Function Prototypes
String timestampString (void);
void headertext (String filename);
void LEDblink (int LEDPin, int blinkTime);
int calculateMean(int pinNumber, int numberOfValues, int delayTime);

void setup() {
  Wire.begin(); // Start the I2C interface
  Serial.begin(57600); // Start the serial interface
  capSensor.begin(); // reset sensor
  delay(2000); // give some time to boot up
  pinMode(button, INPUT_PULLUP);
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, LOW);
  if (!SD.begin(CS)) {
    Serial.println("SD card not initialized");
    return;
  }
  Serial.println("SDcard initialized");
  dataFile = SD.open("datafile.txt", FILE_WRITE);
  if (dataFile) {
    Serial.println("File opened");

  }
  headertext(strrchr(__FILE__, '\\') + 1);  //get filename of sketch

  while (digitalRead(button) == HIGH) {
    delay(500);
  }
  Serial.println("Started measurement");
  dataFile.close();
  digitalWrite(LED0, HIGH);
  delay(1000);
}

void loop() {
  digitalWrite(LED1, HIGH);
  dataFile = SD.open("datafile.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.print(timestampString());
    dataFile.print("\t");
    dataFile.print(capSensor.getCapacitance());
    dataFile.print("\t");
    dataFile.println(capSensor.getCapacitanceProz());
    Serial.println("measurement taken");
    dataFile.close();
    digitalWrite(LED1, LOW);
    LEDblink(LED1, 4000);
    if (digitalRead(button) == HIGH) {
      digitalWrite(LED0, LOW);
      while (1) {
        delay(500);
      }
    }
    //delay(measureTimeDelay * 1000L); alte Wartefunktion
    while (millis() - previousMillis <= (measureTimeDelay * 1000L)) {
      delay(500);
    }
      previousMillis = millis();
  }
  else {
    while (1) {}
  }
}



