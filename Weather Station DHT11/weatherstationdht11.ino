//   This program is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program.  If not, see <https://www.gnu.org/licenses/>.


// Import dependencies
// DHT requires a unified sensor driver from:
// https://github.com/adafruit/Adafruit_Sensor.git
// DHT requires a sensor library from:
// https://github.com/adafruit/DHT-sensor-library.git
// LCD should already be included in your IDE
#include "Adafruit_Sensor.h"
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

// Declare DHT pin and type
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht = DHT(DHTPIN, DHTTYPE);

// Initialize the LCD display according to your circuit
// For reference:
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Assign types to the photoresistor's pin count and values
int PhotoPin = A5;
int PhotoValue = 0;
int minLight;
int maxLight;
int lightLevel;
int adjustedLightLevel;
int off = 0;


void setup() {
  // set up the LCD's number of columns and rows and initialize the DHT 
  lcd.begin(16, 2);
  dht.begin();
}


void loop() {
  // Updates the values every 2 seconds
  delay(2000);
  
  // Assigns a minimum and maximum light values
  lightLevel = analogRead(PhotoPin);
  if (minLight > lightLevel) {
    minLight = lightLevel;
  }
  if (maxLight < lightLevel) {
    maxLight = lightLevel;
  }
  
  // Calibrates and converts the input to percent sunlight
  // 139 is my the minimum value from my circuit
  // 1016 is the maximum value from my circuit
  // For reference:
  // Percent is equal to (value-min)*100/(max-min)
  adjustedLightLevel = ((analogRead(PhotoPin)-139)*100L/(1016-139));
  
  // Set the LCD cursor to the the first line on the first column
  // Print the Percent Sunlight, a divider, and the words "Humid"
  lcd.setCursor(0, 0);
  lcd.print(adjustedLightLevel);
  lcd.print("% Sun | Humid ");
  
  // Set the LCD cursor the the second line on the first column
  lcd.setCursor(0, 1);
  // Read humidity from the DHT sensor
  float h = dht.readHumidity();
  // Read temperature in Fahrenheit from the DHT sensor
  float f = dht.readTemperature(true);
  
  // If the value is NaN then the LCD will print "ERROR
  if (isnan(h) || isnan(f)) {
    lcd.print("ERROR");
    return;
  }
  
  // Using the DHT values as well as the LCD cursor's location,
  // we will now print the temperature in degrees ((char)223) Fahrenheit,
  // a divider, as well as humidity displayed in percent
  lcd.print(f);
  lcd.print((char)223);
  lcd.print("F | ");
  lcd.setCursor(10,1);
  lcd.print(h);
  lcd.print("% ");
}

