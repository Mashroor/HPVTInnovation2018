from gpiozero import LED
from lidar_lite import Lidar_Lite
from time import sleep

#initialize LIDAR module
lidar = Lidar_Lite()
connected = lidar.connect(1)
dist = lidar.getDistance()
#initializations
redLED= LED(5)
orangeLED= LED(6)
yellowLED= LED(13)
greenLED= LED(19)

#connection check
if connected < -1:
        print "Not Conected"
else:
    print "Connected"

while True:
    if dist < 609.6:     #20ft
        greenLED.on()
    if dist < 518.16:    #17ft
        yellowLED.on()
    if dist < 365.706:   #12ft
        orangeLED.on()
    if dist < 213.36:    #7ft
        redLED.on()
    if dist < 152.4:     #5ft
        redLED.blink()
    else:
        redLED.off()
        orangeLED.off()
        yellow.off()
        greenLED.off()
