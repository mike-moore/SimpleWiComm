import time
import serial

ser = serial.Serial(
    port='/dev/ttyUSB0',
    baudrate=9600
)

ser.isOpen()

print 'Enter your commands below.\r\nInsert "exit" to leave the application.'

input=1
while 1 :
    input = raw_input(">> ")
    if input == 'exit':
        ser.close()
        exit()
    else:
        ser.write(input + '\r\n')
        out = ''
        time.sleep(1)
        while ser.inWaiting() > 0:
            out += ser.read(1)

        if out != '':
            print ">>" + out