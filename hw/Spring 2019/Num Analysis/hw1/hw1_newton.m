% Newton's Method
format long
prev = 1; % Initial guess
tol = .001; % Error tolerance
N = 0; % the current iteration number
Nmax = 50; % maximum number of iterations

f = @(x) x^3+x-4;
df = @(x) 3*x^2+1;

while 1
    N = N+1;
    x = prev - f(prev)/df(prev); % Next guess
    [N, x] % Print iteration
    
    % Bail once tolerance or iteration limit reached
    if (abs(x - prev) <= tol) || (N >= Nmax)
        break;
    end
    
    prev = x;
end

