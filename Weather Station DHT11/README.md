# Weather Station DHT11

This repository contains the plans to build an Arduino Uno Weather Station using a DHT11 Temperature & Humidity Sensor.  This
includes a single Photoresistor to analyze relative light levels and outputs the data on an LCD screen.

## Getting Started

Before you begin, make sure you have the necessary dependencies/libraries:
1. https://github.com/adafruit/Adafruit_Sensor
2. https://github.com/adafruit/DHT-sensor-library
*Note: You may need to rename files to contain only basic letters and numbers, no spaces.
**Note: When importing libraries on any previous versions of Arduino IDE prior to version 1.6.4 you must restart your IDE

### Items Required

1. Arduino Uno or similar device
2. DHT11 Module or similar device
3. LCD Module or similar device
4. Photoresistor
5. 10k ohm Resistor
6. 5k ohm Resistor
7. 10k ohm Potentiometer
8. a small Button
9. Breadboard or similar device
10. Jumper Cables or Soldering Equipment

## Circuit

The circuit can be viewed with file: [WeatherStationDHT11.png] (WeatherStationDHT11.png)
Alternatively, Eagle schematics can be found in the file: [WeatherStationDTH11.sch](WeatherStationDHT11.sch)

## Issues
Currently the data within the repository can act as a prototype for learning about the Arduino Uno, however, the program is 
easily configurable to run consistently for long durations so long as issues are addressed such as:
  1. Sleeping - the device is constantly on and will require a sleep-cycle in order to run for longer periods
  2. Dedicated PCB - this will reduce the overall power to the device and allow for a smaller, more manageable form factor
  3. Wireless connectivity - the Weather Station DHT11 can easily be modified to connect with an ESP8266 or similar device
  4. Cloud/Smart Home connectivity - connect to your Cloud/Smart Home and log data over long periods
  5. Battery/Solar Power - LiPo batteries and Solar Cells can easily be configured within the system
  6. Water/Weatherproofing - Due to the unpredictable nature of the outdoors, a Water or Weatherproof housing is needed
  7. 
Assuming all the above issues are addressed and also assuming there is no the chance that more problems will arise in the 
future, the device will be capable of operating as an Open-Source Weather Station year-round.

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/BeatleJuicePack/47204bcc706e0e0c9e11d80e267f3d29) for details on our
code of conduct, and the process for submitting pull requests to us.

## Authors

* **BeatleJuice** - *Initial Work* - [BeatleJuicePack](https://github.com/BeatleJuicePack)
See also the list of [contributors](https://github.com/BeatleJuicePack/Arduino-Projects/contributors)

## License

This project is licensed under the GNU General Public License Version 3 - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgements

* A big thanks to any and all contributors, no matter how big or small the contribution it all helps.
