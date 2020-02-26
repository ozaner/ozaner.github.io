clear
clc
A = [6 4 4 1;4 6 1 4;4 1 6 4;1 4 4 6];
start = [1,0,0,0]';

lam = zeros(10,1);
dif = zeros(10,1);
rat = zeros(10,1);

count=1;
x=start;
while count ~= 11
    y=A*x;
    n=norm(x);
    x=y/n;
    [m,k] = max(x);
    x2=x/m;
    lam(count)=dot(A*x2,x2)/dot(x2,x2);
    if(count > 1)
        dif(count)=lam(count)-lam(count-1);
    end
    if(count > 2)
        rat(count)=dif(count)/dif(count-1);
    end
    count = count + 1;
end
format longE
lam
dif
rat

eig(A);