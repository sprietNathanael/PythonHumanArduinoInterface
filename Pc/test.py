import serial
import time

def write(pin,data,link):
    """
    Send to the Arduino the name of the output
    and the data to write
    """
    link.write("w"+pin+'\t'+data+'\n')
    

link = serial.Serial(port="COM4",baudrate=115200)   #The serial link
time.sleep(5)
write("11","2.5",link)
time.sleep(5)
write("11","5",link)
time.sleep(5)
link.close()
