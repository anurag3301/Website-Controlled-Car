import smbus2 as smbus
import time

data = [0, 0, 0, 0, 1]
count = 0
I2C_SLAVE_ADDRESS = 11  #slave address of arduino
I2Cbus = smbus.SMBus(1) #initialise the I2C bus

while True:
    # try block because you get file io and some i2c bus error sometime
    try:
        got = False     # setting variable got to false assuming the program didnt get the data
        
        f = open("pwmVal.txt", "r") # open file for reading
        data = list(map(int, f.readlines()[0].split())) #convert space seperated numbers into a list
        data[4] = 1 # expictly setting the led state to high
        print(data)

        # if you get some data then set the got variable to true
        for i in data:
            if i != 0:
                got = True
        
        # if you did get the data then write that data to the i2c bus
        if got:
            with smbus.SMBus(1) as I2Cbus:
                I2Cbus.write_i2c_block_data(I2C_SLAVE_ADDRESS, 0x00, data)
            count = 0
        else:
            count += 1
            if count > 5:
                # if you get all 0 values consecutively then write all 0 to i2c bus
                I2Cbus.write_i2c_block_data(I2C_SLAVE_ADDRESS, 0x00, [0, 0, 0, 0, 0])
        
        f.close()
        time.sleep(0.1)
    
    except:
        f.close()
        time.sleep(0.1)
