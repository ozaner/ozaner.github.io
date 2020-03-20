---
title: Superfactorial and Hyperfactorial
date: 2018-04-18
excerpt: "A brief introduction to two interesting variations of the factorial function: the superfactorial and hyperfactorial."
categories:
  - posts
  - notes
tags: 
  - math
  - analysis
---
## Variants of Factorial
### Factorial
Recall that the factorial function $n!$ is the product of the first $n$ [natural numbers](/natural-numbers):

$$n!=\prod_{k=1}^{n}k=1\times2\times3\times\cdots\times n$$

While there is much to discuss about the factorial function, this post concerns itself with two particular variations of the factorial. Namely the superfactorial and the hyperfactorial.

### Superfactorial
We denote the superfactorial of $n$ as $n{$}$. It is defined[^f1] as the product of the first $n$ factorials:

$$n$=\prod_{k=1}^{n}k!=1!\times2!\times3!\times\cdots\times n!$$

### Hyperfactorial
The hyperfactorial of $n$ is denoted $H(n)$ and is defined as:

$$H(n)=\prod_{k=1}^{n}k^k=1^1\times2^2\times3^3\times\cdots\times n^n$$

## Calculator
Below is a calculator for computing these factorials. Note that it accepts non-integer arguments as well, in which case it uses the generalizations discussed in the next section.

<script type="text/javascript" id="WolframAlphaScriptb7ab1f3f563599d85d9d08eade4d504c" src="//www.wolframalpha.com/widget/widget.jsp?id=b7ab1f3f563599d85d9d08eade4d504c"></script>

## Domains & Generalizations
The domain of these three functions is the natural numbers, which includes $0$. As such, it's important to note that $0!,0{$}$, and $H(0)$ all equal $1$ by their above definitions because they are [empty products](https://en.wikipedia.org/wiki/Empty_product), i.e. a product of 0 factors.

On another note, you might recall that the factorial function can be generalized to the complex plane via [analytic continuation](https://en.wikipedia.org/wiki/Analytic_continuation), resulting in the [gamma function](https://en.wikipedia.org/wiki/Gamma_function) $\Gamma(z)$.

Like the factorial, the superfactorial and hyperfactorial can also be generalized to the complex numbers, resulting in the [Barnes G-function](https://en.wikipedia.org/wiki/Barnes_G-function) $G(z)$, and [K-function](https://en.wikipedia.org/wiki/K-function) $K(z)$ respectively.

We can summarize this information with the following table:

|Notation|Name|Definition|OEIS Entry|Analytic Continuation|
|---|---|---|---|
|$n!$|Factorial|$\prod_{k=1}^{n}k$|[A000142](https://oeis.org/A000142)|$\Gamma(n+1)$ gamma function
|$n{$}$|Superfactorial|$\prod_{k=1}^{n}k!$|[A000178](https://oeis.org/A000178)|$G(n+2)$ Barnes G-function
|$H(n)$|Hyperfactorial|$\prod_{k=1}^{n}k^k$|[A002109](https://oeis.org/A002109)|$K(n+1)$ K-function|

## Factorial Identity
We can relate all three of the discussed factorial variants with the following identity:

$$n{$}\cdot H(n)=n!^{n+1}$$

<details class="bordered">
<summary><strong>Proof</strong></summary>

We can prove the above statement, which we'll call $P(n)$, by induction:

$$P(n)\equiv n{$}\cdot H(n)=n!^{n+1}$$

First we multiply both sides of the equation by $(n+1)!(n+1)^{n+1}$:

$$\begin{align}n{$}\cdot H(n)&=n!^{n+1}\\
(n+1)!(n+1)^{n+1}& \ \ \ \ \ (n+1)!(n+1)^{n+1}
\end{align}$$

Now let's simplify the left hand side first. Notice that $n{\$}\cdot(n+1)!=(n+1){\$}$ and that $H(n)\cdot(n+1)^{n+1}=H(n+1)$. From this the left hand side simply becomes:

$$(n+1){$}\cdot H(n+1)$$

Now let's deal with right hand side. Notice that the expression can be rewritten as:

$$\begin{align}
n!^{n+1} \color{green}{(n+1)!}(n+1)^{n+1}&=n!^{n+1}\color{green}{n!(n+1)}(n+1)^{n+1}\\
&=n!^{n+2}(n+1)^{n+2}\\
&=(n+1)!^{n+2}\\
\end{align}$$

Putting the right and left hand sides back together we can see that we just proved $P(n+1)$:

$$P(n+1)\equiv(n+1){$}\cdot H(n+1)=(n+1)!^{n+2}$$

However $P(n+1)$ was proved under the assumption that $P(n)$ was true. Thus:

$$P(n)\implies P(n+1)$$

But, notice that $P(0)$ is true:

$$\begin{align}
P(0)&\equiv 0{$}\cdot H(0)=(0!)^{0+1}&\\
&\equiv1\cdot1=1&\text{(empty product is $1$)}\\
&\equiv T&
\end{align}$$

We thus have by induction:

$$\begin{align}
&P(n)\implies P(n+1)\\
&P(0)\\
\therefore\ &\hline{\forall n\in \mathbb{N},\ P(n)}\\
\end{align}$$
</details>
<p></p>

This identity also holds more generally for the analytic continuations of these functions, although we'll refrain from trying to prove this here:

$$G(n+1)K(n)=\Gamma(n)^{n}$$

<!-- footer -->

[^f1]: While this is the most common usage of the term *superfactorial*, this definition, created by Neil J.A. Sloane and Simon Plouffe (co-authors of the OEIS), isn't the only one. Another definition exists: $n{\$}=n!\uparrow\uparrow n!$ where the double arrows denote [tetration](https://en.wikipedia.org/wiki/Tetration).
