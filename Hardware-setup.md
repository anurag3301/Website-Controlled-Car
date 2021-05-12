## In this documentation Ill show you the Hardware setup and the code for Arduino and Raspberry Ri

### Required Items
1. Raspberry Pi 3/4 [Link](https://www.raspberrypi.org/products/raspberry-pi-4-model-b/)
2. Arduino Mega/Uno (preferably Mega) [Link](https://store.arduino.cc/usa/mega-2560-r3)
3. Bi-Directional Logic Level Converter [Link](https://robu.in/product/level-converter-4-channel/?gclid=CjwKCAjw-e2EBhAhEiwAJI5jg82XpjFWfAbGdkC5EumjAm13ML8FgaoelAgWokQVRVOVu-DNNE_OahoCQl0QAvD_BwE)
4. Gear motors 12V x2 [Link](https://www.amazon.in/Verve-VTM006-Geared-Motor-White/dp/B00RXSTSBE/ref=sr_1_2?dchild=1&keywords=12V+Geared+DC+Motor&qid=1620824539&sr=8-2)
5. Car Chassis [Link](https://www.flyrobo.in/advance-metal-chassis-for-robots-white?tracking=ads)
6. L293D Motor driver [Link](https://www.electronicscomp.com/l293d-dual-h-bridge-motor-driver-ic)
7. 12V DC power supply for arduino and 5V power supply for Raspberry pi

## Schematics for connection B/W arduino and Raspberry pi [Learn More](https://dronebotworkshop.com/i2c-arduino-raspberry-pi/)
![Arduino and Raspberrypi](https://i0.wp.com/dronebotworkshop.com/wp-content/uploads/2019/09/pi-arduino-with-converter.jpeg?w=768&ssl=1)

## Schematics for connection B/W arduino, L293D and motor [Learn More](https://lastminuteengineers.com/l293d-dc-motor-arduino-tutorial/)
![Arduino and motor](https://lastminuteengineers.com/wp-content/uploads/arduino/Wiring-L293D-Motor-Driver-IC-with-DC-Motors-Arduino.png)

# Code
## Arduino:
Upload this code to your arduno [Link](/Arduino_code/main.ino)
Make sure to update the pin no. according to you need

## Raspberry pi:
[This code](/RaspberryPi_Code/i2c.py) is responsible for data transer to arduino through the I2C bus