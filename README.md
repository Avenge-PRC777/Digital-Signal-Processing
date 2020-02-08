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

- Real world signals are analog signals that is continuous in time, hence infinite values;
- Since, computer cannot handle infinite values, it needs to be sampled in time domain;
- To get frequency spectrum of sampled signal, we perform Discrete Time Fourier Transform(DTFT);
- But the spectrum of DTFT is continuous and needs to be sampled;
- So, sampling in frequency domain leads to Discrete Fourier Transform(DFT);

![](https://raw.githubusercontent.com/Avenge-PRC777/Digital-Signal-Processing/master/LAB_04/images/dtftformula.png)

> Discrete time fourier transform formula

![](https://raw.githubusercontent.com/Avenge-PRC777/Digital-Signal-Processing/master/LAB_04/images/dftformula.png)

> Discrete fourier transform formula

## Finding Pulse Period with DFT

- First, one moving averages the signal to smoothen it and remove high frequency noises;
- Then, one takes the DFT of the signal and finds the k index for which magnitude response is maximum;
- The first peak is taken in magnitude response;
- The corresponding frequency for a k index is **(kindex.sampling frequency)/(length of signal)**;
- The pulse rate is obtained as **(60 . pitch frequency[as computed above])**;

![](https://raw.githubusercontent.com/Avenge-PRC777/Digital-Signal-Processing/master/LAB_04/images/DFT.gif)

> DFT Spectrum showing periodicity(repeatitions)

![](https://raw.githubusercontent.com/Avenge-PRC777/Digital-Signal-Processing/master/LAB_04/images/DFTspectraNOFILTER.png)

> DFT spectrum without moving average filter

![](https://raw.githubusercontent.com/Avenge-PRC777/Digital-Signal-Processing/master/LAB_04/images/DFTspectraMA.png)

> DFT spectrum with moving average filter

``` cpp
const int L=75;
const int N=75;
float pi=3.141593522;
float sig[75]={-87.1730763754109}; //75 samples
float Fs=25;//25 Hz, sampling frequency
float* movavg=new float[75]; //moving average array
int window=20; //moving average window
float* dftReal=new float[75]; //array to store real values of dft of signal
float* dftImag=new float[75]; //array to store imaginary values of dft of signal
float** dftmatrixRealPart=new float*[75]; //array to store real values of dft MATRIX of signal
float** dftmatrixImagPart=new float*[75]; //array to store real values of dft MATRIX of signal
float maxm=-1000;
int kindex=0;


//Frequency is kFs/L;
void setup() {
    Serial.begin(9600);
    for(int i=0;i<75;i++)
    {
     dftmatrixRealPart[i]=new float[75];
     dftmatrixImagPart[i]=new float[75];
      }//2D Array initialization
    
    for(int n=0;n<L;n++)
    {
      dftmatrixRealPart[0][n]=1;dftmatrixRealPart[n][0]=1;//This block assumes N==L so loop is equal for column and row
      dftmatrixImagPart[0][n]=0;dftmatrixImagPart[n][0]=0;
      }//Inititalizing all values of 1st row and 1st column of real dft matrix to 1 and of imaginary dft matrix to 0
      
    for(int k=1;k<N-1;k++)
    {
      for(int n=k;n<L;n++)
      {
        dftmatrixRealPart[k][n]=cos((2*pi*k*n)/N);
        dftmatrixImagPart[k][n]=sin((2*pi*k*n)/N)*(-1);
        if(n!=k)
        {
         dftmatrixRealPart[n][k]=dftmatrixRealPart[k][n];
         dftmatrixImagPart[n][k]=dftmatrixImagPart[k][n];
          }
        }
      } //Finding DFT Matrix
      
     doMovingAverage(sig,movavg,10,75); //doing moving average which is available in helper functions file
     
     for(int k=0;k<N;k++)
     {
      float sumReal=0,sumImag=0;
      for(int n=0;n<L;n++)
      {
        sumReal+=(dftmatrixRealPart[k][n]*movavg[n]);
        sumImag+=(dftmatrixImagPart[k][n]*movavg[n]);
        }
        dftReal[k]=sumReal;
        dftImag[k]=sumImag;
      }// Multiplying dft matrix with cleaned signal
    
      for(int k=0;k<(N-1);k++)
      {
        float xy=sqrt((dftReal[k]*dftReal[k])+(dftImag[k]*dftImag[k]));
        if(xy>maxm&&(k<N/2))
        {
          maxm=xy;
          kindex=k;
          }
        } //Finding 1st value of k index for maximum magnitude
        Serial.print("Frequency for maximum magnitude spectrum is ");Serial.print((kindex*Fs)/N);Serial.println(" Hz");
        Serial.print("Pulse period is ");Serial.print(60*(kindex*Fs)/N);Serial.println(" BPM");
        
}

void loop() {
  for(int k=0;k<(N-1);k++)
  {
    float xy=sqrt((dftReal[k]*dftReal[k])+(dftImag[k]*dftImag[k])); //Printing Spectrum
    Serial.print(xy);
        Serial.println(',');
    }
}
```

``` MATLAB
y=load()
```

## Results

![](https://raw.githubusercontent.com/Avenge-PRC777/Digital-Signal-Processing/master/LAB_04/images/WithACF.png)

> Pulse rate found with Autocorrelation function

![](https://raw.githubusercontent.com/Avenge-PRC777/Digital-Signal-Processing/master/LAB_04/images/WithDFT.png)

> Pulse rate found with DFT method

- Error=**(80-71.43)/71.43=0.1199=11.99%**

>>>>>>> a75e612079e71da393283e09d2d20d23981aa151
