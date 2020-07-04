---
header:
  overlay_image: /assets/images/math/set-theory-splash.png
title: Relations
date: 2019-03-17
excerpt: "Defining relations and key terminology related to them."
categories:
  - posts
tags: 
  - math
  - set-theory
---

Relations are mathematical objects used to encode $n$-way relationships between elements of the same or different sets (e.g. there is a two way relationship between $2$ and $5$ in that $2<5$). Some important types of relations include partial orders, equivalence relations, and functions.

<!-- Relations are some of the most fundamental objects to set theory and mathematics as a whole. They allow us to formalize the relationships between different mathematical objects and concepts in the broadest sense.  -->

<!-- Relations with certain properties can be further collected to form particular mathematical structures like fields, ordered sets, and vector spaces who themselves can be studied. -->

Some examples of relations include:
- $x\le y$ Less than or equal to
- $\mathbf v\perp\mathbf u$ Orthogonality
- $x^2$ Square function
- $n\mid m$ Divisibility

<!--more-->

<!-- We can call a predicate with $n\ge2$ free variables a **relationship** between those variables. That is, given a particular choice of $n$ variables, the relationship $P$ may or may not hold:

$$P(x_1,x_2,x_3,\cdots,x_n)$$

If we limit the domain of each variable $x_i$ in the predicate as belonging to some corresponding set $S_i$, we can define the solution set $G$ to the relationship $P$ as follows:

$$G=\{(x_1,x_2\cdots,x_n)\in S_1\times S_2\times\cdots\times S_n\mid P(x_1,x_2,\cdots,x_n)\}$$

We can now extend the idea of relationships to set theory by constructing a **relation** between those $n$ sets which will be characterized by the solution set $G$, commonly called its **graph**. -->


## Definition
An **$n$-ary relation** $R$ is an ordered pair of an $n$-ary [Cartesian product](\cartesian-product) $\prod_{i=1}^n$ and a subset of that product $G\text{:}$

$$R\equiv\left(\prod_{i=1}^nS_i,G\right)$$

The set $S_i$ is called the $i$th **domain** of $R$ and the subset $G$ is called the **graph** of $R$. We can always extract the domains of $R$ from the Cartesian product by [factoring](\cartesian-product#cartesian-factorization) them out.

<!-- Note that this implies that (for $n\gt1$) any $n$-ary relation can also be considered an $(n-1)$-ary relation. That said, there is always a maximum $n$ for which an $n$-ary relation can be considered (i.e. the number of prime Cartesian factors). -->

In terms of Cartesian factorization, the $i$th domain of an $n$-ary relation $R$ is given by $\operatorname{CF}_i^n(\pi_1(R))$
{:.notice--info}

When the domains of the relation are understood from context, it is common for people to simply identify the relation by its graph. This is analogous to identifying an algebraic structure with just its underlying set.

<!-- #### Indexed & Infinitary Relations
Note that, since we have already defined [indexed Cartesian products](\cartesian-product#indexed--infinitary-products), this definition of relations covers infinitary relations (i.e. relations with an infinite number of arguments). The arity of such a relation is, as in the finite case, the cardinality of the index set of the Cartesian product.

While first order logic doesn't support predicates with an infinite number of free variables, we can still salvage this connection by simply considering the variable to be the list as a whole rather than its infinite components.

$$P(x_1,x_2,\cdots)\rightarrow P(\{x_i\}_{i\in I})$$

*That said there are some logics, namely [infinitary logic](https://plato.stanford.edu/entries/logic-infinitary/), that allow for predicates with a countably infinite number of free variables.* -->

### Existence in ZFC
Because [Cartesian products exist](/cartesian-product#existence-in-zfc), invoking the axiom of subset tells us that their subsets exist too (i.e. graphs). This, combined with the [existence of $n$-tuples](/n-tuples#existence-in-zfc), is enough to conclude that relations must also exist.

### Simultaneity of Arity
Recall that any $n$-ary Cartesian product can be <a href="\cartesian-product#simultaneity-of-arity">simultaneously interpreted</a> as a $k$-ary product where $1\le k\le n$. Likewise, this means that an $n$-ary relation can be interpreted as a $k$-ary relation:

$$R=\left(\prod_{i=1}^nS_i,G\right)=\left(\prod_{i=1}^kU_i,G\right)$$

Where the $k$-ary product of domains is given by:

$$\prod_{i=1}^kU_i=\underbrace{\left(\prod^{n-k+1}_{i=1}S_i\right)}_{U_1}\times\underbrace{S_{n-k+2}}_{U_2}\times\cdots\times\underbrace{S_n}_{U_k}$$

<!-- #### Large Relations & Proper Classes

some solution sets are to big to be sets how to phrase that. generalize the reelation

predicate and free vairables but not bounded by some domain. -->

## Notation
Relations are very fundamental mathematical objects and thus have special notation associated to them. Below are common notations for denoting that $n$-elements are related by some relation, i.e. that a given tuple is in the graph $G$ of a relation $R$:

### $n$-ary Relations
Given an $n$-ary relation $R$, it is common to write the left-hand statement in place of the more formal right-hand one:

$$Rx_1x_2\cdots x_n \equiv (x_1,x_2,\cdots,x_n)\in G$$

### Binary Relations
While we could use $Rxy$ for binary relations as above, it is often more convenient to write:

$$xRy\equiv (x,y)\in G$$

This notation is ubiquitous, for example: $3\le5$, $ABC \cong ADC$, $\mathbf v\perp\mathbf u$, etc...
{:.notice--info}


## Empty, Universal, and Identity Relations
### Empty Relation
An $n$-ary **empty relation** is a relation whose graph is the empty set, i.e. any relation of the form:

$$E=\left(\prod_{i=1}^nS_i,\emptyset\right)$$

Thus no combination of elements of $E$'s domains satisfy it:

$$\left(\forall(x_1,x_2,\cdots,x_n)\in\prod_{i=1}^nS_i\right)\neg Ex_1x_2\cdots x_n$$

Note that if any one of the domains $S_i=\emptyset$, then the relation is necessarily an empty relation. This is because the [zero property of the Carteisan product](/cartesian-product#empty-set) means that one of the sets $S_i$ being empty forces the entire product to be empty along with, by extension, any subset of that product.

<!-- The corresponding relationship to such a relation is simply one that is never satisfied by any combination of elements $x_i$ from the domains $S_i$:

$$\left(\forall \{x_i\}_{i=1}^n\in \prod_{i=1}^nS_i\right)\ \neg P(x_1,x_2,x_3,\cdots,x_n)$$ -->

### Universal Relation
Opposite to an empty relation, a universal relation is one whose graph includes every element of the Cartesian product of its domains:

$$U=\left(\prod_{i=1}^nS_i,\prod_{i=1}^nS_i\right)$$

Thus every combination of elements of $U$'s domains satisfy it:

$$\left(\forall(x_1,x_2,\cdots,x_n)\in\prod_{i=1}^nS_i\right) Ux_1x_2\cdots x_n$$

### Identity Relation
An identity relation is a binary relation on a set where each element is only related to itself:

$$I=\left(S\times S,\{(x,x)\mid x\in S\}\right)$$

Thus the identity relation satisfies the following property:

$$\forall x,y\in S\ \left(xIy\iff x=y\right)$$

<!-- Unlike the empty and universal relations which can be defined for any Cartesian product, the identity relation can only be defined as a *relation on a set* (see below). -->

## Properties of Binary Relations
The most common type of relations are binary. This is in part due to the fact that many higher arity relations can be broken up into a collection of binary relations.

<!-- This is in part because many relations can be [*curried*](https://en.wikipedia.org/wiki/Currying) into several different binary relations -->

A binary relation on two different sets $A$ and $B$ is called **heterogenous** when $A\not=B$ and **homogenous** when $A=B$. Homogenous relations are also called **relations on a set**.

Below is a list of common classifications of binary relations based on what properties they satisfy.[^f1] In all the definitions below we will let $R=(A\times B,G)$ where $G\subseteq A\times B$:

### Uniqueness Properties

<details>
<summary><strong>Injective</strong></summary>
A relation is called injective if for all $b\in B$, the $a\in A$ is unique in the expression $aRb$. More formally, $R$ is injective if:

$$\forall a_1,a_2\in A, \forall b\in B \left(a_1Rb\wedge a_2Rb\implies a_1=a_2\right)$$

Because of this property, injective relations are also called <b>left-unique</b>.
<p></p>
</details>

<details>
<summary><strong>Functional</strong></summary>
A relation is functional if for all $a\in A$ on the left side, the $b\in B$ on the right is unique. Relations that fulfill this property are called <b>functions</b> and are said to have a unique output $b$ for a given input $a$. Formally this means:

$$\forall a\in A, \forall b_1,b_2\in B \left(aRb_1\wedge aRb_2\implies b_1=b_2\right)$$

Similar to injective relations, a functional relation is also called <b>right-unique</b>.
</details>

<!-- <details>
<summary><strong>One-to-One</strong></summary>
One-to-One functions are relations that are both functional and injective. These functions map every element in their domain to a unique element in the range. These are also called <b>injective functions</b> because being functional is implied in the classification 'function'.
</details> -->

### Totality Properties

<details>
<summary><strong>Left-Total</strong></summary>
A left-total relation means that for every element in $A$ there is at least one element in $B$ that it is related to:

$$(\forall a\in A,\exists b\in B)\ aRb$$

Note that all functions are automatically left-total, but not all left-total relations are functions.
<p></p>
</details>

<details>
<summary><strong>Surjective</strong></summary>
A relation is surjective if every element in $B$ is related to at least one element in $A$:

$$(\forall b\in B,\exists a\in A)\ aRb$$

Similar to left-total relations, surjective relations are also called <b>right-total</b>. When a function is both injective and surjective it forms a bijection.
</details>

### Homogenous Properties
The following properties only apply to homogenous relations, i.e. $A=B=X$.
<details>
<summary><strong>Reflexive and Irreflexive</strong></summary>
A relation is <b>reflexive</b> if all elements relate to themselves:

$$(\forall x\in X)\ xRx$$

Some example of this are the less than or equal to $\le$ and the divides $\mid$ relations. Relations that don't relate <i>any</i> element to themselves are called <b>irreflexive</b>:

$$(\forall x\in X)\ \neg(xRx)$$

An example of this is the $\lt$ relation.
<p></p>
</details>

<details>
<summary><strong>Symmetric</strong></summary>
A relation is symmetric if $xRy$ implies $yRx$ as well:

$$\forall x,y\in X \left(xRy \implies yRx\right)$$

Some examples of this include the proportionality $\propto$ of functions and similarity $\sim$ of geometric objects.
<p></p>
</details>

<details>
<summary><strong>Anti-Symmetric</strong></summary>
A relation is anti-symmetric if $xRy$ and $yRx$ imply $x=y$:

$$\forall x,y\in X \left(xRy\wedge yRx \implies x=y\right)$$

All partial orders satisfy this property, e.g. $\le$.
<p></p>
</details>

<details>
<summary><strong>Transitive</strong></summary>
A relation is transitive if $xRy$ and $yRz$ means $xRz$:

$$\forall x,y,z\in X \left(xRy \wedge yRz\implies xRz\right)$$

All partial orders and equivalence relations, like $\le$ and $\sim$, are transitive.
<p></p>
</details>

<details>
<summary><strong>Trichotomous</strong></summary>
A relation is trichotomus if for any two elements $x,y\in X$ only one of the following 3 options holds: $xRy$, $yRx$, or $x=y$. More formally:

$$(\forall x,y\in X)\ (xRy \oplus yRx \oplus x=y) \wedge \neg(xRy \wedge yRx \wedge x=y)$$

The most common example of this is as a property of the real numbers under the $\lt$ or $\gt$ relations. In other words, any real number is either greater than, lesser than, <i>xor</i> equal to any other number. All total orders must satisfy this property.
</details>

## Calculus of Relations
Below we include a collection of common transformations and operations on relations along with their associated notation and terminology.

<div class="notice--info">Note that the relational operations of union, subset, etc. mentioned below are not true unions, subsets, etc. as defined. Hence the $ * $ above their symbols. This is because we don't define relations as JUST their graphs but as an ordered pair including it, making the formal definition of these operations a little awkward. That said, when the context is clear, the $ * $ can be omitted.</div>

<details>
<summary><strong>Union and Intersection</strong></summary>
The union of two relations $R_1,R_2$ with the same domains $\prod S_i$, and corresponding graphs $G_1,G_2$, is the following relation:

$$R_1\cup^* R_2\equiv \left(\prod S_i,G_1\cup G_2\right)$$

The same goes for the intersection of two relations with the same domains:

$$R_1\cap^* R_2\equiv \left(\prod S_i,G_1\cap G_2\right)$$

And of course, we can generalize the relational union and intersection of to a finite number of relations with the same domains $n$:

$$\bigcup_{i=1}^n{\vphantom{\bigcup}}^* R_i\equiv\left(\prod S_i,\bigcup_{i=1}^n G_i\right)$$

$$\bigcap_{i=1}^n{\vphantom{\bigcup}}^* R_i\equiv\left(\prod S_i,\bigcap_{i=1}^n G_i\right)$$

Here are some examples:
<ul>
<li>$<\cup^* I=\le$ The union of less than and the identity relation is less than or equal to.</li>
<li>$\ge\cap^* >=>$ The intersection of greater than or equal to and greater than is greater than.</li>
<li>The union of "is father of" and "is mother of" gives "is parent of"</li>
</ul>
<p></p>
</details>

<details>
<summary><strong>Subrelations</strong></summary>
A <b>subrelation</b> of $R$ is a relation $R_\downarrow$ with the same domains and whose graph $G_\downarrow$ is a subset of $R$'s graph $G$:

$$R_\downarrow=\left(\prod S_i,G_\downarrow\right)$$

$$R_\downarrow\subseteq^* R\equiv G_\downarrow\subseteq G$$


Likewise, a <b>superrelation</b> of $R$ is a relation $R_\uparrow$ with the same domains and whose graph $G_\uparrow$ is a superset of $G$:

$$R_\uparrow=\left(\prod S_i,G_\uparrow\right)$$

$$R_\uparrow\supseteq^* R\equiv G_\uparrow\supseteq G$$
</details>

<details>
<summary><strong>Complement</strong></summary>
The complement of a relation $R$ is denoted $\not R$, and sometimes $\bar R$, and is the set of ordered pairs in $\prod S_i$ that are <i>not</i> in $G$:

$$\not R\equiv \left(\prod S_i,\prod S_i\setminus G\right)$$

Some interesting properties of the complement relation are:
<ul>
<li>$\bar{(\not R)}=R$, i.e. the complement of $\not R$ is $R$. Another way to phrase this is that the complement is an <i>involution</i></li>
<li>$R\cup^* \not R=U$, i.e. the union of a relation with its complement gives the universal relation.</li>
</ul>
<p></p>
Also note that, because $\not R$ contains all the pairs <i>not</i> in $R$, it represents it's logical negation:

$$\left(\forall(x_1,x_2,\cdots,x_n)\in\prod_{i=1}^nS_i\right) \neg Rx_1x_2\cdots x_n\iff\not Rx_1x_2\cdots x_n$$

It is this property of the complement relation that allows us to, for example, replace $\not>$ with $\le$ since they are complements of each other:

$$\neg(2>5)\equiv 2\not>5\equiv 2\le 5$$
</details>

<!-- <details>
<summary><strong>Logical Negation of a Relation</strong></summary>
Notice that negating a relation is equivalent to asserting its complement (assuming both elements being related are in the universal set). Put more formally, if $a\in A$ and $b\in B$:

$$\neg(aRb)\equiv aR^\complement b$$

It is this negating property that allows us to replace statements like $\neg(a\le b)$ with  $a\gt b$.
</details> -->

<details>
<summary><strong>Converse</strong></summary>
<p markdown="1">The converse of a binary relation $R$ is denoted $R^\top$ and is simply the reverse of $R$. In other words, if $(x,y)$ is in a relation's graph, then $(y,x)$ is in its converse's graph. This means the domains must be reversed as well. Formally, for a binary relation $R$:[^f2]</p>

$$R=\left(A\times B, G\right)$$

It's converse is given by:

$$R^\top=\left(B\times A, G^\top\right)$$

$$G^\top=\{(b,a)\in B\times A\mid (a,b)\in G\}$$

Some interesting properties of conversion are that it respects composition:

$$(R\circ L)^\top=L^\top\circ R^\top$$

and its an involution:

$$(R^\top)^\top=R$$

For example, the converse of the greater than relation $\ge^\top$ is $\le$. Similarly, the converse of the relation "is a child of" is "is a parent of".

<p></p>
</details>

<details>
<summary><strong>Composition</strong></summary>
<p markdown="1">The composition of two binary relations is the result of applying one after the other. If the first relation is $R_1$, with domain $A\times B$, and the second $R_2$, with domain $B\times C$, their composition is a new relation denoted $R_2\circ R_1$[^f3]:</p>

$$R_2\circ R_1=\left(A\times C, G\right)$$

where the graph $G$ is:

$$G=\left\{(a,c)\in A\times C\mid\exists b:(a,b)\in G_1\wedge(b,c)\in G_2\right\}$$

In other words, for $a\in A,c\in C$:

$$a(R_2\circ R_1)c\equiv \left(\exists b\in B\right)aR_1bR_2c$$

Note that relation composition is associative:

$$X\circ (Y\circ Z)=(X\circ Y)\circ Z$$

An intuitive example of relational composition can be found in kinship relations. The composition "is father of" $\circ$ "is parent of" returns the new relation "is grandfather of".
<p></p>
</details>

<details>
<summary><strong>Inverse</strong></summary>
There are some binary relations $R$ for which there exists a relation $X$ such that:

$$X\circ R=I$$

These relations are called <b>left-invertible</b>. Similarly, when there exists a relation $Y$ such that:

$$R\circ Y=I$$

the relation is called <b>right-invertible</b>. When $R$ is both left and right invertible, it is simply called <b>invertible</b>. And when a relation is invertible, its left and right inverses and converse are all equivalent to the inverse:

$$R^{-1}=R^\top=X=Y$$

And so, we can denote the unique inverse of $R$ as simply $R^{-1}$. As an example, the composition "is child of" $\circ$ "is parent of" returns "is you" (i.e. the identity relation). As such, they are inverses of each other.
<p></p>
</details>

<details>
<summary><strong>Closures and Reductions</strong></summary>
A <b>closure</b> of some relation $R$ is the smallest superrelation of $R$ that satisfies some property.<p></p>

For example the <i>reflexive</i> closure of $R$, denoted $R^=$, is the smallest superrelation of $R$ that is reflexive.<p></p>

A <b>reduction</b> is very similar except it removes the least number of elements from $R$ as necessary in order to have the new relations satisfy some property.<p></p>

For example the <i>irreflexive</i> reduction of $R$, denoted $R^{\not=}$, is the largest subrelation of $R$ that is irreflexive.
</details>


<!-- footnotes -->
[^f1]: A combinatorial side note: the number of binary relations on a set of $n$ elements is given by $2^{n^2}$, which is sequence [A002416](https://oeis.org/A002416) on the OEIS. Further, the number of binary relations on an $n$ element set that satisfy the other listed properties can also be found on the OEIS, though not all have closed formulae.

[^f2]: All finite relations can be represented by a matrix (or a graph which in turn can be represented by an adjacency matrix). It is interesting to note, then, that the converse is analogous to the matrix transpose, hence the notation.

[^f3]: You'll notice that the order of the relations in the notation seems reversed, this is no accident however. The reason for this is that when we define functional composition, it will be just a special case of relational composition and the notation will stay the same. Thus, to make reasoning about relational compositions easier, it may help to simply switch their order in your mind. Also note that composition is analogous to matrix multiplication, which the notation corroborates.