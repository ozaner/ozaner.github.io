### Office Hours
John Ma, Hill Center 336, Thu 2:30-4:30
john.ma311@rutgers.edu
20% HW
20% per midterm (2 midterms)
40% final exam

Explicit vs. implicit equations, a differential equation is an equality with terms y(t) and its derivatives, nth Order.

A solution to a diff eq is a function y that satsifies the eq.

## Midterm 1 review

### Chapter 1
- Separable equations
- Euler's method
  - Given a step size $\Delta t$, and a differential equation $y'=f(t,y)$:
    $$t_{k+1}=t_k+\Delta t\\
    y{k+1}=y_k+\Delta t f(t_k,y_t)$$
- Phase Line
- Bifurcation Diagrams
- LDE's
  - Homogenous
  - Non-Homogenous (integrating factor)
  - Guessing (only for $y'+ay=b(t)$ for constant $a$)
    - If $b(t)=e^{kt}$ ($k\not=a$) then $y_p=Ce^{kt}$
    - If $b(t)=e^{at}$ then $y_p=Cte^{at}$
    - If $b(t)$ is a lienar combo of sin and cos then $y_p=\alpha\sin +\beta \cos$
    - If $b(t)$ is a polynomial, then $y_p$ is a polynomial of same degree
- Existence and Uniqueness (single ODE)
  - For an ODE $y'=f(t,y)$, if $f$ is continuous then solution exists
  - if $\frac{df}{dy}$ is continuous, then solution is unique.
  - And so if this is true for a given rectangle, a unique solution exists in that rectangle (over that interval of t).
  - *Comparison principle*: if you have two solutions to an ODE that satisfies the above, then
    $$y_1(t_0)<y_2(t_0)\implies(\forall t)y_1(t)<y_2(t)$$
    - i.e. solutions can't cross under picard-lindeloff

Picard iterative process? Newton's method? order of convergence?

### Chapter 2
- Independent System of ODEs, can just solve separately
- Partially decoupled system:
    $$x'=f(x)\\
    y'=g(x,y)$$
    - Need to solve $x$ first, then solve $y$ with $x$.
- 