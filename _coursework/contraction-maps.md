---
title: Contraction Maps
date: 2019-09-30
permalink: /contraction-maps/
toc: true
toc_label: "Overview"
tags:
    - math
    - analysis
---

## Definition
A **contraction map** on a metric space $(X,d)$ is a function $T:X\to X$ such that:

$$(\exists k\in[0,1))(\forall x,y\in X)\,\,d(T(x),T(y))\le kd(x,y)$$

Another way to phrase this is that applying the contraction on any two points shrinks their distance by at least some factor $k$.

<!-- (this number, of course, can't be negative as distances are nonnegative) -->

<!--more-->

## Lipschitz continuity
Note that this definition immediately implies that any contraction map $T$ is a **Lipschitz continuous** function. With the minimum **Lipschitz constant** $k$ given by:

$$k=\sup_{\substack{x,y\in X\\x\not=y}}\frac{d(T(x),T(y))}{d(x,y)}\lt 1$$

With this supremum guaranteed to exist by the definition of a contraction map.

*In the special case that the metric space has only 1 element, we have $k=0$.*

## Uniqueness of Fixed Point
Contraction maps have the interesting property of having at most $1$ fixed point. That is to say, if a contraction map $T$ has a fixed point, it must be unique:

<!-- $$|\{x^*\in X\mid T(x^*)=x^*\}|\le 1$$ -->

$$\forall x_1,x_2\in X\, (T(x_1)=x_1\wedge T(x_2)=x_2)\implies x_1=x_2$$

<details>
<summary><strong>Proof</strong></summary>
Let $x_1$ and $x_2$ be two fixed points of a contraction $T$. The definition of contraction gives us the following:

$$d(T(x_1),T(x_2))\le kd(x_1,x_2)$$

And since $x_1$ and $x_2$ are fixed points we have:

$$d(x_1,x_2)\le kd(x_1,x_2)$$

However, since $k$ is some constant in $[0,1)$, and the function $d$ is nonnegative, the only way for the above inequality to hold is if

$$d(x_1,x_2)=0$$

Which, by the identity of indiscernibles, tells us that $x_1=x_2.\,\,\,\,\,\,\,\, \blacksquare$

</details>
<p></p>

As we'll see below, this property is strengthened for complete metric spaces, with each contraction always having a unique fixed point.

<!-- The [Banach fixed-point theorem](/banach-fixed-point-theorem) strengthens this statement for complete metric spaces, with each contraction on such a space always having exactly $1$ fixed point. -->

## Complete Metric Spaces
We can make stronger statements about the fixed points of contractions if we limit ourselves to complete metric spaces. In particular, given a contraction map $T$ on a (non-empty) complete metric space $(X,d)$, the **Banach fixed-point theorem** states:

$$(\exists! x^*\in X)\,\, T(x^*)=x^*$$

That is to say, every contraction on a complete metric space has a unique fixed point.

<details>
<summary><strong>Proof</strong></summary>
We have already proven the uniqueness of this point for all metric spaces (complete or otherwise) above. Now all that's left is to prove the existence of this fixed point assuming completeness.
</details>

### Remark on Convergence
An important fact about this unique fixed point $x^*$ is that:

$$(\forall x\in X)\,\, \left(\lim_{n\to\infty}\underbrace{T\circ T\circ\cdots\circ T}_{n}\ (x)=x^*\right)$$

Or in words, all elements of $X$ approach the fixed point $x^*$ when the map $T$ is repeatedly applied. This can equivalently be phrased in terms of the iteration $x_{n+1}=T(x_n)$:

$$(\forall x_0\in X)\,\, \lim_{n\to\infty} T(x_n)=x^*$$

<!-- <details>
<summary><strong>Proof</strong></summary>

</details>
<p></p> -->

It's important to note that this convergence isn't guaranteed for non-complete metric spaces.

### Uses of the Banach Fixed-Point Theorem
- The theorem is used to prove the existence and uniqueness of solutions to differential equations (i.e. the Picard–Lindelöf theorem) via an iterative sequence of integrals.
- It's used to prove the effectiveness of fixed point methods for the numerical approximation of differential equations (e.g. Newton's method).
- Like with differential equations, it can also be used to prove the existence and uniqueness of solutions to reinforcement learning problems.

<!-- ## Variations
#### Metric Map
A **metric map**, also known as a *non-expansive map*, is a map

#### Subcontraction Map -->