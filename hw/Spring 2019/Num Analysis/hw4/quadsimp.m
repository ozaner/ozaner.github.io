function [value, nfinal, errfinal] = quadsimp(FunFcn,a,b,tol,ninit,maxn)
% This function produces an approximation to the integral of FunFcn on
% the interval [a,b] using the composite Simpson's rule and an
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
  trapold = trap(FunFcn,a,b,ninit);
  midold = mid(FunFcn,a,b,ninit);
  told = (trapold + 2*midold)/3;
% Next compute a sequence of approximations successively doubling
% the number of subintervals
  err=1;
  n = ninit;
while n <= maxn & err > tol
  midnew =  mid(FunFcn,a,b,2*n);
  trapnew = (trapold + midold)/2;
  tnew = (trapnew + 2*midnew)/3;
  err = abs(tnew-told);
  n= 2*n;
  midold=midnew;
  trapold = trapnew;
  told = tnew;
end
value = tnew;
nfinal = n;
errfinal = err;
