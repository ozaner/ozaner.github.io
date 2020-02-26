function imidn = mid(FunFcn,a,b,n)
% This function produces an approximation to the integral of FunFcn on
% the interval [a,b] using the composite midpoint rule using n subintervals
% Funfcn is the name of the function to be evaluated.
% It is supplied as an m file.
% a is the left end point of the interval
% b is the right end point of the interval
% n is the number of subintervals to use
% The output is returned in imidn
    imidn = 0;
    h = (b-a)/n;
    for i = 1:n
     imidn = imidn + feval(FunFcn,a + (i-.5)*h);
    end
    imidn = h*imidn;
