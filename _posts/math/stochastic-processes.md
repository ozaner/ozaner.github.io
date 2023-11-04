---
header:
  overlay_image: /assets/images/math/probability-splash.jpg
title: Stochastic Processes
date: 2020-03-14
excerpt: "A formal look at a key concept in probability theory, used everywhere from computer science to finance."
categories:
  - posts
tags: 
  - math
  - probability-theory
---

## Definition
A **stochastic process** $X$ is an indexed family of random variables $X_i:\Omega\to S$, where each $X_i$ is from some probability space $(\Omega,\mathcal F, P)$ to some measurable space $(S,\Sigma)$:

<!-- $$\begin{gather}
X:I\to S^\Omega\\
X=(X_i)_{i\in I}
\end{gather}$$ -->

$$X=(X_i)_{i\in I}$$

<!-- \quad\text{s.t. $(\forall i\in I)\,\,X_i$ is $(\mathscr P,\mathscr S)$-measurable} -->

### Terminology
For the above stochastic process $X$, we call:
- $I$ the **index set** of $X$
- $\Omega$ the **sample space** of $X$
- $S$ the **state space** of $X$ 

### Alternate Representations
While we have defined a stochastic process as an indexed family of RVs, there are equivalent ways of identifying them. In particular, instead of a collection of random variables, a stochastic process $X: I\to S^\Omega$ can be represented by a single random variable $\widetilde{X}:\Omega\to S^I$.

<!-- For example, given a certain outcome $\omega_0\in\Omega$ we can refer to its corresponding realization $f_{\omega_0}$ in two ways:

$$f_{\omega_0}=\underbrace{(X_i(\omega_0))_{i\in I}}_{\text{indexed family}}=\underbrace{\widetilde{X}(\omega_0)}_{\text{random var.}}$$ -->

We can convert between the two representations via the following isomorphism:

$$\begin{aligned}
  X:I\to S^\Omega&\cong\operatorname{uncurry} X:I\times\Omega\to S\\
  &\cong\operatorname{swap}\operatorname{uncurry} X:\Omega\times I\to S\\
  &\cong\operatorname{curry}\operatorname{swap}\operatorname{uncurry} X:\Omega\to S^I
\end{aligned}$$

And for notational ease, we denote the RV form of a stochastic process $X$ as:

$$\widetilde{X}=\operatorname{curry}\operatorname{swap}\operatorname{uncurry} X$$

With this representation, familiar notions like independence, distribution, variance, etc. can all be defined for stochastic processes the same way they are for random variables.

<!-- For example, two stochastic processes $X$ and $Y$ are independent iff:

$$P(\widetilde{X}\widetilde{Y})=P(\widetilde{X})P(\widetilde{Y})$$ -->

<!-- This representation makes easier to talk about certain aspects of the SP. For example, the **law** or *distribution* of an SP $X$ can now be defined the same way as any other random variable:

$$\operatorname{Law}(\widetilde{X})=P\circ\widetilde{X}^{-1}$$ -->

<!-- Where $\widetilde{X}^{-1}$ is the preimage of $\widetilde{X}$.
{:.notice--info} -->

## Classifications
<!-- Note that stochastic processes can also be referred to as **random processes**  or **random functions**, analogous to random variables. Also note that the index set can also be referred to as the **parameter set**. -->

It is common to take some subset of $\mathbb R$ or $\mathbb R^n$ to be the index set $I$ of a stochastic process $X$. In those cases we can assign the following classifications:
- if $I$ is a subset of $\mathbb Z$, then we call $X$ a **discrete-time stochastic process**.
- if $I$ is an interval of $\mathbb R$, then we call $X$ a **continuous-time stochastic process**.
- if $I$ is a subset of $\mathbb R^n$, then we call $X$ a **random field**.

You'll notice that in the first two cases above, the index is a linearly ordered subset of $\mathbb R$ and can thus be associated with time. In these cases it is common to use the variables $t$ and $T$ rather than $i$ and $I$ as our index and index set respectively. It is also more common, especially in the continuous-time case, to denote the random variable $X_t$ as $X(t)$.
{:.notice--info}

## Realizations
Given a particular outcome $\omega_0\in\Omega$ of the sample space, we obtain a **realization**, or *sample function*, $f_{\omega_0}:I\to S$ of the stochastic process where:

<!-- $$f=(X_i(\omega_0))_{i\in I}$$ -->

$$f_{\omega_0}(i)=X_i(\omega_0)$$

Each outcome of the sample space corresponds to a realization. The set of all possible realizations is called the **ensemble** of the stochastic process.

