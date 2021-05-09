import smbus2 as smbus                                                                                                                 
import time                                                                                                                            
                                                                                                                                       
I2C_SLAVE_ADDRESS = 11                                                                                                                 
                                                                                                                                       
data = list(map(int, input("Enter the four bytes: ").split()))                                                                         
                                                                                                                                       
I2Cbus = smbus.SMBus(1)                                                                                                                
with smbus.SMBus(1) as I2Cbus:                                                                                                         
    I2Cbus.write_i2c_block_data(I2C_SLAVE_ADDRESS, 0x00, data) 