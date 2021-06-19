# Website-Controlled-Car V1
This is fun project made by me in which you can control a Arduino RC car through any device using browser. Im hosting a web server on a raspberry pi which will work as the remote controller. Here is the archetecture behind it so far.
## The Archetecture
![Archetecture](https://i.ibb.co/tpj3FGW/Untitled-document-1.png)
## The Workflow
+ Read this for hardware setup [Link](Hardware-setup.md)
+ Read this for server setup [Link](Server-setup.md)
+ So everything starts with the Flask app, this serve the webpage for the joystick controller. 
+ The JavaScript in the webpage is responsible for the shoing the Joystick on screen, reading the joystick position and send the joystick position to the Flask backend using POST request in the `/send` route.
+ As the Flask app get the joystick position it calcuates the pwm values for the motors and send to arduino though I2C line. But here is problem I am not able to use the I2C bus using my Flask app so I used an another way.
+ The Flask app write the pwm values to a text file named `pwmVal.txt`.
+ Then an another python program named `i2c.py` is executed, this program read the pwm vaues from the pwmVal.txt file and send the pwmValues to arduino though the I2C bus
+ No the arduino fetches the pwm valus and run motors according to the pwm values. 

#### Check the working demo of the project [https://youtu.be/WVhgLSC9BpA](HERE)

### Hope you understood the project, if you have any doubt so post the query in the [discussion section](https://github.com/anurag3301/Website-Controlled-Car/discussions).
