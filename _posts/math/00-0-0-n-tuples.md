---
header:
  overlay_image: /assets/images/math/set-theory-splash.png
title: $n$-Tuples
date: 2018-04-23
excerpt: "A rigorous look at the definition and properties of $n$-tuples."
categories:
  - posts
tags: 
  - math
  - set-theory
---

<!-- An $n$-tuple is an ordered list of $n$ elements. It is dissimilar to a set in that the order of its elements matter, it must be finite, and it can contain multiples of the same element.

Here are some common names for tuples of different size:

$n$-Tuple | Alt. Name
:--|:--
$0$-tuple | null-tuple
$1$-tuple | singleton
$2$-tuple | ordered pair
$3$-tuple | ordered triplet
$n$-tuple | -->

<!-- *My [medium article](https://medium.com/@ozanerhansha/the-ordered-pair-and-set-theory-69aa6e2b8a32) on ordered pairs and their uses.* -->

<!--more-->

## Definition
### $1$-tuples
By convention, we define a $1$-tuple to simply be a set. This definition fits in nicely with the definition of the [unary Cartesian product](\cartesian-product#special-products) we put forward in our post on Cartesian products.

### $2$-tuples
We define $2$-tuples, more commonly known as **ordered pairs**, using the Kuratowski definition:

$$(x_1,x_2)=\{\{x_1\},\{x_1,x_2\}\}$$

The above definition distinguishes $x_1$ from $x_2$ in that both sets in the right set contain $x_1$ but only one contains $x_2$. This is what gives the pair order.

You'll notice in the special case that $x_1=x_2$ we have $(x_1,x_1)=\\{\\{x_1\\},\\{x_1,x_1\\}\\}=\\{\\{x_1\\}\\}$.
{:.notice--info}

### $n$-tuples
Using the $2$-tuple, we can define all $n$-tuples recursively as an ordered pair of an $(n-1)$-tuple and another element. The $3$-tuple, for example, would be:

$$\begin{align}
(x_1,x_2,x_3)&=((x_1,x_2),x_3)\\
&=\{\{(x_1,x_2)\},\{(x_1,x_2),x_3\}\}\\
&=\{\{\{\{x_1\},\{x_1,x_2\}\}\},\{\{\{x_1\},\{x_1,x_2\}\},x_3\}\}\\
\end{align}$$

And in general, an $n$-tuple for $n>2$ is recursively defined as:

$$(x_1,x_2,\cdots,x_{n-1},x_n)=((x_1,x_2,\cdots,x_{n-1}),x_n)$$

While the above definition is standard, there are alternate conceptions of $n$-tuples that allow for $0$-tuples. See [here](https://en.wikipedia.org/wiki/Tuple#Tuples_as_nested_sets) for one such definition.
{: .notice--info}

<!-- *Alternatively, $n$-tuples can also be defined as functions with domains over some finite interval of the positive integers. In this sense, they would be equivalent to finite sequences. Although since tuples are usually used to define functions (and thus finite sequences) this would be circular.*

Whatever definition is used, all that matters is that two $n$-tuples are equivalent *only* when the elements at each of their indices are equivalent. This is their defining property. -->

### Existence in ZFC
The existence of an ordered pair of elements in ZFC can be proved using the axiom of pairing three times. Once to prove that $ \\{ a \\} $ exists, another to prove $ \\{ a,b \\} $ exists, and one more time to pair them with each other.

And since $n$-tuples are simply nested ordered pairs, they too must exist.

## Simultaneous Interpretation
A consequence of our definition is that any $n$-tuple can also be thought of as a $k$-tuple where $1\le k\le n$. This is an immediate consequence of the recursive definition:

$$(x_1,x_2,\cdots,x_n)=(\underbrace{(x_1,x_2,\cdots,x_{n-k+1})}_{1},\underbrace{x_{n-k+2}}_{2},\cdots,\underbrace{x_n}_{k})$$

It is this property that will allow us to also simultaneously interpret the [arity of Cartesian products](\cartesian-product#simultaneity-of-arity) and thus the arity of relations and functions.

Note that this trivially applies to the $k=1$ case as all sets are $1$-tuples by definition.
{: .notice--info}

## Equality
Two ordered pairs are equivalent if and only if the elements in each of their respective indices are equal. That is to say, for two $n$-tuples $X$ and $Y$:

$$\begin{align}
X&=(x_1,x_2,x_3,\cdots,x_n)\\
Y&=(y_1,y_2,y_3,\cdots,y_n)
\end{align}$$

We have the following:

$$\begin{align}
X=Y&\equiv\left(\forall k\in[1..n]\right) x_k=y_k\\
&\equiv x_1=y_1 \land x_2=y_2 \land \cdots \land x_n=y_n\\
\end{align}$$

<!-- *Where $n$ is a set as per its construction in the [natural numbers](\natural-numbers).* -->

Note that this implies that tuples of different sizes will never be equal. Unless, of course, their size difference is only a matter of simultaneous interpretation.

## Extraction
In order to use these tuples, we have to be sure we can produce some formula to extract the their elements. The formula for extracting the $i$th element of an $n$-tuple is called the **$i$th projection**.

### Extracting Elements of $2$-tuples
To extract the first element $\pi_1(P)$ of an ordered pair $P=(a,b)$ we can use the following construction:

$$\pi_1(P)=\bigcup\bigcap P=a$$

<details class="bordered"><summary><strong>Proof</strong></summary>
  <!-- <b>Lemma 1</b>
  <p>To make proving the above statement easier, it would help to prove that the arbitrary union of a set of an element $\{x\}$ is that element $x$:

  $$\bigcup \{x\}=x$$

  First let's start with the definition of the arbitrary union of a set $S$:

  $$\bigcup S=\{a\mid \left(\exists b\in S\right)a\in b\}$$

  In in English this means, all elements $a$ that are contained in at least one set $b$ that are contained in $S$. (i.e the union of all the elements in $S$). Plugging $\{x\}$ in for $S$ we see:

  $$\bigcup \{x\}=\{a\mid \left(\exists b\in \{x\}\right)a\in b\}$$

  Since there is only one element in $\{x\}$, namely $x$, there is only one set $b$ could be: $x$. So, we can say the following:

  $$\bigcup \{x\}=\{a\mid a\in x\}$$

  And since the set of all elements in $x$ is simply that same set:

  $$\boxed{\bigcup \{x\}=x}$$
  </p>
  <b>The Proof</b> -->
  $$\begin{align}
  \pi_1(P)&=\bigcup\bigcap P\\
  &=\bigcup\bigcap \{\{a\},\{a,b\}\}\\
  &=\bigcup \left(\{a\}\cap\{a,b\}\right)\\
  \end{align}$$

  Of course the only element in common between $\{a\}$ and $\{a,b\}$ is $a$ so:

  $$\pi_1(P)=\bigcup \{a\}$$

  And because the union of all the elements in $a$ is precisely $a$, we have:

  $$\pi_1(P)=\bigcup \{a\}=a$$

  And indeed, $a$ is the first element of the ordered pair $P$.
</details><br>
The second element $\pi_2(P)$ of an ordered pair $P=(a,b)$ can be found like so:

$$\pi_2(P)=\bigcup\{x\in\bigcup P\mid\bigcup P\not=\bigcap P\implies x\not\in\bigcap P\}=b$$

<!-- <details><summary><strong>Proof</strong></summary>
I'll do it later...
</details> -->

### Extracting Elements of $n$-tuples
You may have noticed that the definitions above only apply to $2$-tuples. What about $n$-tuples? Well, quite intuitively, we can extract the elements of an $n$-tuple of any size by recursively using the $\pi_1$ and $\pi_2$ functions we defined above.

The notation we'll use is as follows: $\pi^n_i(P)$ is the $i$th element of the $n$-tuple $P=\left(x_1,x_2,x_3,\cdots,x_n\right)$.

The first element of $P$ can be found like so:

$$\pi^n_1(P)=\underbrace{\pi_1\circ\cdots\circ\pi_1}_{n-1\text{ iterations}}(P)=x_1$$

For any element *other* than the first, we can use the following formula:

$$\pi^n_i(P)=\pi_2\circ\underbrace{\pi_1\circ\cdots\circ\pi_1}_{n-i\text{ iterations}}(P)=x_i$$

This should be fairly intuitive as the repeated $\pi_1$ serve to extract the desired nested tuple and once we reach the base case of the $2$-tuple, we either want the first $\pi_1$ or second $\pi_2$ term.

<!-- <details><summary>"Proof" & Intuition</summary>
Not really a proof, I just wrote down how to find the elements of $2,3,4,5$-tuples and found the pattern:

$$\begin{align}
  &2\text{-tuple}\left\{
    \begin{array}{l}
      \pi^2_1=\pi_1(P)\\
      \pi^2_2=\pi_2(P)\\
    \end{array}
  \right.\\
  &3\text{-tuple}\left\{
    \begin{array}{l}
      \pi^3_1=\pi_1\left(\pi_1\left(P\right)\right)\\
      \pi^3_2=\pi_2\left(\pi_1\left(P\right)\right)\\
      \pi^3_3=\pi_2\left(P\right)\\
    \end{array}
  \right.\\
  &4\text{-tuple}\left\{
    \begin{array}{l}
      \pi^4_1=\pi_1\left(\pi_1\left(\pi_1\left(P\right)\right)\right)\\
      \pi^4_2=\pi_2\left(\pi_1\left(\pi_1\left(P\right)\right)\right)\\
      \pi^4_3=\pi_2\left(\pi_1\left(P\right)\right)\\
      \pi^4_4=\pi_2\left(P\right)\\
    \end{array}
  \right.\\
  &5\text{-tuple}\left\{
    \begin{array}{l}
      \pi^5_1=\pi_1\left(\pi_1\left(\pi_1\left(\pi_1\left(P\right)\right)\right)\right)\\
      \pi^5_2=\pi_2\left(\pi_1\left(\pi_1\left(\pi_1\left(P\right)\right)\right)\right)\\
      \pi^5_3=\pi_2\left(\pi_1\left(\pi_1\left(P\right)\right)\right)\\
      \pi^5_4=\pi_2\left(\pi_1\left(P\right)\right)\\
      \pi^5_5=\pi_2\left(P\right)\\
    \end{array}
  \right.\\
\end{align}$$

Why are is there a conditional definition of the $a$th element of an $n$-tuple? What causes this asymmetry? Well it must be the fact that our base case in defining $n$-tuples was the ordered pair rather than some sort of $1$-tuple. Although it's possible that starting with a $1$-tuple wouldn't change this conditional...
</details> -->

## Some Uses
### Cartesian product
Ordered pairs are necessary in defining the [Cartesian Product](/cartesian-product), which in turn are used to define relations, functions, coordinates, etc.

### Mathematical Structures
Tuples are often used to encapsulate sets along with some operator or relation into a complete mathematical structure. One example is a graph which is defined as an ordered pair $G=(V,E)$ where $V$ is a set of vertices and $E$ a set of edges connecting those vertices. Another example is a group which is defined as an ordered pair $G=(S,\cdot)$ where $\cdot$ is some binary operation on the elements of $S$. Tuples are also used to encapsulate rings, fields, vector spaces, topological spaces, ordered sets, and so on.
