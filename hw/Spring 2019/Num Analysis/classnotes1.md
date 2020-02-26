#Num Analysis

## Order of magnitude
We use $O(n^\alpha)$ to denote a variable that grows at rate $\alpha$. For example:

$$x_n=O(n^3)\implies \lim_{n\to\infty} \frac{x_n}{n^3}=c\not=0$$

Ex: Let $A$ be an $n\times n$ matrix and $\vec v$ an $n$-dim vector. Find the order of complexity of the following matrix multiplication:

$$A\cdot\vec v=
\begin{bmatrix}
    a_{11}&\cdots &a_{1n}\\
    \vdots&\ddots &\vdots\\
    a_{n1}&\cdots &a_{nn}\\
\end{bmatrix}\begin{bmatrix}
    a_{1}\\
    \vdots\\
    a_{n}\\
\end{bmatrix}$$

Each row requires $n$ multiplications and $n-1$ additions. So the complexity of all $n$ rows means that the time complexity of $A\cdot\vec v$ is:

$$n\cdot(n+(n-1))=2n^2-n=O(n^2)$$

When the time complexity of an numerical algorithm is polynomial, we call its **order of magnitude** the degree of that polynomial. In  this case this algorithm has a second order of magnitude.

## Order of Convergence
The **order of convergence** of a numerical algorithm is the degree of its error term (which will be a polynomial). Below is an example.

## Finite Difference Method
Used to approximate the derivative of a function $f(x)$. Consider the definition of the derivative:

$$f'(x)=\lim_{h\to 0}\frac{f(x+h)-f(x)}{h}$$

So it would seem that by simply choosing a small value of $h$, called the *step size*, we can approximate the derivative of $f$ at some point $x_0$. We can either add, or subtract for negative, $h$ to attain the *forward difference*:

$$f'(x_0)\approx\frac{f(x_0+h)-f(x_0)}{h}$$

or the average of adding and subtracting the two, *the central difference*:

$$f'(x_0)\approx\frac{f(x_0+h)-f(x_0-h)}{2h}$$

Which method is better? Assuming $f(x)$ is smooth, we can write the McLaurin series of both $f(x+h)$ and $f(x-h)$:

$$f(x+h)=f(x)+f'(x)h+\frac{f''(x)}{2!}h^2+\cdots$$
$$f(x-h)=f(x)-f'(x)h+\frac{f''(x)}{2!}h^2+\cdots$$

Now we see that the first method equals:

$$\frac{f(x+h)-f(x)}{h}=\underbrace{f'(x)}_{\text{derivative}}+\underbrace{\frac{f''(x)}{2!}h+\frac{f'''(x)}{3!}h^2+\cdots}_{\text{error(h)}}$$

As we can see the complexity of the error is linear in $h$:

$$\text{error(h)}\in O(h)$$

We call this *first order convergence*. However, when we compute the error of the central difference:

$$\frac{f(x+h)-f(x-h)}{2h}=\underbrace{f'(x)}_{\text{derivative}}+\underbrace{\frac{f'''(x)}{3!}h^2+\frac{f^{(5)}(x)}{5!}h^4+\cdots}_{\text{error(h)}}$$

In this case, the complexity of the error is quadratic in $h$:

$$\text{error(h)}\in O(h^2)$$

We call this a *second order convergence*. We can conclude then that with the same step-size $h$, the central difference method gives a better approximation than that of the forward difference, despite both methods having the same runtime complexity.

## Floating Point Standard
The floating point representation of a number $x\in\mathbb R$ has 3 parts:
- The **sign bit** $\sigma=\operatorname{sign}(x)$. The bit's value is given by $[x\lt 0]$.
- The **mantissa** ${(a_1a_2a_3a_4\cdots a_i)}_{2}$. This is the binary form of $|x|$ up to $i$ bits scaled such that it is between $0$ and $1$.
- The **exponential** $e=\log_2x$. This is how many binary places $x$ was scaled by to get the mantissa.

This means the formula for a floating point number with $n$ bits of precision is:

$$\operatorname{fl}(x)=\sigma\cdot(.a_1a_2a_3\cdots a_n)_ 2\cdot 2^e$$

#### Error
This approximation $\bar x$ introduces error in our representation of $x$. Recall that the absolute error is given by:

$$\text{absolute error}=x - \bar x$$

And the relative error is given by:

$$\text{relative error}=\frac{x - \bar x}{x}=\epsilon$$

Using this, we can bound the error introduced by the floating point standard:

$$\begin{align*}
\epsilon=\frac{x-\operatorname{fl}(x)}{x}&=\frac{\sigma\cdot(.000\cdots a_{n+1}a_{n+2}\cdots)_2\cdot 2^e}{\sigma\cdot(.a_1a_2a_3\cdots)_ 2\cdot 2^e}\\
&=\frac{(.000\cdots a_{n+1}a_{n+2}\cdots)_2 }{(.a_1a_2a_3\cdots)_ 2}
\end{align*}$$

*Note that the true binary representation of $x$ is an infinite bitstring.*

We can bound this error by considering $a_n$ to be equal to $1$ and setting the rest of the bits to $0$:

$$(.000\cdots a_{n+1}a_{n+2}\cdots)_2\le(.000\cdots 100\cdots)_ 2=2^{-n-1}$$

This gives us:

$$\epsilon=\frac{2^{-n-1}}{(.a_1a_2a_3\cdots)_ 2}\ge 2^{-n-1}$$

#### Double Prescision
Scientific computing mostly uses the $64$-bit double precision float which allocates $n=52$ bits to the mantissa. Thus, the minimum error of this scheme, or its **unit roundoff**, is:
$$\epsilon=\frac{x-\operatorname{fl}(x)}{x}\ge2^{-53}\approx 10^{-16}$$

## Root Finding w/ MVT
### Mean Value Theorem
Recall that, given some continuous function $f:\mathbb R\to\mathbb R$, the mean value theorem says that $f$ must have a root in the interval $[a,b]$ if $f(a)>0$ and $f(b)<0$ or vice versa. In other words:

$$f(a)\cdot f(b)<0\implies(\exists x_0\in[a,b])\ f(x_0)=0$$

### Bisection Method
The bisection method uses the MVT to approach the roots of a function. Given a function $f(x)$:

1. Find two points $a$ and $b$, such that $f(a)\cdot f(b)<0$.
2. Let $c:=\frac{a+b}{2}$
3. if $\ \ \ \ \ \ \ f(c)\cdot f(a)<0$, then set $b:=c$,<br>
  else if $f(c)\cdot f(b)<0$, then set $a:=c$,<br>
  else if $f(c)\cdot f(b)=0$, then return $c$
4. Repeat step 2 until: $|a-b|<\text{tol}$.

*Where $\text{tol}$ is some prescribed tolerance like $10^{-4}$ i.e. 4 decimal digits of accuracy.*

For example, computing $\sqrt a$, where $a>0$, can be equivalently stated as finding the positive root of $f(x)=x^2-a$.

#### Error
Let $(a_n,b_n)$ be the $n$th interval, let $x_n=\frac{a_n+b_n}{2}$ be the $n$th guess, and let $p$ be the true solution of $f(x)=0$.

The error at step $n$ is always at the most $\frac{1}{2}$ the intervals size. Working backwards to each iteration we find:

$$\begin{align*}
|p-x_n|&\le\frac{1}{2}|a_0-b_0|\\
&\le\frac{1}{4}|a_1-b_1|\\
&\vdots\\
&\le\frac{1}{2^{n+1}}|a_n-b_n|\\
\end{align*}$$

For example, the number of iterations to get within a tolerance of $2^{-53}$ is determined by how far the initial bounds are form each other:

$$\underbrace{|p-x_n|}_{\text{error}}\le\underbrace{\frac{1}{2^{n+1}}|a_n-b_n|=2^{-53}}_{\text{tolerance}}$$

### Newton's Method
Given a differentiable function $f:\mathbb R\to\mathbb R$ and an initial guess $x_0$, we can perform the following algorithm to approximate a root:

1. do $x_n:=x_{n-1}-\frac{f'(x_{n-1})}{f(x_{n-1})}$
2. while $|x_{n}-x_{n-1}|<\text{tol}$
3. return $x_n$

*Of course, when actually implementing this we only need 2 variables not $n$.*

The algorithm uses a sequence of tangent lines that get arbitrarily closer to the true root. As such the tolerance in this case refers to how little change has happened between the current and last iterations.

Note that under certain conditions, this method may not always converge for certain functions, intervals, etc.

#### Error
The error at a step $n$ is:

$$|p-x_n|\le c|p-x_n|^2$$

Where the constant $c$ depends on

$$\frac{f''(\theta_n)}{2f'(x_n)},\ \theta_n\in(p,x_n)$$

#### Order of Convergence
When newton's method works right, it has a quadratic convergence.

### Secant Method
Given two initial points $x_0$ and $x_1$, find their secant line, and then find its x-intercept $x_2$. Repeat process with previous two points up to desired accuracy. The algorithm:

1. do $x_n:=x_{n-1}-\frac{x_{n-1}-x_{n-2}}{f(x_{n-1})-f(x_{n-2})}f(x_{n-1})$
2. while $|x_{n}-x_{n-1}|<\text{tol}$
3. return $x_n$

#### Error
The error at step $n$ can be shown to be bounded by:

$$p-x_n\le c|p-x_{n-1}|^r,\ \ \ r=\frac{\sqrt 5+1}{2}\approx 1.62$$

Where the constant $c$ depends on:

$$\left|\frac{f''(\theta_n)}{2f'(x_n)}\right|,\ \theta_n\in(p,x_{n-1})$$

#### Order of Convergence
Recall that the error converges in order $r$ means:

$$|x_{n-1}-p|\le c|x_n-p|^r$$

## Fixed Point Iteration
Recall that a fixed point of a function $f$ is one which satisfies:

$$f(x)=x$$

Consider $x_{n+1}=f(x_n)$. Note that finding a fixed point of $f(x)$ is equivalent to finding a root of $f(x)-x$. Newton's method can be viewed as a fixed point iteration.

#### Fixed Point Theorem
For sequence $x_{n+1}=f(x_n)$ for which $f:I=\to\mathbb R$ satisfies the following:
- $f(x)$ is continuous on $I=[a,b]$
- $(\forall x\in I)\ a\le f(x)\le b$
- $(\forall x\in I)\ |f'(x)|<1$

Then $G(x)$ has a unique fixed point $s$. Moreover, the sequence will approach it:

$$\lim_{n\to\infty}x_n=\lim_{n\to\infty}f(x_n)=s$$

#### Example
Root of $x^2+x+6=0\to x=\frac{6}{x^2}\to x_{n+1}=\frac{6}{x_n^2}$. If this recurrence relation satisfies the fixed point theorem then it will converge. If not then it won't.

#### Order of Convergence
If $x_n\to s$ and:
- $f(s)=s$
- $f'(s)=f''(s)=\cdots=f^{(p-1)}(s)=0$
- $f^{(p)}(s)\not= 0$

then the Taylor series tells us:

$$|x_{n+1}-s|=\frac{f^{(p)}(s)}{p!}(x_n-s)^p+O(|x_n-s|^{p+1})$$

or in other words:

$$|x_{n+1}-s|\le \alpha|x_n-s|^p$$

And so the function has an order $p$ convergence. That is, the order of convergence is the first $p$ such that $f^{(p)}(s)\not=0$.
