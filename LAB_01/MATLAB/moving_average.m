%Moving Average Filter
prompt='Enter L value:';
L = input(prompt);
%disp(L);

%y[n]=(1/L)*(x[n]+x[n-1]+....+x[n-(L-1)])
% Transfer function equation is (1/L)*(1-z^{-L})/(1-z^{-1})
b=zeros(1,L);
b(1)=1;b(L)=-1;
b=b*(1/L);
a=[1 -1];% 'b' is NUMERATOR coefficients and 'a' is DENOMINATOR coefficients

[h,w]=freqz(b,a,2001);%freqz is for negative powers of z
% 'n' here(i.e 2001) is n points equally spaced around the unit circle
%h here is H(w), frequency response for 2001 values of w(Angular frequency)
%H(w) is complex valued, it has phase and magnitude response
%abs(h) gives magnitude response, angle(h) gives phase in RADIANS([-pi,pi])

figure;
plot(w/(2*pi),20*log10(abs(h))); %20*log10() is to convert magnitude response into deciBels 
xlabel('Frequency(Hz)'); ylabel('Magnitude(deciBels)');axis tight;grid on;title('Magnitude Response');

figure;
plot(w/(2*pi), angle(h)*(180/pi));
xlabel('Frequency(Hz)'); ylabel('Phase(Degrees)');axis tight;grid on;title('Phase Response');

[z,p,k] = tf2zpk(b,a); %tf2zp is only for positive powers of z or s in numerator
%use tf2zpk for negative powers
%'k' is gain
fvtool(b,a,'polezero')
text(real(z)-0.1,imag(z)-0.1,'\bfZeros','color',[0 0.4 0])
text(real(p)-0.1,imag(p)-0.1,'\bfPoles','color',[0.6 0 0])