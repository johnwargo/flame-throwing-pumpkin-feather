# Flame-Throwing Pumpkin

Hi, I'm Sparky -  a remote controlled, flame throwing "pumpkin." Yes, I know it's a small metal trash can painted to look like a pumpkin. Pretend its a pumpkin for now; you can use an actual pumpkin for your implementation if you want.

![Sparky Portrait](/images/sparky.jpg)

This project contains general assembly instructions and the device code for the project; You should be able to build your own version of this from these instructions. 

> Before you panic over the dangerous nature of this project, please note that the Glade Automatic Spray Air Freshener only sprays fuel for less than a second, so all you'll get with this is a short burst of flame that should scare and startle visitors, but not harm them unless they are very close to the device.

It does shoot fire out of its mouth, so you should be VERY, VERY careful with this device. Keep all humans and animals 6 feet or more away from the device while it operates. I do not accept any responsibility for harm caused by and through your implementation of this project. Be careful.

Here's a demonstration of the project's flame throwing capabilities:

[![Flame Throwing Demonstration](https://img.youtube.com/vi/WcZAg1KJ5VQ/0.jpg)](https://www.youtube.com/watch?v=WcZAg1KJ5VQ)

And here's a complete demonstration of the project (by our exchange student Jannis):

[![Full Demonstration](https://img.youtube.com/vi/NKz0V5vYwB8/0.jpg)](https://www.youtube.com/watch?v=NKz0V5vYwB8)

This is version 1 of the Flame Throwing Pumpkin project; the original and unimproved.

## Background

I always wanted a flame throwing pumpkin, so finally built one. There are a lot of other plans on the Internet for this type of project, some that are very dangerous (like this one: https://www.instructables.com/Flamethrowing-Jack-O-Lantern/). This one is simple and fairly safe (but still dangerous since, you know, it's shooting fire).

I used a small metal trash can painted orange as my 'pumpkin', mostly because I was lazy and wanted to be able to reuse it year after year. You can use a real pumpkin for this, but you'll have to use a pretty tall one due to the height of the Glade Automatic Spray Air Freshener that must fit inside.

This project uses a [Glade Automatic Spray Refill and Holder Kit, Air Freshener for Home and Bathroom, Cashmere Woods, 6.2 Oz](https://www.amazon.com/gp/product/B00MH7V0QC) and an oil lamp to create a very short burst of flame out of the pumpkin's mouth. 

For the remote control, I used the [4 Channel DC12V 433MHz Inching Relay Module Wireless RF Switch for Truck Lift Tailgate ,2 Transmitter and 1 Receiver](https://www.amazon.com/gp/product/B07W56RNXJ) which is no longer available from Amazon. There are a bunch of alternatives available on [Amazon](https://www.amazon.com/s?k=4+relay+remote+control&crid=2MKVFJA61FI9K&sprefix=4+relay+remote+control).

I wanted something that I could use to amaze small children on Halloween but also startle older children when they enter the yard. That's why I selected to use a 4-button remote control for this project, it allowed me to give the pumpkin different behaviors depending on which remote button I pushed. In the current configuration, it delivers the following behaviors:

- Button 1: Flashes the LEDs inside the pumpkin yellow.
- Button 2: Flashes the LEDs inside the pumpkin yellow and plays a scream through the speakers.
- Button 3: Flashes the LEDs Red and plays a scream through the speakers.
- Button 4: Shoots flame out of the pumpkin's mouth.

The original version of this project used a portable BlueTooth speaker for audio output, but I was never happy with the quality and volume from that particular device, so this year I upgraded the project with an amplifier and two 6" speakers. It sounds amazing.

## Parts List

For this project, I used the following components:

- [Glade Automatic Spray Refill and Holder Kit, Air Freshener for Home and Bathroom, Cashmere Woods, 6.2 Oz](https://www.amazon.com/gp/product/B00MH7V0QC)
- [4 Channel DC12V 433MHz Inching Relay Module Wireless RF Switch for Truck Lift Tailgate ,2 Transmitter and 1 Receiver](https://www.amazon.com/gp/product/B07W56RNXJ)
- [Adafruit Feather M0 Basic Proto - ATSAMD21 Cortex M0](https://www.adafruit.com/product/2772)
- [Adafruit Music Maker FeatherWing - MP3 OGG WAV MIDI Synth Player](https://www.adafruit.com/product/3357)
- [NeoPixel FeatherWing - 4x8 RGB LED Add-on For All Feather Boards](https://www.adafruit.com/product/2945)
- 2 x [Stacking Headers for Feather - 12-pin and 16-pin female headers](https://www.adafruit.com/product/2830)
- [JVC CS-J620 300W 6.5" CS Series 2-Way Coaxial Car Speakers, Set of 2](https://www.amazon.com/gp/product/B00OO1ENP4)
- [Kinter K3118 Texas Instruments TI Digital Hi-Fi Audio Mini Class D Home Auto DIY Arcade Stereo Amplifier with 12V 3A Power Supply Black](https://www.amazon.com/gp/product/B0787BRQ2F)

If I were to do this project again today, I'd probably use the [Adafruit ESP32 Feather V2 - 8MB Flash + 2 MB PSRAM - STEMMA QT](https://www.adafruit.com/product/5400) board instead. That's my goto board nowadays, and it allows me to run code on separate threads so I can watch for remote input on one thread while controlling the lights and audio playback on another thread. See [Arduino ESP32 Running Tasks On Multiple Cores](https://johnwargo.com/posts/2023/arduino-running-tasks-on-multiple-cores/) for more information.

## Scream Audio File Copy

Copy all of the project's audio files to the root of a Micro SD Card and insert it into the Adafruit Music Maker FeatherWing. If you want to use different audio files in your version of this project, simply copy the files over while maintaining the file naming convention used in the Audio Files folder.

## Hardware Assembly

Solder male headers to the underside of NeoPixel FeatherWing, it sits on top of the stack of Feather boards (so you can see the LEDs).

Solder stacking female headers to top of the Adafruit Music Maker FeatherWing.

Depending on how you want to connect everything together you can either solder female headers onto the top of the Adafruit Feather M0 Basic Proto and solder it to a [Adafruit Perma-Proto Half-sized Breadboard PCB](https://www.adafruit.com/product/1609) board (like I did) or simply solder female headers to the top of the board.

You should end up with a stack of components that looks something like this:

![Stacked Boards](/images/figure-01.jpg)

I used the Perma Proto board to connect everything together since it allowed me to pull out the connections to the Arduino input pins into screw connectors. This allows me to easily connect and disconnect the remote control relay board.

![All connections](/images/figure-02.jpg)

The project sketch uses an array of values to define which Input pins to use to read values from the remote control relays:

```c
int myPins[] = {A1, A2, A3};
```

Connect the first set of relay wires to the Feather's `A1` and `GND` connections.
Connect the second set of relay wires to the Feather's `A2` and `GND` connections.
Connect the third set of relay wires to the Feather's `A3` and `GND` connections.

If you decide to use different input pins on the Arduino device, just update the `myPins` array in the sketch accordingly.

The fourth set of relay wires connect directly to the Glade Air Freshener; the sketch doesn't do anything to control flame throwing.

## Hacking the Air Freshener

The air freshener operates by periodically spraying freshener in the room based on a setting on the back of the device. You can configure it to spray every 9, 18 or 36 minutes. The air freshener also has a button on the back you can use to force a spray whenever you want; this is where I hacked the device.

I opened up the device and found the two wires that connect to the button. Next, I cut those wires from the button's circuit board (you can see them to the left of the button in the following figure), disabling the button, and added wire extensions to the cut wires so I can connect them to the 4th relay on the remote control.

![Air Freshener](/images/figure-03.jpg)

The side effect of this approach is that I've done nothing to interrupt the timed spray. So, once you power on the device, not only will it shoot fire when you press the 4th button on the remote control, it will also periodically shoot fire on the predetermined schedule. If you don't want this behavior, you must disable that capability in the air freshener as well.

## Making Fire

To enable fire, you must put a small candle or oil lamp in front of the spray nozzle in the air freshener. Don't put it directly in front of the spray, experiment with it sightly below the nozzle. I used an oil lamp sitting on a piece of wood - mostly so I could be consistent with the flame. A candle will shorten throughout the night on Halloween and I didn't want to have to get up every so often and adjust candle placement.

---

You can find information on many different topics on my [personal blog](http://www.johnwargo.com). Learn about all of my publications at [John Wargo Books](http://www.johnwargobooks.com).

If you find this code useful and feel like thanking me for providing it, please consider <a href="https://www.buymeacoffee.com/johnwargo" target="_blank">Buying Me a Coffee</a>, or making a purchase from [my Amazon Wish List](https://amzn.com/w/1WI6AAUKPT5P9).
