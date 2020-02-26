function itrapn = trap(FunFcn,a,b,n)
% This function produces an approximation to the integral of FunFcn on
% the interval [a,b] using the composite trapezoidal rule using n subintervals
% Funfcn is the name of the function to be evaluated.
% It is supplied as an m file.
% a is the left end point of the interval
% b is the right end point of the interval
% n is the number of subintervals to use
% The output is returned in itrapn
  n1 = n-1;
  h = (b-a)/n;
  itrapn = feval(FunFcn,a)/2 + feval(FunFcn,b)/2;
  for i = 1:n1
     itrapn = itrapn + feval(FunFcn,a + i*h);
  end
  itrapn = h*itrapn;
