clear
x0 = 0;
y0 = 0;
xfinal = 5.9;
h = 0.1;
n = (xfinal - x0)/h;
n = round(n);
f = @(x,y) 1 - 8*x*y;
x = linspace(x0,xfinal,n+1);
y = zeros(1,n+1);
y(1) = y0;
for i = 1:n
y(i+1) = y(i) + h*f(x(i), y(i));
end
plot(x,y)
format long
[x(end),y(end)]
grid on % Use this statement to see the values more clearly