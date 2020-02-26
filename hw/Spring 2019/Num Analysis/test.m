%% Use Matlab as a calculator
% To supress output use ;

1+1;
1-2;

3^2; % square
sin(pi/2); % trig functions
exp(1); % exponential func
log(exp(1)^2); % natural log

% Clear Command Window
clc
%% Vectors and Matrix
%%
M = [1,2;3,4]; %, seperate elements ; seperate rows
% M2 = [1,2;3]; % Matrix dim must match
u = [1,2]; % Row vector
v = [1;2]; % Column vector

M*v; % Matrix multiplication
u*v; % Dot product

u'; % Matrix transpose

[1]==1; % 1x1 matrices are scalars

w1 = [3,5];
w2 = [4,2];
w1 .* w2; % element-wise multiplication

size(M); % Number of rows and columns (as a matrix)
length(w1); % length of vector/rows of matrix
%% Define a function
% One way is to make a new script (file) named that function

% Another is to use a function handle
sigma = @(x) 1./(1+exp(-x)); %./ allows for element-wise evaluation
sigma(0); % Now we can call function
%% Plot
%%
x = [0,1,2,3]; %x-coords of points
y= [0,1,0,-1]; %y-coords of points
plot(x,y); % plot peicewise linear graph of points

% Plotting a function
% First we discretize the interval, say [-10,10], into 20 subintervals
x = linspace(-10,10,21); % Vector of 21 points (20 intervals)

% Evaluate function on all the points
y = sigma(x); % evaluates function

plot(x,y);
legend('sigma function');