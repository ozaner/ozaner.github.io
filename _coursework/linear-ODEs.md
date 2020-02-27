---
header:
  overlay_image: /assets/images/math/diff-eqs-splash2.gif
title: Linear ODEs
date: 2019-10-15
excerpt: "Notes on the properties of linear ODEs and techniques for solving them."
permalink: /linear-ODEs/
redirect_from:
  - /linear-differential-equations/
categories:
  - posts
tags:
    - math
    - analysis
    - differential-equations
---
<!-- original date: 2018-05-28 -->

## Definition
An $n$th order **linear differential equation (LDE)** is an ODE[^f1] that can be expressed as a linear combination of the first $n$ derivatives of some function $y$ and differentiable functions $a_i(t)$:
$\newcommand{\der}[2][t]{\frac{d#2}{d#1}}\newcommand{\dern}[3][t]{\frac{d^{#3}#2}{d#1^{#3}}}$

$$a_0(t)y+a_1(t)\der y+a_2(t)\dern y2+\cdots+a_n(t)\dern yn=b(t)$$

Note that, since the quotient of differentiable functions is differentiable, we can express any such equation in explicit form:

$$\dern yn=a_{n-1}(t)\dern y{n-1}+\cdots+a_2(t)\dern y2+a_1(t)\der y+a_0(t)y+b(t)$$

## Homogeneity
When $b(x)=0$, the linear differential equation is dubbed **homogeneous**. Further, every LDE has an **associated homogenous equation** found by setting $b(x)=0$.

Homogenous equations are an important subclass of LDEs as they are both easier to solve and, as we'll see below, are used in deriving solutions to non-homogenous LDEs.

### Superposition of Solutions
Homogenous LDE's have the unique property that any linear combination, aka superposition, of its solutions is also a solution. That is to say, for any $k$ solutions to a homogenous LDE $y_i(t)$ and constants $c_i\in\mathbb R$ (or any field like $\mathbb C$) the following is also a solution:

$$y(x)=c_1y_1(x)+c_2y_2(x)+\cdots+c_ky_k(x)$$

We call this property **linearity**, or the **superposition principle**, and it immediately implies that the solution set $S$ to a homogenous differential equation forms a vector space $(S,+,\cdot)$ under function addition and scalar multiplication. As it turns out, the dimension of this vector space is equal to the order of the LDE.

## Extended Linearity
A useful fact, one that allows us to solve a wide variety of non-homogenous LDE's, is that the general solution $y(t)$ to any LDE can be written as:

$$y(t)=y_p(t)+y_c(t)$$

Where $y_p(t)$ is any particular solution to the LDE and $y_c(t)$ is the general solution of its associated homogenous equation.

## First Order LDEs
### Homogeneous Case
A first order homogenous LDE is one of the following form:

$$\der y=f(t)y$$

This is a [**separable equation**](/separable-equations) and thus its solution set, after some manipulation, is given by the following integral equation:

$$y(t)=Ce^{\int f(t)\mathop{dt}}$$

*Where $C$ is some arbitrary constant.*

<details><summary><strong>Proof</strong></summary>
The ODE $\der y=f(t)y$ is separable, and so its equilibrium solutions are given by the roots of $y$, which is just $y=0$. The non-equilibrium solutions are given by:

$$\begin{align*}
\der y&=f(t)y&\text{(homogenous LDE)}\\
\int\frac{dy}{y}&=\int f(t)\mathop{dt}&\text{(separable ODE)}\\
\ln y&=\int f(t)\mathop{dt} + C_1&\text{(integration)}\\
y&=e^{\int f(t)\mathop{dt} + C_1}&\text{(exponentiation)}\\
y&=C_2e^{\int f(t)\mathop{dt}}&\\
\end{align*}$$

Notice that $C_2$ is a strictly positive constant over the reals (and non-zero over the complex numbers), but when we let it equal $0$ we arrive at the sole equilibrium solution. As such, the general solution to the LDE is the following indexed by an arbitrary constant $C$:

$$\boxed{y=Ce^{\int f(t)\mathop{dt}}}$$
</details>

<details><summary><strong>Example: Discharging an RL Circuit</strong></summary>
A real world example of a homogenous first order LDE with constant coefficients can be found in considering the current in an RL circuit after it has been fully charged and the source of emf has been removed. The circuit will then  discharge as given by <b>Kirchhoff's loop law</b>:

$$-IR-L\dfrac{dI}{dt}=0$$

We can rearrange the first order homogeneous LDE above as so:

$$\der I = -\frac{R}{L}I$$

And so our general solution is simply:

$$\begin{align}
I(t)&=C_1e^{\int -R/L\mathop{dt}}\\
&=C_2e^{-Rt/L}
\end{align}$$

Recall that the RL circuit is initially fully charged, i.e $I(0)=\frac{\mathcal{E}}{R}$ (see charging example below). With this initial condition, we can solve for a particular $C_2$:

$$\begin{align}
\frac{\mathcal{E}}{R}&=C_2e^{-R(0)/L}\\
&=C_2e^0\\
&=C_2
\end{align}$$

Plugging this back into our general solution, we can conclude that the current $I(t)$ of a fully charged discharing RL circuit is given by:

$$\boxed{I(t)=\frac{\mathcal{E}}{R}e^{-Rt/L}}$$
</details>

<!-- The above equation is the **general solution** to any given first order homogeneous LDE. To arrive at a **particular solution**, that is solve for the constant $C$, one would need to be given an **initial condition** (i.e some pair $(x,y)$ on the function). -->

### General Case
A general first order LDE can be written as follows:

$$\der y+f(t)y=g(x)$$

The general solution of a first order LDE is given by:

$$y(t)=\frac{\int \mu(t)g(t)\mathop{dt}+C}{\mu(t)}=\frac{\int e^{\int f(t)\mathop{dt}}g(t)\mathop{dt}+C}{e^{\int f(t)\mathop{dt}}}$$

*Where $C$ is some arbitrary constant, and the **integrating factor** $\mu(t)=e^{\int f(t)\mathop{dt}}$.*

<details><summary><strong>Proof</strong></summary>
I'll do it later.
</details>

<details><summary><strong>Example: Charging an RL Circuit</strong></summary>
A real world example of a general first order LDE with constant coefficients can be found in considering the current of an RL circuit, which is given by Kirchhoff's loop law:

$$\mathcal{E}-IR-L\dfrac{dI}{dt}=0$$

<p><i>Where emf $\mathcal{E}$ and current $I$ are functions of time $t$, and resistance $R$ and inductance $L$ are constants.</i></p>

<p>Rearranging the terms and isolating, we can put it in a more familiar form:</p>

$$\dfrac{dI}{dt}+\frac{R}{L}I=\frac{\mathcal{E}}{L}$$

To solve this first order LDE, we first compute the integrating factor:

$$\mu(t)=e^{\int R/L\;dt}=Ce^{Rt/L}$$

Plugging this into our general formula and simplifying we find the following general solution:
$$\begin{align}
I(t)&=\frac{\int \mu(t)g(t)\mathop{dt}+C_1}{\mu(t)}\\
&=\frac{\frac{C\int e^{Rt/L}\mathcal{E}}{L}\mathop{dt}+C_1}{Ce^{Rt/L}}\\
&=\frac{\frac{\mathcal{E}}{L}\int e^{Rt/L}\mathop{dt}+C_2}{e^{Rt/L}}\\
&=\frac{\mathcal{E}e^{Rt/L}+C_3}{Re^{Rt/L}}
\end{align}$$

If we assume the current is intially 0, i.e. $I(0)=0$, we can solve for $C_3$:

$$\begin{align}
0&=\frac{\mathcal{E}e^{R(0)/L}+C_3}{Re^{R(0)/L}}\\
&=\frac{\mathcal{E}e^0+C_3}{Re^0}\\
&=\frac{\mathcal{E}+C_3}{R}\\
\rightarrow C_3&=-\mathcal{E}
\end{align}$$

Plugging this back into our general solution we finally arrive at our particular solution:

$$\begin{align}
I(t)&=\frac{\mathcal{E}e^{Rt/L}-\mathcal{E}}{Re^{Rt/L}}\\
&=\frac{\mathcal{E}}{R}\left(\frac{e^{Rt/L}-1}{e^{Rt/L}}\right)\\
&=\frac{\mathcal{E}}{R}\left(1-e^{-Rt/L}\right)
\end{align}$$

And so, we can conclude that the current $I(t)$ in an RL circuit as a function of time is given by:

$$\boxed{I(t)=\frac{\mathcal{E}}{R}\left(1-e^{-Rt/L}\right)}$$

As a side note, notice that as time increases the current asymptotes. In particular we have:

$$\begin{align}
\lim_{t\rightarrow\infty}{I(t)}&=\lim_{t\rightarrow\infty}\frac{\mathcal{E}}{R}\left(1-e^{-Rt/L}\right)\\
&=\lim_{t\rightarrow\infty}\frac{\mathcal{E}}{R}\left(1-\frac{1}{e^{Rt/L}}\right)\\
&=\frac{\mathcal{E}}{R}\left(1-0\right)\\
&=\frac{\mathcal{E}}{R}
\end{align}$$
</details>

<!-- ## Second Order Solution

### Homogeneous w/ Constant Coefficients

<details><summary><strong>Proof</strong></summary>
</details>

#### Real Roots
#### Complex Roots
#### Multiplicity of Roots -->

## $n$th order LDEs
Higher order LDE's are not solvable in general, and can only be solved in particular cases or with particular assumptions. Below are two such methods:

- **Constant coefficient LDEs** can be solved via the *method of undetermined coefficients*.
- **Constant coefficient homogenous LDE's** can be solved by solving their *characteristic polynomial*.

<!-- One such example are homogenous LDE's with constant coefficients, which can be solved in a manner similar to that of the second order case detailed in the previous section. -->

### Reduction to 1st Order System of LDEs
An common technique in solving $n$th order LDEs is to **reduce** them to a lower order system. Given an $n$th order LDE:

$$\dern yn=b(t)+a_0(t)y+a_1(t)\der y+a_2(t)\dern y2+\cdots+a_{n-1}(t)\dern y{n-1}$$

*Where $a_i$, $b$ and $y$ are functions of $t$.*

We can *reduce* it to a first order system of $n$ LDEs. To do this, we first define the following $n$ variables:

$$\begin{align*}
x_{n-1}&=\dern y{n-1}\\
x_{n-2}&=\dern y{n-2}\\
&\phantom{a}\vdots\\
x_{1}&=\der y\\
x_{0}&=y\\
\end{align*}$$

Recognizing that:

$$\dern y{i+1}=x_{i+1}=\der{x_i}$$

we can now rewrite the equation as the following system of $n$ LDEs:

$$\begin{cases}
\der{x_{n-1}}=a_{n-1}x_{(n-1)}+a_{n-2}x_{(n-2)}+\cdots+a_1x_1+a_0x_0+b\\
\der{x_{n-2}}=x_{n-1}\\
\,\,\,\vdots\\
\der{x_1}=x_2\\
\der{x_0}=x_1
\end{cases}$$

This system can be further represented via the following matrix equation:

$$\der{\mathbf{x}}=\mathbf{Ax}+\mathbf{b}$$

$$\underbrace{\begin{bmatrix}
\der{x_0}\\\der{x_1}\\\der{x_2}\\\vdots\\\der{x_{n-2}}\\\der{x_{n-1}}
\end{bmatrix}}_{\der{\mathbf{x}}}=

\underbrace{\begin{bmatrix}
0&1&0&0&\cdots&0\\0&0&1&0&\cdots&0\\0&0&0&1&\cdots&0\\\vdots&\vdots&\vdots&\vdots&\ddots&\vdots\\0&0&0&0&\cdots&1\\a_0&a_1&a_2&a_3&\cdots&a_{n-1}
\end{bmatrix}}_{\mathbf{A}}

\underbrace{\begin{bmatrix}
x_0\\x_1\\x_2\\\vdots\\x_{n-2}\\x_{n-1}
\end{bmatrix}}_{\mathbf{x}}+

\underbrace{\begin{bmatrix}
0\\0\\0\\\vdots\\0\\b
\end{bmatrix}}_{\mathbf{b}}$$

Note that we could always cut short our variable defining and thus be left with a higher order system. That said, first order systems are usually easier to deal with than higher orders.

<!-- footer -->

[^f1]: The above definition only refers to linear *ODEs*, with linear *PDEs* being linear combinations of a function's partial derivatives. This post deals only with the former.