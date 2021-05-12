# Server Setup
## NOTE, I expect you have worked on Flask before

+ Clone the repository
+ Copy the content of [this directory](/RaspberryPi_Code) to the place from where you'll host the server
+ Host the Flask app to your local network, watch this [tutorial](https://www.youtube.com/watch?v=yMbiW45O_RA)
+ Now you should get this screen when you enter the raspberry pi's local ip on browser
![Image](https://i.ibb.co/T2rQbCK/Screenshot-from-2021-05-12-19-07-58.png)
+ Change the absolute path of pwmVal.txt file in init.py line 39
+ Change the permission of file pwmVal.txt using command `sudo chmod 777 pwmVal.txt`
+ Also change the project folder path in file app.wsgi