clear
clc
n = 8;
y(1:n)=1/sqrt(n);
y=y';
H=hilb(n);
b=H*y;
z=H\b;
x=y;

norm(x-z,inf)/norm(x,inf)
a=norm(H*z-b,inf)/norm(b,inf)
b=norm(H,inf)*norm(inv(H),inf)
a*b

%norm(x-z)/norm(x)
%a=norm(H*z-b)/norm(b)
%b=norm(H)*norm(inv(H))
%a*b