# Flame-Throwing Pumpkin

**Note:** This is a work in progress, please be patient with me.

Hi, I'm Sparky -  a remote controlled, flame throwing "pumpkin" (yes, I know it's a small metal trash can painted to look like a pumpkin. Pretend its a pumpkin for now; you can use an actual pumpkin for your implementation if you want.

![Sparky Portrait](/images/sparky.jpg)

This project contains general assembly instructions and the device code for the project; Yyo should be able to build your own version of this from these instructions. 

Now, before you panic over the dangerous nature of this project, please note that the Glade Automatic Spray Air Freshener only sprays fuel for less than a second, so all you'll get with this is a short burst of flame that should scare and startle visitors, but not harm them unless they are very close to the device.

It does shoot fire out of its mouth, so you should be VERY, VERY careful with this device. Keep all humans and animals 6 feet or more away from the device while it operates. I do not accept any responsibility for harm caused by and through your implementation of this project. Be careful.

Here's a demonstration of the project's flame throwing capabilities:

[![Flame Throwing Demonstration](https://img.youtube.com/vi/WcZAg1KJ5VQ/0.jpg)](https://www.youtube.com/watch?v=WcZAg1KJ5VQ)

And here's a complete demonstration of the project's capabilities (by our exchange student Jannis):

[![Full Demonstration](https://img.youtube.com/vi/NKz0V5vYwB8/0.jpg)](https://www.youtube.com/watch?v=NKz0V5vYwB8)

This is version 1 of the Flame Throwing Pumpkin project; the original and unimproved. For an updated version, Version 2, look here <<ADD LINK>>.

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

The original version of this project used a portable BlueTooth speaker for audio output, but I was never happy with the quality and volume from that particular device, so this year I upgraded the project with an amplifier and two 6" speakers.

## Parts List

For this project, I used the following components:

- [Glade Automatic Spray Refill and Holder Kit, Air Freshener for Home and Bathroom, Cashmere Woods, 6.2 Oz](https://www.amazon.com/gp/product/B00MH7V0QC)
- [4 Channel DC12V 433MHz Inching Relay Module Wireless RF Switch for Truck Lift Tailgate ,2 Transmitter and 1 Receiver](https://www.amazon.com/gp/product/B07W56RNXJ)
- [Adafruit Feather M0 Basic Proto - ATSAMD21 Cortex M0](https://www.adafruit.com/product/2772)
- [Adafruit Music Maker FeatherWing - MP3 OGG WAV MIDI Synth Player](https://www.adafruit.com/product/3357)
- [NeoPixel FeatherWing - 4x8 RGB LED Add-on For All Feather Boards](https://www.adafruit.com/product/2945)
- [JVC CS-J620 300W 6.5" CS Series 2-Way Coaxial Car Speakers, Set of 2](https://www.amazon.com/gp/product/B00OO1ENP4)
- [Kinter K3118 Texas Instruments TI Digital Hi-Fi Audio Mini Class D Home Auto DIY Arcade Stereo Amplifier with 12V 3A Power Supply Black](https://www.amazon.com/gp/product/B0787BRQ2F)

If I were to do this project again today, I'd probably use the [Adafruit ESP32 Feather V2 - 8MB Flash + 2 MB PSRAM - STEMMA QT](https://www.adafruit.com/product/5400) board instead. That's my goto board nowadays and it allows me to run code on separate threads so I can watch from remote input on one thread while controlling the lights and audio playback on another thread. See [Arduino ESP32 Running Tasks On Multiple Cores](https://johnwargo.com/posts/2023/arduino-running-tasks-on-multiple-cores/) for more information.
