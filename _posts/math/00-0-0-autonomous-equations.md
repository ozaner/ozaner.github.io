---
header:
  overlay_image: /assets/images/math/diff-eqs-splash2.gif
title: Autonomous Differential Equations
date: 2019-08-10
excerpt: "An overview of the class of differential equations that are invariant over time."
categories:
  - posts
tags: 
  - math
  - analysis
  - differential-equations
---

## Definition
An ODE is called **autonomous** if it is independent of it's independent variable $t$. This is to say an explicit $n$th order autonomous differential equation is of the following form:

$$\frac{d^ny}{dt}=f(y,y',y'',\cdots,y^{(n-1)})$$

ODEs that *are* dependent on $t$ are called **non-autonomous**, and a system of autonomous ODEs is called an **autonomous system**.

<!--more-->

### Solvability
Despite this simplifying restriction, only first order autonomous equations are solvable in general. Second order autonomous equations are reducible to first order ODEs and can be solved in specific cases. Autonomous equations of higher orders, however, are no more solvable than any other ODE.

## First Order Equations
### General Solution
Note that any explicit first order autonomous equation:

$$\frac{dy}{dt}=h(y)$$

is [**separable**](/separable-equations) and so their solution sets are given by their **equilibrium points**, i.e. the roots of $h(y)$, as well as the solutions to the following integral equation:

$$\int\frac{1}{h(y)}\,dy=t+C$$

*Where $C$ is the constant of integration.*

<div class="notice--info">
  Note that the following four sections only consider the real solutions to real valued autonomous ODEs.
</div>

<details><summary><h3 class="inline">Limiting Behavior of Solutions</h3></summary>
<p>Recall that a continuous function $f(y)$ can only change signs after passing through a zero. However, due to the Picard–Lindelöf theorem, no non-equilibrium solution $y$ to the ODE $f(y)$ can pass through an equilibrium point. This means their derivative can't pass through zero, and so the solution is always increasing/decreasing:</p>

<!-- And so, all non-equilibrium solutions are not only bound by their surrounding equilibrium solutions, but must also be monotone functions: -->

<!-- ![time](/assets/images/math/autonomous-equations/behavior1.png?style?=centerme){:width="550px"} -->

<img src="/assets/images/math/autonomous-equations/behavior1.png" alt="monotone" class="align-center">

<p>Further, all non-equilibrium solutions approach the nearest equilibrium point or, if none bound it, approach infinity:</p>

<!-- ![time](/assets/images/math/autonomous-equations/behavior.png?style?=centerme) -->

<img src="/assets/images/math/autonomous-equations/behavior.png" alt="equilibria" class="align-center">

<p>And so, more formally, for any solution $y(t)$ to an autonomous equation $f(y)$ we have the following for an arbitrary point $t_0$ in solution's domain:</p>

<ul>
    <li>if $f(y(t_0))=0$ then $y(t)$ is a equilibrium solution.</li>
    <li>if $f(y(t_0))>0$ then $y(t)$ is increasing and, as $t\to\infty$, tends to the first equilibrium solution greater than $y(t_0)$ or, if none exist, tends to $\infty$.</li>
    <li>if $f(y(t_0))<0$ then $y(t)$ is decreasing and, as $t\to\infty$, tends to the first equilibrium solution lesser than $y(t_0)$ or, if none exist, tends to $-\infty$.</li>
</ul>

<div class="notice--info">
  Note that the limiting behavior is reversed when $t\to-\infty$, we can see this by simply negating the ODE. Also note that this behavior applies only to solutions that satisfy Picard–Lindelöf.
</div>
</details>

<details><summary><h3 class="inline">Phase Line</h3></summary>
<p>A simple consequence of autonomous ODE's being time independent is that the slopes of the slope field are the same for any time $t$:</p>

<!-- ![time](/assets/images/math/autonomous-equations/time-invariance.png?style?=centerme){:width="550px"} -->

<img src="/assets/images/math/autonomous-equations/time-invariance.png" alt="time-invariance" class="align-center">

<p>As a result, the graph is redundant in the x-axis and can be encapsulated by a 1-dimensional line parallel to the y-axis. A simplified version of such a plot is called a <b>phase line</b>:</p>

<!-- ![triple](/assets/images/math/autonomous-equations/triple-graph.png?style?=centerme) -->

<img src="/assets/images/math/autonomous-equations/triple-graph.png" alt="triple-graph" class="align-center">

<p>As we can see, the phase line denotes the equilibrium solutions (i.e. the roots of $f(y)$) with a filled in circle while denoting the intervals with increasing/decreasing solutions (i.e. the intervals where $f(y)$ is above/below the $y$-axis) with an up/down arrow.</p>

<p>Phase lines are useful tools in visualizing the properties of particular solutions to autonomous equations. Just by seeing where a solution falls in it, we can tell whether it is increasing, decreasing, or an equilibrium solution. We can also surmise its limiting behavior since it will approach the nearest equilibrium point in the direction it is growing/shrinking. And, if there is no such equilibrium, the solution must grow unbounded.</p>
<p></p>
</details>

<details><summary><h3 class="inline">Classification of Equilibria</h3></summary>
<p>As a quick refresher, the equilibria of a first order ODE can be put into three catagories:</p>

<ul>
    <li><b>Stable</b>: Solutions sufficiently close to this equilibrium will asymptotically approach it as $t\to\infty$.</li>
    <li><b>Unstable</b>: Solutions sufficiently close to this equilibrium will diverge from it.</li>
    <li><b>Semi-stable</b>: Solutions sufficiently close on one side of this equilibrium will asymptotically approach it as $t\to\infty$, but solutions on the other side will diverge from it.</li>
</ul>

<p>Thanks to the limiting behavior of solutions we discussed earlier, classifying the equilibria of an autonomous equation is as easy as spotting the pattern on its phase line:</p>

<!-- ![equilibria](/assets/images/math/autonomous-equations/equilibria.png?style?=centerme) -->

<img src="/assets/images/math/autonomous-equations/equilibria.png" alt="equilibria" class="align-center">

<p>If the surrounding arrows of an equilibrium point point towards it, it is stable (a sink). If they point away from it, it is unstable (a source). And if they point in any other combination, it is semi-stable (a node).</p>

<b>First Derivative Test</b>
<br>
For any equilibrium point $y_0$ of an autonomous ODE $f(y)$ we have the following:

<ul>
    <li>if $f'(y_0)<0$ then $y_0$ is stable (a sink).</li>
    <li>if $f'(y_0)>0$ then $y_0$ is unstable (a source).</li>
    <li>if $f'(y_0)=0$ then the test gives us no information.</li>
</ul>
</details>

<details><summary><h3 class="inline">Bifurcations</h3></summary>
<!-- Has a definition of topologically equivalent
https://kurser.math.su.se/pluginfile.php/4075/mod_resource/content/0/GenericHopfBifurcation.pdf -->

<p>Recall that a <b>bifurcation</b> of a paramaterized family of ODEs $y'=f_\mu(t,y)$ occurs at $\mu=\mu_0$ when the solution set of $f_{\mu_0}(t,y)$ has a different topology than solution sets for values of $\mu$ arbitrarily close to $\mu_0$.</p>

<p>In the case of a family of first order autonomous equations with parameter $\mu$:</p>

$$y'=f_\mu(y)$$

<p>the only kind of bifurcations that can occur are those that change the number/stability of equilibria. And so to visualize these changes, we draw a <b>bifurcation diagram</b> consisting of the following set of points $\mathfrak{B}$ on the $\mu y$ plane:</p>

$$\mathfrak{B}=\{(\mu,y)\in\mathbb R^2\mid f_\mu(y)=0\}$$

<img src="/assets/images/math/autonomous-equations/bifurcation.png" alt="bifurcation" class="align-center">

<!-- BIFRUCATION DIAGRAM HERE + 3 values of MU around VALUE
somethig like this:
http://sosmath.com/diffeq/first/bifurcation/bifurcation.html -->

<p>This is a graph of every equilibrium point for every value of $\mu$ and, like a phase line, it makes it easier to spot values and behaviors of interest. In fact, you'll notice that for any particular parameter $\mu_0$, the line $\mu=\mu_0$ is the phase line of the equation $y'=f_{\mu_0}(y)$. You'll also notice that instead of labeling <i>intervals</i> of increasing/decreasing, we shade <i>sectors</i> of increasing/decreasing.</p>

<p>The <b>bifurcation values</b> of the family are simply the values of $\mu$ for which the number/stability of equilibria change. In this case $\mu=0$ is one such value because for $\mu$ after this there are now 2 equilibria rather than 1. This particular type of bifurcation is called a pitchfork bifurcation, and there are other types as well.</p>

<b>Sketching Bifurcation Diagrams</b><br>
<p>We can graph the equilibria by setting $f_\mu(y)=0$ and solving for $y$ in terms of $\mu$. We must be careful, though, to not lose any points due to things like division by zero.</p>

<p>To shade the sectors appropriately, we simply plug a point from each sector into the differential equation and label it increasing if it is positive and decreasing if it is negative (i.e. we perform the first derivative test). Note that this test will always be conclusive because the only points that won't be either positive or negative, i.e. zero, are the equilibria.</p>

<!-- First we pick a parameter $\mu_0$ whose phase line that goes through as many sectors as possible, to minimize the number of values we need to check. Then, we find the equilibria of $f_{\mu_0}(y)$ as well as classify them. A quick way to do this is the first derivative test mentioned above, although this doesn't work on nodes.</p> -->

<!-- <p>Armed with this knowledge, we can now shade the areas directly above and below the tested equilibria depending on what classification we found. We repeat this process with other values of $\mu$ until we have all sectors shaded.</p> -->
<div class="notice--info">
  Here is a useful <a href="http://www.scholarpedia.org/article/Bifurcation"> article</a> and <a href="https://www.math.univ-toulouse.fr/~gfaye/ENS11/chap_bif.pdf">paper</a> on bifurcations.
</div>
</details>

## Second Order Equations
As mentioned earlier, higher order autonomous equations are not generally solvable. That said, there are some methods that may work in particular cases. Below we detail one common one for second order autonomous equations.

### Order Reduction
A useful method of solving second order autonomous ODEs is expressing them as first order ODEs. We do this by first letting $v=y'$ so that we have:

$$\frac{d^2y}{dt^2}=f(y,v)$$

Now note that, due to the chain rule, we can write:

$$\frac{d^2y}{dt^2}=\frac{dv}{dy}\frac{dy}{dt}=\frac{dv}{dy}v$$

Allowing us to express our original equation as the following first order ODE:

$$\frac{dv}{dy}v=f(y,v)$$

If this ODE is solved, we'll be left with a solution $v(y)$ which we can then use to solve the following first order autonomous equation:

$$\frac{dy}{dt}=v(y)$$

If we make certain assumptions about the function $f$, like it being separable or dependent only on $y$, we can obtain more [explicit solutions](https://calculus.subwiki.org/wiki/Second-order_first-degree_autonomous_differential_equation) for second order autonomous equations.
{: .notice--info}

<!-- ## Autonomous System
<details><summary><h3 class="inline">Phase Plane</h3></summary>
<p><i>Note that this section only considers real solutions to real valued autonomous systems.</i></p>

<p>Similar to phase lines, we can represent the behavior of solutions to a system of 2 autonomous equations by way of a <b>phase plane</b>:</p>

HERE IS THE PHASE PLANE

<p>Each point in the plane cooresponds to a particular initial condition $(x_0,y_0)$.</p>

<p>As you can see, due to the absence of a time dimension, the direction the solution evolves in as time increases is usually denoted by an arrow.</p>

<p>When Picard-Lindeloff is in play, no two solutions of autonomous systems can solve the same IVP. This is reflected in the phase plane as the fact that no solution can cross over another.</p> -->

<!-- <p>This leads to only 3 types of solutions on the phase plane</p> -->

<!-- <p><i>Note that the phase line and phase plane can be extended to any number of dimensions depending on the number $n$ of differential equations in the system. This forms an $n$-dimensional <b>phase space</b>. Although, past 3 dimensions, the diagram stops being a useful visualization.</i></p>
</details>

also show that this is equivalent to a first order general ODE or somethign like seond order ode relatinship blah. -->