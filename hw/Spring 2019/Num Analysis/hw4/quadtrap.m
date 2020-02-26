function [value, nfinal, errfinal] = quadtrap(FunFcn,a,b,tol,ninit,maxn)
% This function produces an approximation to the integral of FunFcn on
% the interval [a,b] using the composite trapezoidal rule and an
% interval doubling stategy
% Funfcn is the name of the function to be evaluated.
% It is supplied as an m file.
% a is the left end point of the interval
% b is the right end point of the interval
% tol is the absolute error tolerance
% ninit is the initial number of subintervals used
% maxn is the maximum number of subintervals allowed
% value is the final value of the integral returned
% nfinal is the final number of subintervals used
% errfinal is the error between the last two approximations
%
% Compute the initial approximation `told` to the integral
  told = trap(FunFcn,a,b,ninit);
% Next compute a sequence of approximations successively doubling
% the number of subintervals
  err=1;
  n = ninit;
while n <= maxn & err > tol
  tnew = (told + mid(FunFcn,a,b,n))/2;
  err = abs(tnew-told);
  n= 2*n;
  told = tnew;
end
value = tnew;
nfinal = n;
errfinal = err;
