# Numerical Integration
Given a function $f:[a,b]\to\mathbb R$, we want to find the area underneath it's graph. This is given by the integral of the function over that interval:

$$\int_a^bf(x)\ dx$$

In calculus we usually find the antiderivative of $f$, call it $F$, and then evaluate it as the interval points. This is equivalent to evaluating the integral:

$$\int_a^bf(x)\ dx=F(x)\Big|_ a^b=F(b)-F(a)$$

However, this is not always possible. Whether it be because it is computationally expensive, or an antiderivative does not exist/isn't representable via elementary functions, e.g. $f(x)=e^{x^2}$. We can get around this problem by using numerical integration methods.

## Trapezoid Rule
We essentially integrate the piecewise linear interpolation of the function $f$, given n+1 nodes $(x_i,y_i)$, where $x_0=a$ and $x_n=b$. The integral of each piece of the interpolation is a trapezoid with area equal to:

$$\frac{(y_i+y_{i+1})(x_{i+1}-x_i)}{2}$$

The entire integral over the piecewise linear interpolation is simply the sum of each piece's integral.

$$\int_a^bf(x)\approx\sum_{i=0}^{n-1}\frac{(y_i+y_{i+1})(x_{i+1}-x_i)}{2}$$

Note that the interval $[a,b]$ has been divided into $n$ subintervals.

#### Lagrange Polynomial derivation
Looking at it another way, we have the following linear interpolation in Lagrange form for the $i$th interpolating line:

$$p_i(x)=f(x_i)\frac{x-x_{i+1}}{x_i-x_{i+1}}+f(x_{i+1})\frac{x-x_i}{x_{i+1}-x_i}$$

integrating it and simplifying, we arrive at the same answer.

#### Equidistant Nodes
When the nodes are equidistant, we can simplify the formula further. Note that $\frac{b-a}{n}=\Delta x=x_{i+1}-x_i$ for some constant $\Delta x$, meaning:

$$\begin{align*}
\int_a^bf(x)&\approx \Delta x\sum_{i=0}^{n-1}\frac{y_i+y_{i+1}}{2}\\
&=\Delta x\left(\frac{y_0+y_{1}}{2}+\frac{y_1+y_{2}}{2}+\cdots+\frac{y_{n-1}+y_{n}}{2}\right)\\
&=\Delta x\left(\frac{y_0+y_n}{2}+y_1+y_2+\cdots+y_{n-1}\right)\\
&=\Delta x\left(\frac{y_0+y_n}{2}\right)\sum_{i=1}^{n-1} y_i
\end{align*}$$

#### Error
The error of the trapezoid method given equal intervals is, assuming 2 continuous derivatives over $[a,b]$:

$$\text{error}_n=-\frac{(b-a)^3}{12n^2}f''(\xi)=-\frac{(\Delta x)^2(b-a)}{12}f''(\xi)=-\frac{(\Delta x)^3n}{12}f''(\xi)$$

*Where $\xi\in[a,b]$.*

An asymptotic formulation is given by:

$$\text{error}_n = -\frac{(\Delta x)^2(b-a)}{12} \big[ f'(x_n)-f'(x_0) \big] + O((\Delta x)^{3})$$

The maximum magnitude of the error is given by:

$$|\text{max error}_n|=\frac{(\Delta x)^2(b-a)}{12}\max_{a\le\xi\le b}|f''(\xi)|$$

## Simpson's Rule
Simpson's rule uses a piecewise quadratic interpolation to approximate the function rather than a linear one. We then can easily integrate that quadratic function like so:

$$\int_a^bf(x)\ dx\approx \sum_{i=0}^{n-1}\frac{x_{i+2}-x_i}{x_n}(y_i+4y_{i+1}+y_{i+2})$$

#### Equidistant Nodes
When the nodes are equidistant, we can simplify the formula further. Note that $\frac{b-a}{n}=\Delta x=x_{i+1}-x_i$ for some constant $\Delta x$, meaning:

h/6(f(x_0)+4f(x_1/2)+2f(x_1)+4f(x_3/2)...+f(x_n))

#### Error
The error of Simpson's rule given equal intervals is, assuming 4 continous derivatives over $[a,b]$:

$$\text{error}_n=-\frac{(b-a)^4}{180n^2}f^{(4)}(\xi)=-\frac{(\Delta x)^3(b-a)}{180}f^{(4)}(\xi)=-\frac{(\Delta x)^4n}{180}f^{(4)}(\xi)$$

*Where $\xi\in[a,b]$.*

An asymptotic formulation is given by:

$$\text{error}_n = -\frac{(\Delta x)^4}{180} \big[ f'''(b)-f'''(a) \big] + O((\Delta x)^{6})$$

The maximum magnitude of the error is given by:

$$|\text{max error}_n|=\frac{(\Delta x)^4}{180}\max_{a\le\xi\le b}|f^{(4)}(\xi)|$$

#### Richardson Extrapolation
If $f'''(a),f'''(b)$ are unknown, we can use Richardson extrapolation. Consider the following subtraction of the error for $n$ intervals, and $2n$ intervals times $2^4$:

$$\text{error}_n-2^4(\text{error}_{2n})\implies \text{error}_n=16(\text{error}_{2n})+O\left(\frac{3}{4}(\Delta x)^6\right)$$

We define the Richardson method as:

$$R_{2n}=\frac{16S_{2n}-S-n}{16-1}$$
