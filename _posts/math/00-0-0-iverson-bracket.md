---
header:
  overlay_image: /assets/images/math/set-theory-splash.png
title: Iverson Bracket
date: 2018-08-27
excerpt: "A rigorous treatment of the Iverson bracket along with an overview of its properties and uses."
categories:
  - posts
tags: 
  - math
  - logic
  - set-theory
---

The Iverson bracket, denoted $[P]$, is a "function" that evaluates to $1$ if the given proposition $P$ is true and $0$ if it's false. That is to say:

$$[P]={\begin{cases}1,&{P}\\0,&{\neg P}\end{cases}}$$

The bracket notation can also be used with predicates:

$$[P(x)]={\begin{cases}1,&{P(x)}\\0,&{\neg P(x)}\end{cases}}$$

Below I give two set-theoretic definitions of the Iverson bracket. One for the propositional case and one for the predicate case.

## Propositional Definition
The Iverson bracket is not a true function as there is no such set of all propositions to be its domain. We can instead think of the notation $[P]$ as being shorthand for the following set:

$$[P]\equiv\bigcup\{x\in \{0,1\}\mid(x=1\wedge P) \vee (x=0\wedge\neg P)\}$$

<!-- *Where $2=\\{0,1\\}$ as per its construction in the [natural numbers](\natural-numbers).* -->

The set builder notation above will end up being $\\{0\\}$ or $\\{1\\}$, depending on whether $P$ is true, and the arbitrary union $\bigcup$ outside of the set 'unwraps' the resulting singleton, leaving us with just $0$ or $1$.
{:.notice--info}

This definition allows us to truly equate $[P]$ with the values $0$ and $1$ in the set-theoretic sense.

## Predicate Definition
For the predicate version of the Iverson bracket, we'd like $[P(x)]$ to be some function of $x$ and always return either $0$ or $1$. To this end, we must limit our $x$ to some domain $S$.

Also, to aid in defining $[P(x)]$ we'll call it $Q(x)$ for the time being and define $Q$ as:

$$\begin{gather*}
Q\equiv(S\times\{0,1\}, G_Q)\\
G_Q=\{(x,y)\in S\times\{0,1\}\mid(P(x)\wedge y=1)\vee(\neg P(x)\wedge y=0)\}
\end{gather*}$$

Where $S$ is the domain, $\{0,1\}$ the codomain, and $G_Q$ the graph of the function $Q$.

<!-- While we could simply use the same definition above and replace all instances of $P$ with $P(x)$, it might instead be more useful to define $[P(x)]$ as a full blown set-theoretic function. -->

<details class="bordered">
<summary><strong>Proof of Function</strong></summary>
Clearly $Q$ is a relation as $G_Q\subseteq S\times\{0,1\}$. But to show that $Q$ is a function, we must show that it is right-unique. This should be clear as for any $x\in S$, $P(x)\oplus\neg P(x)$ due to the law of the excluded middle, meaning there is only a single pair $(x,y)\in G_Q$.
</details>
<p></p>

And so $Q:S\to \\{0,1\\}$ is a function. We can now define $Q(x)\equiv [P(x)]$, to return to our original notation. Note that due to the [simultaneity of arity](/relations/#simultaneity-of-arity), this definition works just as well for $n$-ary predicates, netting $n$-ary functions.

Also note that while we do limit ourselves to some domain $S$ rather than the whole universe, this is unavoidable if we are to identify the notation $[P(x)]$ with (not just a function) but any set, where $x$ is a free variable. At least in ZFC, that is.
{:.notice--info}

## Arithmetic Properties
Below are some of the immediate properties of the Iverson bracket. We can think of these equalities as bridges between the first order logic notions of truth (true vs. false) and the arithmetic/computational notion of booleans ($0$ vs. $1$).

- $[\neg P]=1-[P]$
- $[P\wedge Q]=[P][Q]$
- $[P\vee Q]=[P]+[Q]-[P][Q]$
- $[P\oplus Q]=([P]-[Q])^2$
- $[P\rightarrow Q]=1-[P]-[Q]+[P][Q]$
- $[P\equiv Q]=1-([P]-[Q])^2$

<!-- Note that these properties apply to predicates $P(x), Q(y)$ as well, as long as we hold the inputs $x,y$ constant.
{: .notice--info} -->

<!-- *The last three can be solved via substitution of the first three and normal propositional calculus.* -->

## Examples
Iverson brackets are, in many cases, a more natural way to express certain conditional functions or properties.

<details open>
<summary><strong>Kronecker Delta</strong></summary>
The Iverson bracket generalizes the Kronecker delta function $\delta_{ij}$ to any proposition $P$ rather than the specific proposition $i=j$. We can express the Kronecker delta function in terms of the Iverson bracket as so:

$$\delta_{ij}=[i=j]$$
</details>

<details open>
<summary><strong>Trichotomy of $\mathbb{R}$</strong></summary>
Iverson brackets afford a much simpler way to convey the property of trichotomy, or any list of mutually exclusive conditions:

$$[a<b]+[a=b]+[a>b]=1$$
</details>

<details>
<summary><strong>Sign Function</strong></summary>
$$\operatorname{sgn}(x)=[x>0]-[x<0]\ \ \ \ \ \ (\text{For $x\not=0$})$$
</details>

<details>
<summary><strong>Absolute Value</strong></summary>
$$ {\begin{aligned}|x|&=x\cdot \operatorname {sgn}(x)\\&=x([x>0]-[x<0])\end{aligned}}$$
</details>

<details>
<summary><strong>Heaviside Step Function</strong></summary>
$$H(x)=[x>0]$$
</details>

<details>
<summary><strong>Min and Max</strong></summary>
$$\min(x,y)=x[x\leq y]+y[x>y]$$

$$\max(x,y)=x[x>y]+y[x\leq y]$$
</details>

<details>
<summary><strong>Ceiling and Floor</strong></summary>
$$\lceil x\rceil =\sum _{n\in\mathbb Z}n[n-1<x\le n]$$

$$\lfloor x\rfloor =\sum _{n\in\mathbb Z}n[n\le x<n+1]$$
</details>
