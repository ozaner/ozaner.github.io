%f = inline('[x(1)-x(1)^2-x(2)^2; x(2)-x(1)^2+x(2)^2]');
%format long
%s = NewtonMethod(f,[0.5 0.5],10e-14,10)

options = optimset('Display', 'iter');
x0 = [0.5,0.5];
[x,fval] = fsolve(@fccns,x0,options)