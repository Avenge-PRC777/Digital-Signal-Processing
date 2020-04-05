clear;clc;close all;
display('**NOTE:Epsilon used here is ripple factor and is not in decibels**')
prompt='Do you want to enter logarithmic passband ripple or epsilon: 1-epsilon,0-Ap: ';
y=input(prompt);
if(y!=1)
prompt='Enter pass band ripple, Ap in dB: ';
Ap=input(prompt);
E=sqrt(1/(10^(-Ap/10))-1);
else
prompt='Enter epsilon value(>0), ripple factor(large value means more passband ripple): ';
while 1
E=input(prompt);
  if(E>=0)
    break
  end
  if(E<0)
    prompt='Epsilon should be positive, please enter positive value: ';
  end
end
end
prompt='Enter passband frequency(in Hz, in analog): ';
Wp=input(prompt);
prompt='Enter stop band frequency(in Hz, in analog): ';
Ws=input(prompt);
prompt='Enter sampling frequency(in Hz, in analog): ';
FS=input(prompt);
prompt='Enter stopband attenuation required(in dB)(positive value means more attenuation): ';
A=input(prompt);

prompt='Press 1-Butterworth,0-Chebyshev,type1: ';
inp=input(prompt);
if(inp==1)
[n,a,b]=butterdsp(E,A,Wp,Ws,FS);%Filter function called
else
[n,a,b]=chebyshevtype1dsp(E,A,Wp,Ws,FS);%Filter function called
end

prompt='Do you want to see magnitude and phase response(1-yes,0-no): ';
fl=input(prompt);
if(fl==1)
  [h,w]=freqz(b,a,1024,FS);
  mr=abs(h);
  mr=mr/abs(max(h));
  figure(1);
  subplot(2,1,1);plot(w,mr);axis tight;grid on;title('Magnitude Response');xlabel('Frequency(Hz)');ylabel('Magnitude');
  subplot(2,1,2);plot(w,(angle(h)*180)/pi);axis tight;grid on;title('Phase Response');xlabel('Frequency(Hz)');ylabel('Phase(degrees)');
else
  display('Thank you');
end