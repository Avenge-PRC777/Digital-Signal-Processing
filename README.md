<<<<<<< HEAD
# Digital-Signal-Processing
This repo contains some basic techniques for processing Digital Signals.

![](https://media.cheggcdn.com/study/026/0260950c-90d8-4fba-8889-946957400f9a/elec-6-img-1.png)

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
* [Lab 03](#lab-03)
  * [Autocorrelation](#autocorrelation)
  * [Autocorrelation on PPG Signal](#autocorrelation-on-ppg-signal)
  * [Autocorrelation on Speech Signal](#autocorrelation-on-speech-signal)
* [Lab 04](#lab-04)
  * [Discrete Fourier Transform](#discrete-fourier-transform)
  * [Finding Pulse Period with DFT](#finding-pulse-period-with-DFT)
  * [Results](#results)


# About

- Analog signals are present all around us, may it be **temperature, heart rate or sound**;
- These signals need to be converted to digital form so that our computers can process and analyse the signals easily;

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/encoding.png?raw=true)

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/decoding.png?raw=true)

- So, I will include some signal processing techniques that I do in my lab along with some additional information to get you started;
- The motivation behind this is after getting yourself acquainted with the methods you can explore more in the world of **sensors, IoT, data processing and much more**;

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
- **Moving Average Filter**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/movingav.png?raw=true)

> Input/Output relation

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/moveqZ.png?raw=true)

> Converting to Z-Transform

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/movtransferfunction.png?raw=true)

> Transfer function equation

- **First order difference filter**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/diff.png?raw=true)

> Input/Output relation

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/difftransfer.png?raw=true)

> Transfer function equation

- **Three point central difference filter**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/threep.png?raw=true)

> Input/Output relation

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/threepTrans.png?raw=true)

> Transfer function equation

## Pole Zero Analysis

- **Moving Average Filter**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PoleZeroLTwo.png?raw=true)

> Pole-Zero plot for L=2

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/magResMALTwo.png?raw=true)

> Magnitude Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PhaseRespMALTwo.png?raw=true)

> Phase Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PoleZeroL8.png?raw=true)

> Pole-Zero plot for L=8

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/magResMAL8.png?raw=true)

> Magnitude Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PhaseRespMAL8.png?raw=true)

> Phase Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PoleZeroL100.png?raw=true)

> Pole-Zero plot for L=100

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/magResMAL100.png?raw=true)

> Magnitude Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PhaseRespMAL100.png?raw=true)

> Phase Response

- **First order difference filter**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PoleZeroFirstOrder.png?raw=true)

> Pole-Zero plot

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/magResFirstOrder.png?raw=true)

> Magnitude Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PhaseRespFirstOrder.png?raw=true)

> Phase Response

- **Three point central difference filter**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PoleZeroThree.png?raw=true)

> Pole-Zero plot

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/MagResThree.png?raw=true)

> Magnitude Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PhaseRespThree.png?raw=true)

> Phase Response

## Results

- The given data set is that of ppg signal of 1000 sample points and sampled at 100Hz;
- **Moving average filter results**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/L2.png?raw=true)

> L=2; Blue-PPG signal, Red-Moving averaged ppg signal

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/L8.png?raw=true)

> L=8; Blue-PPG signal, Red-Moving averaged ppg signal

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/L100.png?raw=true)

> L=100; Blue-PPG signal, Red-Moving averaged ppg signal

- **High Pass Filters**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/FirstOrderOutput.png?raw=true)

> Blue-PPG signal, Red-Moving averaged ppg signal, Green- First Order Difference

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/ThreePoint.png?raw=true)

> Blue-PPG signal, Red-Moving averaged ppg signal, Green- Three Point Difference

- **Removing Baseline Drift**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/baselinedrift.png?raw=true)

> Blue-PPG signal, Red-Noide(first order difference), Green- PPG Signal without noise, Yellow- Moving averaged ppg signal, Purple- Baseline component, Indigo- PPG signal without baseline component

- **Moving average on difference operator**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/maondifference.png?raw=true)

> Blue-PPG signal, Red-Noide(first order difference), Green- Moving averaged first order difference
=======
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
   + Three point central difference filter-A high pass filter
- **Moving Average Filter**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/movingav.png?raw=true)

> Input/Output relation

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/moveqZ.png?raw=true)

> Converting to Z-Transform

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/movtransferfunction.png?raw=true)

> Transfer function equation

- **First order difference filter**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/diff.png?raw=true)

> Input/Output relation

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/difftransfer.png?raw=true)

> Transfer function equation

- **Three point central difference filter**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/threep.png?raw=true)

> Input/Output relation

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/threepTrans.png?raw=true)

> Transfer function equation

## Pole Zero Analysis

- **Moving Average Filter**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PoleZeroLTwo.png?raw=true)

> Pole-Zero plot for L=2

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/magResMALTwo.png?raw=true)

> Magnitude Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PhaseRespMALTwo.png?raw=true)

> Phase Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PoleZeroL8.png?raw=true)

> Pole-Zero plot for L=8

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/magResMAL8.png?raw=true)

> Magnitude Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PhaseRespMAL8.png?raw=true)

> Phase Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PoleZeroL100.png?raw=true)

> Pole-Zero plot for L=100

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/magResMAL100.png?raw=true)

> Magnitude Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PhaseRespMAL100.png?raw=true)

> Phase Response

- **First order difference filter**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PoleZeroFirstOrder.png?raw=true)

> Pole-Zero plot

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/magResFirstOrder.png?raw=true)

> Magnitude Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PhaseRespFirstOrder.png?raw=true)

> Phase Response

- **Three point central difference filter**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PoleZeroThree.png?raw=true)

> Pole-Zero plot

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/MagResThree.png?raw=true)

> Magnitude Response

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/PhaseRespThree.png?raw=true)

> Phase Response

## Results

- The given data set is that of ppg signal of 1000 sample points and sampled at 100Hz;
- **Moving average filter results**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/L2.png?raw=true)

> L=2; Blue-PPG signal, Red-Moving averaged ppg signal

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/L8.png?raw=true)

> L=8; Blue-PPG signal, Red-Moving averaged ppg signal

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/L100.png?raw=true)

> L=100; Blue-PPG signal, Red-Moving averaged ppg signal

- **High Pass Filters**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/FirstOrderOutput.png?raw=true)

> Blue-PPG signal, Red-Moving averaged ppg signal, Green- First Order Difference

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/ThreePoint.png?raw=true)

> Blue-PPG signal, Red-Moving averaged ppg signal, Green- Three Point Difference

- **Removing Baseline Drift**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/baselinedrift.png?raw=true)

> Blue-PPG signal, Red-Noide(first order difference), Green- PPG Signal without noise, Yellow- Moving averaged ppg signal, Purple- Baseline component, Indigo- PPG signal without baseline component

- **Moving average on difference operator**:

![](https://github.com/Avenge-PRC777/Digital-Signal-Processing/blob/master/LAB_01/images/maondifference.png?raw=true)

> Blue-PPG signal, Red-Noide(first order difference), Green- Moving averaged first order difference

# Lab 03
This lab is based on applying autocorrelation function to PPG signal and Speech signal.

## Autocorrelation
- Autocorrelation is defined as the correlation of signal with a delayed copy of itself;

![](https://raw.githubusercontent.com/Avenge-PRC777/Digital-Signal-Processing/master/LAB_03/images/autocorrelation.jpeg)

> Autocorrelation equation for continuous time domain

- Properties of autocorrelation signal:

  + Autocorrelation function is a function of delay;
  + It is an even signal;
  + It has maximum at zero delay;
  + It ranges from -1 to 1 and slowly dies out to 0 when delay is same as the length of the signal;

- Applications of autocorrelation include:
  
  + Detection of periodicity in a signal obscured by noise;
  + Detection of missing fundamental frequency in signal;
  + Removal of white noise;

- Detection of periodicity in signal:
  
  + From autocorrelation function we need to find the first zero crossing location;
  + From the first zero crossing location we need to find the location of the first maximum;
  + Doing so tells us after how much delay(shifting) there will be a strong similarity(hence periodicity);
  + Period(or Pitch period) is calculated as (**True location of second maximum)/(Sampling frequency**);

## Autocorrelation on PPG Signal
- PPG stands for Photoplethysmogram, where 'plethys' means measuring volume of an organ;
- Hence, PPG tries to capture heart rate information by measuring how much light is absorbed at the tips of our fingers;
- The heart rate obtained is called pulse period;
  + Pulse period is defined as (**60/pitch period**) where pitch period is determined by autocorrelation technique;
  + It is the resting pulse period and is measured in beats per minute(BPM);
  + Dataset of PPG signal contains 2000 samples sampled at 100Hz

![](https://raw.githubusercontent.com/Avenge-PRC777/Digital-Signal-Processing/master/LAB_03/images/PPG.gif)

> Blue-PPG signal;Red-Moving Averaged PPG Signal;Green- Autocorrelation signal

![](https://raw.githubusercontent.com/Avenge-PRC777/Digital-Signal-Processing/master/LAB_03/images/PPG.png)

> Obtained results for pulse period

## Autocorrelation on Speech Signal
- Speech signal is produced by our voice box;
  + For males, it is in range 65 to 260 Hz(approximately);
  + For females, it is in range 100 to 525 Hz(approximately);
- Pitch frequency can be calculated using autocorrelation as mentioned above;
  + Pitch frequency is found as (**1/Pitch period**);

![](https://raw.githubusercontent.com/Avenge-PRC777/Digital-Signal-Processing/master/LAB_03/images/Speech.gif)

> Blue-PPG signal;Red-Moving Averaged PPG Signal;Green- Autocorrelation signal

![](https://raw.githubusercontent.com/Avenge-PRC777/Digital-Signal-Processing/master/LAB_03/images/Speech.png)

> Obtained results for pitch frequency

# Lab 04

## Discrete Fourier Transform

## Finding Pulse Period with DFT

## Results

>>>>>>> a75e612079e71da393283e09d2d20d23981aa151
