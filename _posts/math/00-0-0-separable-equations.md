---
header:
  overlay_image: /assets/images/math/diff-eqs-splash2.gif
title: Separable Differential Equations
date: 2019-07-09
excerpt: "An overview of separable differential equations"
categories:
  - posts
tags: 
  - math
  - analysis
  - differential-equations
---

## Definition
A first order differential equation is called **separable** if the derivative of $y$ can be expressed as the product of a function dependent on $t$ and function dependent on $y$:

$$\frac{dy}{dt}=f(t,y)=g(t)h(y)$$

*where both $g(t)$ and $h(y)$ are continuous functions.*

<!--more-->

### Autonomous Equations
Note that in the special case that $g(t)=1$, the separable equation is independent of $t$ and is thus a first order [**autonomous equation**](\autonomous-equations).

<!-- Autonomous differential equations are ones that are independent of $t$. Instead they are dependent only on $y$ and, for higher order equations, $y$'s derivatives. -->

## Solutions by Integration
The reason differential equations of the above form are interesting is because they are equivalent to the following (hopefully simple) integral equation:

$$\int\frac{1}{h(y)} \,dy=\int g(t) \,dt$$

which, when computed, will yield a family of *implicit solutions* to the differential equation (which can possibly be solved for a family of *explicit solutions*). We call this technique for solving differential equations the **separation of variables**.

<details class="bordered">
<summary><strong>Proof</strong></summary>

$$\begin{align*}
\frac{dy}{dt}&=g(t)h(y)\\
\frac{1}{h(y)}\frac{dy}{dt}&=g(t)&\text{(algebra)}\\
\int\frac{1}{h(y)}\frac{dy}{dt}\,dt&=\int g(t)\,dt&\text{(integrate with $dt$)}\\
\int\frac{1}{h(y)}\,dy&=\int g(t)\,dt&\text{(algebra)}
\end{align*}$$

<!-- <i>Note that for this proof we used non-standard analysis, which uses the hyperreal numbers to define derivatives and integrals. In particular, since integration is just a infinite summation and $\frac{dy}{dt}$ is just the ratio of infinitesimals, our cancellation of $dt$ in the last step was justified.</i> -->
<i>In the last step we multiply $\frac{dy}{dt}$ by $dt$ to get $dy$. This can be more directly justified using non-standard analysis where infinitesimal quantities are meaningful.</i>
</details>

## Equilibrium Solutions
Note that the second step of our proof (where we divided both sides by $h(y)$) is not valid for constant $y_0$ such that $h(y_0)=0$ as division by zero is undefined. As such, we must take special care in checking the roots of $h(y)$. In particular, we note that these roots are actually solutions to the separable equation since the derivative of a constant is $0$:

$$\frac{d}{dt}y_0=0\,\,\,\,\,\,\,\,\,\,\,\,\,\frac{dy}{dt}=g(t)h(y_0)=0$$

*For any constant $y_0$ such that $h(y_0)=0$.*

These constant solutions for $y$, called **equilibrium solutions**, aren't present in the solution to the integral equation above. And so the *entire* solution set of a separable equation consists of the roots of $h(y)$ as well as the solutions of the integral equation.

<!-- The solutions obtained by the separation of variables aren't the only ones. All the roots of $h(y)$ are also solutions to the separable differential equation. This is plain to see as for any constant $y_0$ such that $h(y_0)=0$ we have:

$$\frac{d}{dt}y_0=0\,\,\,\,\,\,\,\,\,\,\,\,\,\frac{dy}{dt}=g(t)h(y_0)=0$$

The reason these constant solutions for $y$, called **equilibrium solutions**, must be accounted for separately is because the left hand side of the integral equation:

$$\int\frac{1}{h(y)}\,dy$$

is undefined for $y$ such that $h(y)=0$ since division by zero is undefined.

As such, the *entire* solution set of a separable equation consists of both the roots of $h(y)$ as well as the solutions of the integral equation. -->