---
header:
  overlay_image: /assets/images/math/probability-splash.jpg
title: Random Variables
date: 2020-05-21
excerpt: "Defining the core object of probability theory."
categories:
  - posts
tags: 
  - math
  - probability-theory
---

## Measurable Function
A **measurable function** from a measure space $(S_1,\Sigma_1)$ to another measure space $(S_2,\Sigma_2)$ is a function $\mu:\Sigma_1\to\Sigma_2$ such that:

$$(\forall B\in\Sigma_2)\quad \mu^{-1}(B)\in\Sigma_1$$

<!-- $$B\in\Sigma_2\implies\mu^{-1}(B)\in\Sigma_1$$ -->

Note that $\mu^{-1}(B)$ denotes the preimage of $B$ under $\mu$, i.e. $\mu^{-1}(B)=\\{x\in S_1\mid\mu(x)\in B\\}$.
{:.notice--info}

## Random Variable
A **$(S,\Sigma)$-valued random variable** on a probability space $(\Omega, \mathcal F, P)$ is a measurable function from $(\Omega,\mathcal F)$ to $(S,\Sigma)$.

## Outcome of a RV
Consider a probability space $(\Omega,\mathcal F, P)$ and a RV $X$ over it. Given an outcome $\omega\in\Omega$, we call $X(\omega)$ the **outcome** of $X$.

## Distribution of a RV
Every random variable $X$ has a **distribution**, or **law**, associated to it. This is a function $L_X:\Sigma\to[0,1]$ that maps all measurable sets, i.e. elements of the $\sigma$-algebra $\Sigma$, to some probability. It is defined as the **pushforward** measure:

$$L_X=P\circ X^{-1}$$

For example, the probability that the outcome of a random variable $X$ is contained within $B$ is given by:

$$\begin{align*}
P(X\in B)&=P(\{\omega\in\Omega\mid X(\omega)\in B\})\\
&=P(X^{-1}(B))\\
&=L_X(B)
\end{align*}$$

Note that two RV's $X$ and $Y$ that have the same distribution, and are on the same probability space, are not necessarily equal, although the converse is true:

$$L_X=L_Y\nRightarrow X=Y$$

In the case of discrete random variables, however, identical distributions on the same probability space do indeed imply equality.

### Notation
Given two $(S,\Sigma)$-valued random variables $X$ and $Y$ over the same probability space, we use the notation:

$$X\sim Y\equiv L_X=L_Y$$

to denote that they share the same distribution. However, given a RV $X$ and a particular probability distribution $f:\Sigma\to[0,1]$ we use the same notation to denote:

$$X\sim f\equiv L_X=f$$

