y=load('ppgwithRespiration_25hz_30seconds.mat');
x=y.xppg;
x=x';
[l,~]=size(x);
myfft=fft(x,l);
figure(1);
subplot(1,2,1);
plot(x);axis tight;grid on;title('Input Signal');xlabel('Time');ylabel('Amplitude');
subplot(1,2,2);
plot(abs(myfft));axis tight;grid on;title('Frequency Spectrum');xlabel('Frequency');ylabel('Magnitude');

%Getting respiratory part only
myfft(1)=0;
myfft(17:l,:)=0;
xapp=ifft(myfft,l);
[~,loc]=max(myfft);
display("Respiratory rate in Breaths per minute: ");display((loc-1)*25*60/l);
figure(2);
subplot(1,2,1);
plot(abs(xapp));axis tight;grid on;title('Respiratory Signal only');xlabel('Time');ylabel('Amplitude');
subplot(1,2,2);
plot(abs(myfft));axis tight;grid on;title('Frequency Spectrum');xlabel('Frequency');ylabel('Magnitude');