% Problem 3b
close all % closes plotting windows
a=-5; b=5;
n=32;
x=linspace(1,2*n+1,n+1);
xin = (a+b)/2 + (b-a)/2 * cos(x*pi/(2*n+2));
yin= 1./(1+xin.^2);
xout=linspace(a,b,100);
[yout, cof] = interppoly(xin,yin,xout);
ytrue= 1./(1+xout.^2);
plot(xout,ytrue-yout)
