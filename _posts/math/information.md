---
header:
  overlay_image: /assets/images/math/probability-splash.jpg
title: Information
date: 2020-05-21
excerpt: "what the hell is information?"
categories:
  - posts
tags: 
  - math
  - probability-theory
---

## Self-Information
Given a probability space $(\Omega,\mathcal F,P)$, the **self-information** of an event $E\in\mathcal F$ is given by:

$$I(E)=-\log P(E)$$

### Units
The units we express information in depend on the base used in the logarithm. A base of $e$, i.e. the natural logarithm, results in units called *nats*. A base of $10$ results in the unit of *digits*, and a base of 2 results in the familiar unit of *bits*.

We can think of these units as analogous to that of degrees and radians. The quantity $I(E)$ is indeed *dimensionless*, yet the quantity is taken with respect to some logarithm base, which we denote via the 'units' of information used (bits, nats, etc.)

We can convert between units by simply:


For example: 


And thus 1 nat equals x bits.

## IMF
Given a discrete RV $X$ with a pmf of $p_X$, we can define a function $I_X$ called the **information mass function (imf)** such that:

$$\begin{align*}
I_X(x)&=I(X=x)\\
&=-\log P(X=x)\\
&=-\log p_X(x)
\end{align*}$$

We can see that it is analogous to the pmf but, instead of giving the probability of any particular outcome of $X$, it gives the self-information.

## Entropy
Given a discrete $(S,\Sigma)$-valued RV $X$, we define its **shannon entropy**, or simply **entropy**, $H(X)$ as the expected value of its imf:

$$\begin{align*}
H(X)&=E[I_X(X)]\\
&=\sum_{x\in S}P(X=x)I_X(x)\\
&=-\sum_{x\in S}p_X(x)\log p_x(x)
\end{align*}$$