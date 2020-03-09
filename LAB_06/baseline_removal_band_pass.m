digit_f=0:0.01:pi;fs=80;df=2*pi/fs;
lx=length(digit_f);
hw=ones(1,lx);
for i=1:lx
  hw(i)=(1-exp(-2*j*digit_f(i)))/(2.7933-1.364*exp(-2*j*digit_f(i))-1.0728*exp(-j*digit_f(i)));
endfor
figure(1);
mw=abs(hw);mw/=abs(max(mw));
aw=angle(hw);aw/=abs(max(aw));
halfpower=0:0.01:40;
yhalf=(1/sqrt(2))*ones(1,length(halfpower));
subplot(1,2,1);plot(digit_f/df,mw);hold on;plot(halfpower,yhalf);axis tight;grid on;
subplot(1,2,2);plot(digit_f/df,aw);hold on;plot(halfpower,yhalf);axis tight;grid on;