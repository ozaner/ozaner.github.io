function [s J] = NewtonMethod(f,p0,tol,MaxIter)
format long
x = sym('x'); y = sym('y'); 
F = f([x,y]);
% Compute the Jacobian matrix symbolically
J = jacobian(F);
invJ = inv(J);
s = zeros(MaxIter,2);
s(1,:) = p0;
dsnorm = inf;
iter = 1;

while dsnorm>tol && iter<MaxIter
    ds = -subs(invJ,[x y],s(iter,:))*f(s(iter,:));
    s(iter+1,:) = s(iter,:) + ds';
    dsnorm = norm(ds,inf);
    iter = iter+1;
end
s = s(1:iter,:);

end