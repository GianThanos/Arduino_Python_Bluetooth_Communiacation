import serial
import time

port = '/dev/ttyUSB0'
ser = serial.Serial(port, 9600, timeout=1)
time.sleep(2)
user_input = 'L'

while user_input != 'q':
    user_input = input('H = on, L = off, q = quit'  )
    if user_input == 'h':
        ser.write(user_input.encode())
        print ('you wrote : ',user_input)
        
    if user_input == 'l':
        ser.write(user_input.encode())
        print ('you wrote : ',user_input)
        
    if user_input == 't':
        ser.write(user_input.encode())
        b = ser.readline()  
        time.sleep(0.1) 
        string_n = b.decode()   
        string = string_n.rstrip() 
        flt = str(string)        
        print(flt)
       
    time.sleep(0.5) # wait 0.5 seconds