---
header:
  overlay_image: /assets/images/math/probability-splash.jpg
title: The Basic Principle of Counting
date: 2019-06-25
excerpt: "An overview of a basic counting principle along with examples."
permalink: /principle-of-counting/
categories:
  - posts
tags: 
  - math
  - set-theory
  - probability-theory
  - combinatorics
---

## Statement
The **basic principle of counting** is a combinatorial, and ultimately set-theoretic, statement regarding the number of outcomes two events can have when taken together. This is particularly useful in calculating the probability of events with finite number of outcomes, which can often be reduced to counting those outcomes.

The principle states that if one event has $m$ possible outcomes and another has $n$ possible outcomes, then the events taken together have $mn$ possible outcomes.

<!--more-->

Formally, if $A$ is the set of all outcomes of the first event and $B$ the second:

$$A=\{a_1,a_2,\cdots,a_m\}\ \ \ \ \ B=\{b_1,b_2,\cdots,b_n\}$$

then the set of combined outcomes is just their [cartesian product](\cartesian-product) $A\times B$:

$$A\times B=\{(a,b)\mid a\in A\wedge b\in B\}=\left\{
\begin{matrix}
    (a_1,b_1), & (a_1,b_2), & \dots & (a_1,b_n), \\
    (a_2,b_1), & (a_2,b_2), & \dots & (a_2,b_n), \\
    \vdots & \vdots & \ddots & \vdots \\
    (a_m,b_1), & (a_m,b_2), & \dots & (a_m,b_n)
\end{matrix}\right\}$$

The basic principle, then, just reiterates that the [product of cardinalities](\cartesian-product#cardinal-multiplication) is equal to the cardinality of the cartesian product:

$$|A\times B|=|A||B|=mn$$

### Example
For example, consider rolling two dice, where the event of rolling a die is given by $D=\\{1,2,3,4,5,6\\}$. The set of outcomes for rolling two dice is given by $D\times D$. An example of an outcome is $(3,2)$ which corresponds to rolling a $3$ on the first die and a $2$ on the second. The basic principle tells us that the number of different possible dice rolls is given by:

<!-- Since these are independent events (the first roll doesn't affect the outcome of the second) -->

$$|D\times D|=|D||D|=6\cdot6=36$$

*Note here that $(3,2)$ is different from $(2,3)$. That is to say, order matters.*

## Generalization
This of course generalizes to not just two, but any number of events due to the properties of cardinal multiplication:

$$\left|\prod_{i=1}^nS_i\right|=|S_1\times S_2\times\cdots\times S_n|=|S_1||S_2|\cdots|S_n|=\prod_{i=1}^n|S_i|$$

It also applies to an infinite number of events as well as events with an infinite number of outcomes. For example:

$$\left|\prod_{i\in\mathbb N}\mathbb Z\right|=\prod_{i\in\mathbb N}\left|\mathbb Z\right|=\left|\mathbb Z^\mathbb N\right|=\aleph_0^{\aleph_0}=\mathfrak{c}$$

<!-- |\underbrace{\mathbb Z\times \mathbb Z\times\cdots}_{\aleph_0}|=|\mathbb Z||\mathbb Z|\cdots=\aleph_0\aleph_0\cdots=\aleph_0^{\aleph_0}=\mathfrak{c} -->

<!-- ### Independence of Outcomes
It is important to note that if the outcome of the first event affects the number of outcomes of the other events (implying they're not independent), the cartesian product wouldn't represent all possible outcomes as it would include impossible ones as well. An example might be if getting a 2 on the first roll precluded you from getting a 4 on the second roll. This would mean the outcome $(2,4)$ is not a possible event and $|D_1\times D_2|=36$ is $1$ too high. -->

## Without Explicit Sets
<!-- Note that this independence only matters when the *number* of outcomes changes. -->
Note that we only need to know the size, or *cardinality*, of the two sets in question to use the basic principle. For example, if we want to quantify the set of all two digit strings with no repeats, we have 10 choices of digits for the first digit and 9 choices for the second:

$$|\{(0,1),(2,3),(9,3),\cdots\}|=10\cdot 9=90$$

Notice that we cannot represent the above as a cartesian product of two sets (i.e. it doesn't have a [cartesian factorization](\cartesian-product#cartesian-factorization)) because the set of possible choices of the second element changes for every choice of the first element.

However, regardless of which digit is picked first, we know that the set of second choices will have cardinality $9$ despite not knowing what $9$ digits are in that set. As such, we can still use the basic principle.