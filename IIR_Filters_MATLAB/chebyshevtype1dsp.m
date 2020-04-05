function [NPole, a, b]=chebyshevtype1dsp( E , A , Wp , Ws, Fs )
  wp=2*pi*Wp/Fs;ws=2*pi*Ws/Fs;del2=10^(-A/20);%Conversion into digital frequency and getting stop band ripple.
  num=sqrt(1-(del2^2))/(del2*E);den=ws/wp;
  order=ceil(acosh(num)/acosh(den));%Order of filter required
  display('Order of filter is: ');display(order);
  order=5;
  k=0:1:order-1;
  k=k*2+1;k=k*(pi/(2*order));k=k+(pi/2);
  Beta=((sqrt(1+E^2)+1)/E)^(1/order);
  r2=2*pi*Wp*(Beta^2+1)/(2*Beta);r1=2*pi*Wp*(Beta^2-1)/(2*Beta);
  k=(r2*cos(k)+j*r1*sin(k));%poles in s-domain
  fcutoff=Wp*(E^(1/order));Wc=2*pi*fcutoff;
  display('Cutoff frequency of filter is: ');display(fcutoff);
  T=1/Fs;
  NPole=(2+T*k)./(2-T*k);%poles in z-domain,using bilinear transformation
  gain=real(prod(NPole));
  b=[1,1];
  a=[1,-NPole(1)];
  for i=2:length(NPole)
    a=conv(a,[1,-NPole(i)]);
    b=conv(b,[1,1]);
  endfor
  b=b*gain;
  a=real(a);
end