# Flame-Throwing Pumpkin (Adafruit Feather)

This project contains general assembly instructions and the device code for a remote controlled, flame throwing pumpkin. You should be able to build your own version of this from these instructions.

Now, before you panic over the dangerous nature of this project, please note that the Glade Automatic Spray Air Freshener only sprays fuel for less than a second, so all you'll get with this is a short burst of flame that should scare and startle visitors, but not harm them unless they are very close to the device.

It does shoot fire, so you should be VERY, VERY careful with this device. Keep all humans and animals 6 feet or more away from the device while it operates. I do not accept any responsibility for harm caused by and through your implementation of this project. Be careful.

## Background


Glade Automatic Spray Refill and Holder Kit, Air Freshener for Home and Bathroom, Cashmere Woods, 6.2 Oz
https://www.amazon.com/gp/product/B00MH7V0QC


4 Channel DC12V 433MHz Inching Relay Module Wireless RF Switch for Truck Lift Tailgate ,2 Transmitter and 1 Receiver
https://www.amazon.com/gp/product/B07W56RNXJ




This is the Microcontroller version of the project.

Connects to first, second, third ports on the remote control relay (port 4 is for the flame thrower)

Flashes a Neopixel FeatherWing, plays audio files.



## Assembly

1. Insert vertical post in base
2. Mount relay board on vertical post
3. Plug relay power brick into power strip
4. Wire Relay power onto relay board
5. Strap Bose speaker to front of vertical post
6. Cover frame with material
7. Mount bucket mount to vertical post
8. Screw bucket to bucket mount
9. Feed colored wires through bucket and bucket mount
10. Connect colored wires to the relay board (using image and bullet list in next section as an example)
11. Connect two USB cables to power strip
12. Connect one USB cable to the Bose Speaker
13. Feed the other cable through the bottom of the bucket and connect to the Feather assembly

## Relay Wiring Configuration

1. Power
2. Yellow
3. White
4. Green
5. Blue

As illustrated in the following picture.

![Relay Wiring](images/figure-01.png)