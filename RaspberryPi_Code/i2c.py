import smbus2 as smbus
import time
data = [0, 0, 0, 0, 0]
count = 0
I2C_SLAVE_ADDRESS = 11
while True:
    try:
        got = False
        with open("pwmVal.txt", "r") as f:
            data = list(map(int, f.readlines()[0].split()))
        print(data)
        I2Cbus = smbus.SMBus(1)
        for i in data:
            if i != 0:
                got = True
        if got:
            with smbus.SMBus(1) as I2Cbus:
                I2Cbus.write_i2c_block_data(I2C_SLAVE_ADDRESS, 0x00, data)
            count = 0
        else:
            count += 1
            if count > 5:
                I2Cbus.write_i2c_block_data(I2C_SLAVE_ADDRESS, 0x00, [0, 0, 0, 0, 0])

        time.sleep(0.1)
    except:
        time.sleep(0.1)
