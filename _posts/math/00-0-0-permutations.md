---
header:
  overlay_image: /assets/images/math/probability-splash.jpg
title: Permutations
date: 2019-08-25
excerpt: "Notes on the definition, notation, and variants of the permutation."
categories:
  - posts
tags: 
  - math
  - combinatorics
---

## Definition
A **permutation** on a set $S$ is a bijective function $\sigma$ from $S$ to itself:

$$\sigma:S\xrightarrow{\small\rm Bijective} S$$

This, the modern mathematical definition of the term, is opposed to the more common conception of a permutation as an arrangement or *sequence* of all $n$ elements of $S$ with no repeats:

$$f: [1..n]\xrightarrow{\small\rm Bijective} S$$

<!-- *Where $n=[0..n-1]$ [as per von Neumann](/natural-numbers/#definition). So the zeroth element is $f(0)$, first is $f(1)$, etc.* -->

<!--more-->

We distinguish between these two definitions by calling the function definition an **active** permutation and the arrangement definition a **passive** permutation. In this way we can continue using the word 'permutation' in both situations and simply infer the definition from context. That said, we will be using the active definition unless otherwise specified.

## Notation
Permutations are functions commonly denoted by lowercase greek letters (e.g. $\sigma, \pi, \alpha$) and can be written in a variety of special notations, two of which are covered below.

### Two-Line Notation
A common way to define a permutation $\sigma$ on a finite set with $n$ elements, each denoted $s_i\in S$, is via **two-line notation**:

$$\sigma=\begin{pmatrix}s_{1}&s_{2}&\cdots&s_{i}&\cdots &s_{n}\\\sigma (s_{1})&\sigma (s_{2})&\cdots&\sigma (s_{i})&\cdots &\sigma (s_{n})\end{pmatrix}$$

<details>
<summary>Example</summary>
For example, a permutation on $\{1,2,3\}$ with $\sigma(1)=3,\sigma(2)=1$, and $\sigma(3)=2$ would be denoted:

$$\sigma=\begin{pmatrix}1&2&3\\3&1&2\end{pmatrix}=\begin{pmatrix}2&1&3\\1&3&2\end{pmatrix}$$

</details>

Note that this notation isn't unique, i.e. we can express the same permutation in many different ways ($n!$ ways to be precise) by simply rearranging the columns.
{:.notice--info}

### One-Line Notation
A more compact notation can be used in liu of the two-line notation if there is some accepted or implied total order $<_S$ of $S$. In this case there is no need to write the first line as it is implied, giving us the **one-line notation**:

$$\begin{gather*}
\sigma=\begin{pmatrix}\sigma (s_{1})&\sigma (s_{2})&\cdots&\sigma (s_{i})&\cdots &\sigma (s_{n})\end{pmatrix}\\
i<j\implies s_i<_Ss_j
\end{gather*}$$

<details>
<summary>Example</summary>
For example, we know there is a natural ordering of the positive integers (i.e. $1,2,3,\cdots$) and so we can rewrite our previous example permutation as:

$$\sigma=\underbrace{\begin{pmatrix}1&2&3\\3&1&2\end{pmatrix}}_{\text{two-line}}=\underbrace{\begin{pmatrix}3&1&2\end{pmatrix}}_{\text{one-line}}$$

</details>
<p></p>
You'll notice that in this notation, our active permutations looks similar to passive permutations, i.e. an arrangement of the elements of a set.

Unlike the two-line notation, this notation is unique (up to whatever the ordering of $S$ is).
{:.notice--info}

## Symmetric Group
Under function composition, the set of all permutations of a set $S$ forms a group called the **symmetric group** of $S$:

$$\begin{gather*}
\text{Sym}(S)=(G,\circ)\\
G=\{\sigma\in S\times S\mid\sigma\text{ is a bijection}\}
\end{gather*}$$

*Where $\circ$ denotes function composition over $S\times S$.*

That this is indeed a group can be seen from the following 4 facts:

- Function composition is **associative**.
- The **identity** function is a permutation.
- Because they are bijections, every permutation has an **inverse** which are also permutations since $S=\text{domain}=\text{codomain}$.
- The composition of a bijection with a bijection is also bijection and, because $S=\text{domain}=\text{codomain}$, we have that permutations are **closed** under function composition.

### Notation
When talking about symmetric groups in general, it is common to denote the symmetric group of an $n$ element set as $S_n$, with the actual elements of the group being unimportant as they are all group isomorphic.

## Counting Permutations
The number of different permutations of a set (i.e. the cardinality of it's symmetric group) is one of the most, arguably *the* most, fundamental principles of combinatorics.

Note that for a finite set with $n$ elements, we have $n$ choices for what to map the first element to, $n-1$ choices for the second element, and so on until we reach the $n$th element which has only $1$ choice left to map to.

Thus, by the [principle of counting](/principle-of-counting), the number of distinct permutations of an $n$ element set $S$ is given by the [factorial](\superfactorial-and-hyperfactorial)[^f1]:

$$|\text{Sym}(S)|=n(n-1)(n-2)\cdots3\cdot2\cdot1=n!$$

### Infinite Sets
The number of permutations of a set, and thus the factorial, can be generalized to infinite cardinals. That is, given an infinite set $S$ with cardinality $|S|=\kappa$:

$$|\text{Sym}(S)|=\kappa^\kappa=2^\kappa=|\mathcal{P}(S)|$$

## Generalizations
We now detail some generalizations of passive permutations which may serve useful in solving combinatorial problems.

### Partial Permutations
A **$k$-permutation** of an $n$ element set $S$ is a sequence of $k$ distinct elements of $S$, with $k\le n$:

$$f:[1..k]\to S,\,\,\,\,\,\,i\not=j\Rightarrow\sigma(i)\not=\sigma(j)$$

The number of different $k$-permutations a set with $n$ elements has is denoted $_nP_k$, or more commonly in statistics as `nPr(n,k)`. Via the principle of counting, it is given by:

$$_nP_k=n(n-1)(n-2)\cdots(n-k+1)=n^{\underline {k}}$$

Which we can see is just the $k$th falling factorial of $n$. Another way to see this is to recognize that there are $\binom{n}{k}$ [combinations](\binomial-coefficient) of $k$ elements each with $k!$ permutations, giving us:

$$_nP_k=\binom{n}{k}k!=\frac{n!}{(n-k)!k!}k!=\frac{n!}{(n-k)!}=n^{\underline{k}}$$

### Multiset Permutations
Given a multiset $S$ of size $n$, a **multiset permutation** is a sequence of $S$ in which each element $s_i$ appears exactly as many times as is their multiplicity $k_i$:

$$f:[1..n]\to S,\,\,\,\,\big|\{i\mid f(i)=s_i\}\big|=k_i$$

The number of different multiset permutations a multiset $S$ of size $n$ has is simply $n!$ divided by the number of permutations of identical elements, i.e. the factorial of each element's multiplicity:

$$\frac{n!}{k_1!k_2!\cdots k_r!}=\binom{n}{k_1,k_2,\cdots,k_r}$$

*Where the number of distinct elements in $S$ is $r$.*

You'll notice that this is equivalent to the [multinomial coefficient](/binomial-coefficient#multinomial-coefficient), which gives the number of different ways to split a set of $n$ elements into groups of $k_1,k_2,\cdots,k_r$.

### Partial Multiset Permutations
A mixture of the two previous variants, a partial multiset permutation of length $k$ is called a **$k$-multiset permutation**. That is, a sequence of length $k$ on a multiset $S$ where no element $s_i$ appears more times than its multiplicity $k_i$:

$$f:[1..k]\to S,\,\,\,\,\big|\{i\mid f(i)=s_i\}\big|\le k_i$$

To my knowledge, however, there is no concise formula to count these permutations.

<!-- https://math.stackexchange.com/questions/1395657/on-counting-and-generating-all-k-permutations-of-a-multiset -->

[^f1]: Note that $\vert\text{Sym}(S)\vert$ denotes the cardinality of the symmetric group's underlying set, not of $\text{Sym}(S)$ which is just an ordered pair. 