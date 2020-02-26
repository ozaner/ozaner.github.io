<!-- ---
layout: post
title: Numerical Analysis Notes Ch. 1
date: 2019-02-15
tags: math computer-science numerical-analysis
--- -->
My notes on Atkinson and Han's *Elementary Numerical Analysis*. Chapter 1 - Taylor Polynomials.

## 1.1 - 1.2 Taylor Polynomials and Error
See post on [Taylor Series](/taylor-series).

## 1.3 Polynomial Evaluation
Given a polynomial with coefficients $c_k$:

$$p(x)=\sum_{k=0}^n c_k x^k=c_0+c_1x+c_2x^2+\cdots+c_n c^n$$

What is the fastest way to evaluate it for a given input $x$? Where 'fastest' means the lowest combined total of additions and multiplications.

<!--more-->

#### Naïve Algorithm
Naïvely, computing the $k$th term of a polynomial takes $k$ multiplications:

$$cx^k=c\cdot\underbrace{x\cdot x\cdots x}_{k-1\text{ multiplies}}$$

Adding up all $n+1$ terms of an $n$th degree polynomial would take $n$ additions:

$$\underbrace{c_0+c_1x+c_2x^2+\cdots c_nx^n}_{n\text{ additions}}$$

Thus, the operations this algorithm uses for an $n$th degree polynomial total to:

$$\underbrace{n}_{+}+\underbrace{\sum_{k=0}^n k}_{\times}=n+\frac{n(n-1)}{2}\in O(n^2)$$

*This doesn't take into account the operation of storing a variable to memory but the time complexity is not affected by this.*

#### Less Naïve Algorithm
We can improve upon this by not computing each term independently. At the $k$th step we would store the result of $x^k$ to be used in computing $x^{k+1}$:

$$cx^k=\underbrace{c\cdot x\cdot x^{k-1}}_{2\text{ multiplies}}$$

*Except for $k=0$ and $k=1$ which take $0$ and $1$ multiply respectively.*

Along with the, still $n$, additions this comes out to:

$$\underbrace{n}_{+}+\underbrace{2(n-1)+1}_{\times}=3n-1\in O(n)$$

#### Horner's Method
Perhaps somewhat surprisingly, the above algorithm can be improved further. The following algorithm, **Horner's method**, is the most efficient way to evaluate a polynomial (i.e. takes the least number of operations). To see how this is done note the following identity:

$$\begin{align*}
  p(x)&=c_0+c_1x+c_2x^2+\cdots+c_nx^n\\
  &=c_0+x\big(c_1+x\big(c_2+x\big(c_3+\cdots+x(c_{n-1}+xc_n)\cdots \big )\big )\big )
\end{align*}$$

This algorithm has us multiply the current sum $s$ by $x$ and add the next coefficient (from last to first) and then repeat. By doing this we work our way from the inner most parenthesis to the outside, completing the evaluation. To make this clear the steps are:

- $s:=xc_n$
- $s:=x(c_{n-1}+s)$
- $s:=x(c_{n-2}+s)$
- $\ \ \ \ \ \vdots$
- $s:=x(c_1+s)$
- $s:=c_0+s$

And we are done. Note that this takes 1 multiplication for the first step, 1 addition for the last step, and 1 of each for the middle $n-1$ steps. This totals to:

$$n+n=2n\in O(n)$$
