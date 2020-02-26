% Bisection Method
format long
a = 1; % left end point of interval containing the root
b = 4; % right end point of interval containing the root
tol = .001; % Error tolerance
N = 0; % the current iteration number
Nmax = 50; % maximum number of iterations

f = @(x) x^3+x-4;

fa = f(a);
fb = f(b);
while 1
    N = N+1;
    m =(a+b)/2; % new interval bound
    fm = f(m);
    [N,m] % Print iteration
    
    % Bail once tolerance or iteration limit reached
    if N ~=1
        if (abs(m - prev) <= tol) || (N >= Nmax)
            break;
        end
    end
    
    % New bounds
    if fa*fm <= 0
        b = m;
        fb = fm;
    else
        a = m;
        fa = fm;
    end
    
    prev = m; % Remeber previous for tolerance
end
