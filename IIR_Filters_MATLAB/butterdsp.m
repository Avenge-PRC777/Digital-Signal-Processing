function [NPole, a, b]=butterdsp( E , A , Wp , Ws, Fs )
  wp=2*pi*Wp/Fs;ws=2*pi*Ws/Fs;del2=10^(-A/20);%Conversion into digital frequency and getting stop band ripple.
  num=sqrt(1-(del2^2))/(del2*E);den=ws/wp;
  order=ceil(log10(num)/log10(den));%Order of filter required
  display('Order of filter is: ');display(order);
  k=0:1:order-1;
  k=k*2+1;k=k*(pi/(2*order));k=k+(pi/2);k=(cos(k)+j*sin(k));
  fcutoff=Wp*(E^(1/order));Wc=2*pi*fcutoff;
  display('Cutoff frequency of filter is: ');display(fcutoff);
  k=k*Wc;%poles in s-domain
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