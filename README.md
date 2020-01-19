# Digital-Signal-Processing
This repo contains some basic techniques for processing Digital Signals.

![](https://media.cheggcdn.com/study/026/0260950c-90d8-4fba-8889-946957400f9a/elec-6-img-1.png)

# About

- Analog signals are present all around us, may it be **temperature, heart rate or sound**;
- These signals need to be converted to digital form so that our computers can process and analyse the signals easily;

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/encoding.png?raw=true)

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/decoding.png?raw=true)

- So, I will include some signal processing techniques that I do in my lab along with some additional information to get you started;
- The motivation behind this is after getting yourself acquainted with the methods you can explore more in the world of **sensors, IoT, data processing and much more**;

Table of Contents
=================

* [Digital\-Signal\-Processing](#digital-signal-processing)
* [About](#about)
* [Table of Contents](#table-of-contents)
* [Prerequisites](#prerequisites)
* [Lab 01](#lab-01)
  * [Filters](#filters)
  * [Pole Zero Analysis](#pole-zero-analysis)
  * [Results](#results)

# Prerequisites

- **Arduino Due**(Arduino Uno may not support the processing strength required);

![](https://5.imimg.com/data5/JP/DW/MY-562456/arduino-due-r3-500x500.jpg)

> Arduino Due has 96 kilo bytes SRAM and 512 kilo bytes flash memory.

![](https://rukminim1.flixcart.com/image/352/352/learning-toy/h/t/f/diy-ecraft-arduino-uno-r3-original-imaefmesah8uz4rh.jpeg?q=70)

> Arduino Uno has 2 kilo bytes SRAM and 32 kilo bytes flash memory

- **MATLAB**(Octave or Python may also serve as an alternative to visualize plots);

# Lab 01

## Filters

- Filter is a system that either allows or rejects specific frequency components in the input to produce an output.
- There are many types of filters:
   + Low Pass Filter
   + High Pass Filter
   + All Pass Filter
   + Band Pass Filter
   + Band Stop Filter
   + Notch Filter
- The three filters in focus here are:
   + Moving average filter-A low pass filter
   + First order difference filter-A high pass filter
   + Three point central difference filter-A band pass filter
- Moving Average Filter:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/movingav.png?raw=true)

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/moveqZ.png?raw=true)

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/movtransferfunction.png?raw=true)

## Pole Zero Analysis
## Results
