function [yout, cof] = interppoly(xin,yin,xout)
% This function first determines the vector of coefficients cof
% in the Newton form of the interpolating polynomial of degree 
% less than or equal to n-1, i.e., the polynomial p(x) of degree
% less than or equal to n-1 of the form
% p(x) = cof(1) + cof(2)(x-xin(1)) + ... + cof(n)(x-xin(1))...(x-xin(n-1))
% satisfying p(xin(i)) = yin(i), i=1:n,
% where the inputs xin and yin are vectors of length n.
% The function then determines the values
% yout = p(xout), where xout is a vector of length m.
n = length(xin)
for k=1:n-1
yin(k+1:n) = (yin(k+1:n)-yin(k)) ./ (xin(k+1:n) - xin(k));
end
cof = yin;
yout = cof(n)*ones(1, length(xout));  
% ones(l,m) returns an l-by-m matrix of 1s.
for k=n-1:-1:1
yout = (xout-xin(k)).*yout + cof(k);
end
