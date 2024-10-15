# Flame-Throwing Pumpkin (Adafruit Feather)

This project contains general assembly instructions and the device code for a remote controlled, flame throwing pumpkin. You should be able to build your own version of this from these instructions.

Now, before you panic over the dangerous nature of this project, please note that the Glade Automatic Spray Air Freshener only sprays fuel for less than a second, so all you'll get with this is a short burst of flame that should scare and startle visitors, but not harm them unless they are very close to the device.

It does shoot fire, so you should be VERY, VERY careful with this device. Keep all humans and animals 6 feet or more away from the device while it operates. I do not accept any responsibility for harm caused by and through your implementation of this project. Be careful.

## Background

I always wanted a flame throwing pumpkin, and finally built one. There are a lot of other plans on the Internet for this type of project, some that are very dangerous (like this one: https://www.instructables.com/Flamethrowing-Jack-O-Lantern/). 

This project uses a [Glade Automatic Spray Refill and Holder Kit, Air Freshener for Home and Bathroom, Cashmere Woods, 6.2 Oz](https://www.amazon.com/gp/product/B00MH7V0QC) and an oil lamp to create a short burst of flame out of the pumpkin's mouth. 

I used a small metal trash can painted orange as my 'pumpkin', mostly because I was lazy and wanted to be able to reuse it year after year. You can use a real pumpkin for this, but you'll have to use a pretty tall one due to the height of the Glade AUtomatic Spray Air Freshener that must fit inside.

For the remote control, I used the [4 Channel DC12V 433MHz Inching Relay Module Wireless RF Switch for Truck Lift Tailgate ,2 Transmitter and 1 Receiver](https://www.amazon.com/gp/product/B07W56RNXJ) which is no longer available from Amazon. There are a bunch of alternatives available on [Amazon](https://www.amazon.com/s?k=4+relay+remote+control&crid=2MKVFJA61FI9K&sprefix=4+relay+remote+control).

I wanted something that I could use to amaze small children on Halloween but also startle older children when they enter the yard. That's why I selected to use a 4-button remote control for this project, it allowed me to give the pumpkin different behaviors depending on which remote button I pushed. In the current configuration, it delivers the following behaviors:

- Button 1: Flashes the LEDs Yellow.
- Button 2: Flashes the LEDs Yellow and plays a scream through the speakers.
- Button 3: Flashes the LEDs Red and plays a scream through the speakers.
- Button 4: Shoots flame out of the pumpkin's mouth.


## Parts List

For this project, I used the following components:

- [Glade Automatic Spray Refill and Holder Kit, Air Freshener for Home and Bathroom, Cashmere Woods, 6.2 Oz](https://www.amazon.com/gp/product/B00MH7V0QC)
- [4 Channel DC12V 433MHz Inching Relay Module Wireless RF Switch for Truck Lift Tailgate ,2 Transmitter and 1 Receiver](https://www.amazon.com/gp/product/B07W56RNXJ)
- [Adafruit Feather M0 Basic Proto - ATSAMD21 Cortex M0](https://www.adafruit.com/product/2772)
- [Adafruit Music Maker FeatherWing - MP3 OGG WAV MIDI Synth Player](https://www.adafruit.com/product/3357)
- [NeoPixel FeatherWing - 4x8 RGB LED Add-on For All Feather Boards](https://www.adafruit.com/product/2945)
- [JVC CS-J620 300W 6.5" CS Series 2-Way Coaxial Car Speakers, Set of 2](https://www.amazon.com/gp/product/B00OO1ENP4)
- [Kinter K3118 Texas Instruments TI Digital Hi-Fi Audio Mini Class D Home Auto DIY Arcade Stereo Amplifier with 12V 3A Power Supply Black](https://www.amazon.com/gp/product/B0787BRQ2F)

If I were to do this project again today, I'd probably use the [Adafruit ESP32 Feather V2 - 8MB Flash + 2 MB PSRAM - STEMMA QT](https://www.adafruit.com/product/5400) board instead. That's my goto board nowadays and it allows me to run code on separate threads so I can watch from remote input on one thread while controlling the lights and audio playback on another thread.

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