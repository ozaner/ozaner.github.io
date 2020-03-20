---
header:
  overlay_image: /assets/images/math/probability-splash.jpg
title: Intro Probability Notes Ch. 3
date: 2019-01-21
excerpt: "My notes on Ross' *A First Course in Probability*. Chapter 3 - Conditional Probability and Independence"
permalink: /prob-notes-3/
categories:
  - posts
tags: 
  - math
  - probability-theory
---

## Conditional Probabilities
Conditional probabilities arise when we have partial information about an experiment. That is, given that an event $F$ has occurred, the probability that an event $E$ occurs is denoted and given by:

$$P(E|F)=\frac{P(EF)}{P(F)}$$

Note that the conditional probability is not defined when $P(F)=0$, which should make sense considering an event that cannot happen cannot possibly be a precondition for another.

<details class="bordered">
<summary><strong>Example</strong></summary>
For example, suppose our sample space $S$ is the set of all outcomes of rolling two fair dice:

$$S=[1..6]\times[1..6]$$

What is the probability that the sum of the dice is 8, given that the first die we rolled was a 3? Here, event $E$ is rolling a 3 on the first die and event $F$ is getting a pair that adds to 8:

$$\begin{align*}
E&=\{(3,1),(3,2),(3,3),(3,4),(3,5),(3,6)\}\\
F&=\{(2,6),(3,5),(4,4),(5,3),(6,2)\}\\
EF&=\{(3,5)\}
\end{align*}$$

Remember that each dice roll is equally likely (i.e. this is a uniform distribution) and so the probabilities of the relevant events are:

$$\begin{align*}
P(F)&=\frac{|F|}{|S|}=\frac{5}{36}\\
P(EF)&=\frac{|EF|}{|S|}=\frac{1}{36}
\end{align*}$$

This leaves us with:

$$P(E|F)=\frac{P(EF)}{P(F)}=\frac{1}{5}$$
</details>

Note that since the sample space itself always has a probability of $1$, it serves as a sort of identity for the conditional probability of any event:

$$P(E|\Omega)=\frac{P(E\Omega)}{P(\Omega)}=P(E)$$

<!-- Conversely, the conditional probability formula is undefined for events having $0$ probability:

$$P(F)=0\implies P(E|F)=\frac{P(EF)}{P(F)}=\frac{0}{0}$$

This jives with our intuition as it doesn't make sense to consider the probability of an event $E$ under the precondition that an impossible event $F$ occurred. -->

## Multiplication Rule
Note that we can rearrange the conditional probability formula like so:

$$P(EF)=P(F)P(E|F)$$

giving us a formula for the probability of the intersection of events.
We can extend this formula to the intersection of multiple events like so:

$$P(E_1E_2E_3\cdots E_n)=P(E_1)P(E_2|E_1)P(E_3|E_1E_2)\cdots P(E_n|E_1E_2\cdots E_{n-1})$$

Or more succinctly:

$$P\left(\bigcap_{i=1}^n E_i\right)=\prod_{i=1}^nP\left(E_i\mid\bigcap_{j=1}^{i-1} E_i\right)$$

## Law of Total Probability
The law of total probability states that for any countable partition $(F_i)_{i\in I}$ of the sample space $\Omega$, an event $E$ satisfies:

$$\begin{align*}
P(E)&=\sum_{i\in I}P(EF_i)\\
&=P(EF_1)+P(EF_2)\cdots
\end{align*}$$

We can think of the sum as a weighted average of the probability of $E$ which should, if the weights sum to 1 (i.e. partition $\Omega$), equal that same probability. Also, note that the multiplication rule allows us to phrase this law as:

$$\begin{align*}
P(E)&=\sum_{i\in I}P(E|F_i)P(F_i)\\
&=P(E|F_1)P(F_1)+P(E|F_2)P(F_2)\cdots
\end{align*}$$

*Where $i$ such that $P(F_i)=0$ are omitted from the sum, to avoid the undefined conditional probability.*

A particular case of this law is when the partition consists of two sets, this necessitates that the sets be complements of each other in order to partition the whole sample space:

$$\begin{align*}
P(E)&=P(E|F)P(F)+P(E|F^\complement)P(F^\complement)\\
&=P(E|F)P(F)+P(E|F^\complement)(1-P(F))
\end{align*}$$

## Bayes' Theorem
Bayes' Theorem is the simple observation that for any two events $E$ and $F$:

$$P(F|E)=\frac{P(E|F)P(F)}{P(E)}$$

<!-- We can remove the discontinuity when $P(F)=0$ by writing it like so:

$$P(E|F)P(F)=P(F|E)P(E)$$ -->

<details class="bordered">
<summary><strong>Proof</strong></summary>
$$\begin{align*}
P(FE)&=P(F|E)P(E)\tag{Multiplication Rule}\\
P(E|F)&=\frac{P(EF)}{P(F)}\tag{Def. of conditional prob.}\\
&=\frac{P(FE)}{P(F)}\tag{Commutativity of intersection}\\
&=\frac{P(F|E)P(E)}{P(F)}\tag{substitution}\\
\end{align*}$$
</details>

Using the law of total probability, we can generalize Bayes' Theorem. Given some countable partition $(F_i)_{i\in I}$ of the sample space, we can replace the $P(E)$ in the denominator with:

$$P(F_i|E)=\frac{P(F_i|E)P(F_i)}{\sum_{i\in I}P(E|F_i)P(F_i)}$$

Bayes Theorem is also useful, and is often phrased, in the following form where the law of total probability is used in the 2 set partition case:

$$P(F|E)=\frac{P(E|F)P(F)}{P(E|F)P(F)+P(E|F^\complement)P(F^\complement)}$$

## Odds of an Event
When we use the phrase "The odds $E$ happens" we mean how much more times likely it is that $E$ occurs rather than doesn't occur (i.e. $E^\complement$ occurs):

$$\operatorname{odds}(E)=\frac{P(E)}{P(E^\complement)}=\frac{P(E)}{1-P(E)}$$

We can use Bayes' Theorem to describe how the odds of a hypothesis $H$ are affected by the introduction of some new evidence $E$:

$$\begin{align*}
\operatorname{odds}(H|E)&=\frac{P(H|E)}{P(H|E^\complement)}&\text{(def. of odds)}\\
&=\frac{P(E|H)P(H)/P(E)}{P(E|H^\complement)P(H^\complement)/P(E)}&\text{(Bayes' Theorem)}\\
&=\frac{P(E|H)P(H)}{P(E|H^\complement)P(H^\complement)}&\\
&=\operatorname{odds}(H)\frac{P(E|H)}{P(E|H^\complement)}&\text{(def. of odds)}
\end{align*}$$

Or in words, the odds that a hypothesis $H$ is true in light of some new evidence $E$ is simply given by the old odds of the hypothesis times the probability that the evidence ocurred given the hypothesis is true over the probability that it occurred given the hypothesis was false.

## Independent Events
When the probability of an event $E$ does not change when another event $F$ is known to have occurred, the events are called **independent**. They are called **dependent** otherwise. In other words, the event $E$ is independent of $F$ when:

$$P(E|F)=P(F)$$

Note that from the definition of conditional probability, this tells us that for two independent events $E$ and $F$:

$$P(EF)=P(E)P(F)$$

Note that the above equation is a more common definition of independence than the first one given. Also note that if $E$ and $F$ are independent then so too are their complements:

$$P(EF)=P(E)P(F)\rightarrow P(EF^\complement)=P(E)P(F^\complement)$$

We can generalize independence to any set of events $A$, even infinite, in the following way:

$$(\forall S\subseteq A)\ |S|\lt\aleph_0\rightarrow P\left(\bigcap_{E\in S} E\right)=\prod_{E\in S} P\left(E\right)$$

Or in other words, a set of events is mutually independent iff the intersection of every finite subset of that set has the same probability of the product of those set's probabilities taken separately.
