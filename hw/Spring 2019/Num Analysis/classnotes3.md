midterm curve +12 points

## Least Square Data Fitting
Given a set of points in $\mathbb R^2$:

$$S=\{(x_i,y_i)\}_{i=1}^n$$

we want a function $f$ such that $f(x_i)\approx y_i$. With such a function, the error at the $i$th point is:

$$\epsilon_i=f(x_i)-y_i$$

The **root mean square error** of all points is

$$E=\sqrt{\frac{1}{n}\sum_{i=1}^n\epsilon_i^2}=\sqrt{\frac{1}{n}\sum_{i=1}^n(f(x_i)-y_i)^2}$$

The least square data fitting problem, then, is to find a function $f$ that minimizes that error $E$. Also, note that minimizing the above expression is equivalent to minimizing:

$$E^2n=\sum_{i=1}^n\epsilon_i^2=\sum_{i=1}^n(f(x_i)-y_i)^2$$

#### Linear Least Square
Consider $f$ of the form:

$$f(x)=mx+b$$

Now our task is to find $m$ and $b$ such that we minimize the following function $G$:

$$G(m,b)=\sum_{i=1}^n(mx_i+b-y_i)^2$$

We do this by setting $G$'s partial derivatives to $0$:

$$\frac{\partial G}{\partial m}=\sum_{i=1}^n2x_i(mx_i+b-y_i)=0$$

$$\begin{align*}
\frac{\partial G}{\partial b}&=\sum_{i=1}^n2\left(mx_i+b-y_i\right)=0\\
&=\sum_{i=1}^nmx_i+\sum_{i=1}^nb-\sum_{i=1}^ny_i\\
&=m\sum_{i=1}^nx_i+nb-\sum_{i=1}^ny_i\\
&\rightarrow m\sum_{i=1}^nx_i+nb=\sum_{i=1}^ny_i\\
\end{align*}$$

blah blah

#### More General LS Problem
Consider a linear combination a set of basis functions $\phi_i(x)$:

$$f(x)=a_1\phi_1(x)+a_2\phi_2(x)+\cdots$$

For example polynomials would use the basis $\{1,x,x^2,\cdots\}$. This results in a function $G$ which we must minimize:

$$G(a_1,a_2,\cdots)=\sum_{i=1}^n(a_1\phi_1(x_i)+a_2\phi_2(x_i)+\cdots-y_i)^2$$

To do this we set $G$'s partial derivatives to $0$:

$$\frac{\partial G}{\partial a_j}=2\sum_{i=1}^n(a_1\phi_1(x_i)+a_2\phi_2(x_i)+\cdots-y_i)=0$$

$$A\vec a=\vec b$$

## Polynomial Interpolation
Given a set of points $(x_i,y_i)$ give a polynomial $p(x)$ that fits all these points exactly.

It can be used to approximate a function $f$. If we have a set of known points of $f$ we can find an interpolating polynomial and then plug in our desired value.

#### Linear Interpolation
Given two points $(x_0,y_0), (x_1,y_1)$ the linear polynomial passing through them is:

$$p(x)=\frac{(x_1-x)y_0+(x-x_0)y_1}{x_1-x_0}$$

*Plug $x_0,x_1$ in to see why this works.*

#### Quadratic Interpolation
Given three points $(x_0,y_0)_ {i=0}^2$ the quadratic polynomial passing through them is:

$$p(x)=y_0L_0(x)+y_1L_1(x)+y_2L_2(x)$$

Where

$$L_0(x)=\frac{(x-x_1)(x-x_2)}{(x_0-x_1)(x_0-x_2)}$$

*Notice that plugging in $x_1,x_2$ return $0$, while $x_0$ returns $1$*

And the same for $L_1$ and $L_2$:

$$L_1(x)=\frac{(x-x_0)(x-x_2)}{(x_1-x_0)(x_1-x_2)}$$
$$L_2(x)=\frac{(x-x_0)(x-x_1)}{(x_2-x_0)(x_2-x_1)}$$

We call $L_1,L_2,L_3$ the quadratic Lagrange polynomials. They have the following property:

$$L_i(x_j)=\begin{cases}
1,\ \ \ \ \  i=j\\
0,\ \ \ \ \  i\not=j
\end{cases}$$

From here it is simple to see why we defined the quadratic interpolation as we did.

#### General Interpolation
In general, the $n$th degree polynomial interpolation given $n+1$ points is:

$$p(x)=y_0L_0(x)+\cdots+y_nL_n(x)$$

Where $L_i$ is the $n$th degree Lagrange polynomial:

$$L_0(x)=\frac{(x-x_1)(x-x_2)\cdots(x-x_n)}{(x_0-x_1)(x_0-x_2)\cdots(x_0-x_n)}$$

and in general:

$$L_i(x)=\prod_{j=0\\j\not=i}^n\frac{x-x_j}{x_i-x_j}$$

#### Complexity
2(n-2) additions, 2(n-3) multiplications per Lagrange polynomial, this times n-1 polynomials, n-1 multiplications of $y_i$ and $n-2$ additions of these terms.

4n^2-12n+7=O(n^2), not horrible I suppose.

Doing it by simply solving an $n$th degree polynomial via a linear system as opposed to using Lagrange polynomials is an $O(n^3)$ solution.

## Newton Interpolation
#### Linear Interpolation
Given two points, the unique line that connects them is:

$$p(x)=y_1+\frac{y_2-y_1}{x_2-x_1}(x-x_1)$$

#### Divided Difference
Given two points $(x_1,y_1),(x_2,y_2)$, where $f(x_i)=y+i$, their divided difference is:

$$f[x_1,x_2]=\frac{y_1-y_2}{x_1-x_2}$$

So our linear interpolation becomes:

$$p(x)=y_1+f[x_1,x_2] (x-x_1)$$

The divided difference of three points is:

$$f[x_1,x_2,x_3]=\frac{f[x_1,x_2]-f[x_2,x_3]}{x_1-x_3}$$

So our interpolation polynomial is:

$$p(x)=y_1+f[x_1,x_2] (x-x_1)+f[x_1,x_2,x_3] (x-x_1)(x-x_2)$$

#### General Case
In general, given $n+1$ points the Newton polynomial is given by:

$$p(x)=\sum_{i=0}^n\left(f[x_1,\cdots,x_n]\prod_{j=0}^{i-1}(x-x_j)\right)$$

To solve for a divided difference, its useful to create a table of x,y,1st order, 2nd order, etc. values to use in the computation.

#### Implementation
1. Initialize an $n$-dim vector $d:=[y_1,y,_ 2,\cdots, y_n]$
2. Now we update the last element $d_n:=\frac{d_{n-1}-d_n}{x_{n-1}-x_n}$
3. We continue backwards, updating from $n$ to $2$ setting the $i$th entry equal to $d_i:=\frac{d_{i-1}-d_i}{x_{i-1}-x_i}$. This leaves us with the first order differences (except for the 1st element, which is the 0th order difference of the first element)
4. Now we compute the second order differences backwards from $n$ to $3$ using the same formula. And so on??

#### Psuedocode
```python
d:=(y_1,y,_2,..., y_n)
for i=2:n
  for j=n:(-1):i #-1 makes the increment go backwards.
    d_j:=(d[j-1]-d[j])/(x[j-i+1]-x[j])
```

Evaluating the polynomial naively gives an $O(n^2)$ running time. Rewriting it using Horner's method we have:

$$p(x)=d_1+\left(x+x_1\right)\left(d_2+\left(x-x_2\right)\left(d_3+\left(x-x_3\right)\left(\cdots d_n(x-x_{n-1})\right)\right)\right)$$

So we get:
```python
p=d[n]
p=((x-x[n-1])p+d[n-1])
p=((x-x[n-2])p+d[n-2])
...
p=((x-x[n-i])p+d[n-i])
```

## Interpolation Error

#### Error Estimate
Let $f:[a,b]\to\mathbb R$ with $n+1$ continuous derivatives and let $\{x_0,x_1,\cdots,x_n\}\in[a,b]$ be distinct nodes. We define $p(x)$ as the interpolating polynomial of those nodes. Then:

$$\operatorname{error}(x)=f(x)-p(x)=f^{(n+1)}(\zeta)\frac{(x-x_0)(x-x_1)\cdots(x-x_n)}{(n+1)!}$$

#### Example
Given $f(x)=e^x$ what is the error at $x=1/3$ and what is the max error over the interval:

$$\max_{0\le x\le1}|f(x)-p_1(x)|$$

*Our nodes are 0,1 the end points, linear interpolation.*

$$f(x)-p_1(x)=f''(\zeta)\frac{(x-0)(x-1)}{2!}$$
$$|f(1/3)-p_1(1/3)|=|f''(\zeta)|\left|\frac{(1/3)(2/3)}{2!}\right|$$

Since $f''(x)=e^x$ we find that $|f''(\zeta)|=|e^3|$

For the max we note that $|e^\zeta|\le|e^1|=e$ because it is an increasing function and our interval is from 0 to 1:

$$\begin{align*}
|f(x)-p_1(x)|&=|f''(\zeta)|\left|\frac{x(x-1)}{2!}\right|\\
&\le e\left|\frac{x(x-1)}{2!}\right|\\
\max_{0\le x\le1}|f(x)-p_1(x)|&\le\max_{0\le x\le1}\left|\frac{x(x-1)}{2!}\right|  
\end{align*}$$

Max of a quadratic is at its vertex and thus $x=1/2$ gives the max error.

#### Runge Problem
The Runge phenomenon is when the ends of a polynomial interpolation oscillates with greater intensity as the number of points increases. This happens in, for example, $\frac{1}{1+x^2}$.

A way to avoid this is to, instead of picking uniformly distributed nodes, to pick points that minimize the polynomial.

This is difficult to do in practice and so another way to avoid the Runge problem is to construct a piecewise polynomial interpolation.
