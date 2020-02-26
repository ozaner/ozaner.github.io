<b>Ozaner Hansha</b>
September 17th, 2018

## Intro to Math Reasoning HW 1
### Problem 1
Let's first phrase the problem in terms of sets. The set of all letters in the alphabet is denoted $\Omega=\{A,B,C,\cdots,Z\}$ and can be constructed in any way that doesn't collide with the set $\mathbb{Z}$. The set of consonants can be defined as $\Psi=\{\omega\in\Omega\mid\omega\not=A,E,I,O,U\}$ or in English: "the set of all letters that are not vowels."

Because each tile has both a letter and a positive integer associated with it, we can think of each tile as an ordered pair from the cartesian product of $\Omega$ and the nonnegative integers $\mathbb{Z}^+$. There are $50$ tiles so we can think of the problem as a function whose domain is the integer interval $[1..50]$:

$$T:[1..50]\to\Omega\times\mathbb{Z}^+$$

Where $T(n)$ is the $n$th tile in the finite sequence. I'll also refer to $T(n)$ as $(x_n,y_n)$ where $x_n\in\Omega$ and $y_n\in\mathbb{Z}^+$, for convenience.

Now, the statement we are trying to prove, "is it true that every tile that has a consonant on one side has an even number on the other side?" can be stated as:

$$\forall (x_n,y_n)\in T,\ x_n\in\Psi\rightarrow \left(y_n\equiv 0 \bmod 2\right)$$

To prove this statement we have to be sure that every tile with a consonant has an even number on the other side. This means we must check every tile that has a consonant face up (to see if there is an even number on the other side), and every tile that has a number face up (to see if there was a consonant on the other side). The only tiles we don't need to check are those with vowels face up. Their status is irrelevant to the proposition.

Conversely, to *disprove* the statement all we need to do is come up with a single example of a consonant tile that has an odd number on the back. Formally:

$$\exists (x_n,y_n)\in T,\ x_n\in\Psi\wedge \left(y_n\equiv 1 \bmod 2\right)$$

So, assuming either outcome is equally as likely (a big assumption), our best bet is to pick up tiles with consonants on face up and see if they have an odd number on the back. If they do then we are done and receive $200-(number of tries), if not we keep going.

There is a point where we should no longer continue to check. This is where the potential gain for losing outweighs the potential for winning. So if the potential gain after $n$ tile checks is $50-n$ and the potential loss is $$200-n$ we can calculate at what $n$ we should stop checking given the probability that all $n$ checks were positive:

$$\left(\frac{n}{50}\right)\left(50-n\right)\ge\left(1-\frac{n}{50}\right)\left(200-n\right)$$

If the above holds then keep checking, if not guess. And if you have an example where the statement doesn't hold before this point (i.e $x$ is a consonant and $y$ is odd) then stop there and say so.

### Problem 2
*My first instinct might be to simply enumerate all possible times, but I'm sure there is a way to attack this via graph theory. But even drawing out that graph with each possible configuration of people seems tedious, much less applying some  minimization algorithm to get form state A (all at the beginning) to state B (all at the end).*

Instead I'm going to just talk my way through it. First B and T would go. This will take $10$ minutes but any trip with T involved would take 10 minutes so best to get him out of the way considering he doesn't have to make any more trips past this point.

Next B, of course, would travel back as T would take too long. Now B takes A which takes $5$ minutes. Then B travels back and then takes C back which takes $2$ minutes. Over all it takes $10+5+2+1+1=19$ minutes (the 1's are from B's trips back).

Notice that B could've taken anybody back an each trip, all that was important is that B was the one coming back as B had the smallest travel time. This meant we could minimize the times on the trips back. This choice also doesn't hurt the times of the two person trips as the smaller travel times are overshadowed by the slower ones. As such, B's travel time would've been wasted if he was not the one making the solo trips.

### Problem 3
<!-- I think this situation is similar to the bubble sort algorithm. However the added benefit that the players can choose to pair up with whoever they want (at each iteration) is equivalent to this being the best case performance of bubble sort (it is as if the elements were in the optimal ordering). And so the best case performance is just 16 -->

At first I thought this was equivalent to the bubble sort algorithm but I realized that the fact that the list (or people in this case) could be rearranged at every iteration made it a bit different.

Not sure...

### Problem 4
The function $g:A\to B$ is one-to-one ($g(x)=g(y)\rightarrow x=y$).
#### Part a
Prove that for any two functions $h_1,h_2:B\to C$ that $g\circ h_1=g\circ h_2\rightarrow h_1=h_2$. Or, in other words, that injective functions are cancellative under function composition.

This can be shown via the simple equality:

$$\begin{align}
g\circ h_1&=g\circ h_2\\
g^{-1}\circ\left(g\circ h_1\right)&=g^{-1}\circ\left(g\circ h_2\right)\tag{$g^{-1}$ both sides}\\
\left(g^{-1}\circ g\right)\circ h_1&=\left(g^{-1}\circ g\right)\circ h_2\tag{Associativity prop.}\\
I\circ h_1&=I\circ h_2\tag{Inverse prop.}\\
h_1&=h_2\tag{Identity prop.}\\
\end{align}$$

We've shown that $h_1=h_2$ assuming that $g$ has an inverse function and that function composition respects the associative property.

*The fact that the inverse of a function composed with itself is the identity function is usually the definition of the inverse function so we don't need to prove that or the existence of an identity function.*

$g$ must have an inverse function $g^{-1}:B\to A$ because it is injective. That is to say, for every element in the range of $g$ there is a single element in the domain that it corresponds to. We can even define the new function as such:

$$g^{-1}=\{(x,y)\in B\times A\mid g(y)=x\}$$

Now of course the above is certainly a relation, but we haven't proved it is a function. But this is a simple consequence of the function being injective. Suppose there were two $y_1\not=y_2$ such that $g^{-1}(y_1)=x=g^{-1}(y_2)$:

$$\begin{align}
y_1&\not=y_2\tag{given}\\
g^{-1}(y_1)=x&\wedge g^{-1}(y_2)=x\tag{given}\\
g(x)=y_1&\wedge g(x)=y_2\tag{def. of $g^{-1}$}\\
y_1&=y_2\\
\end{align}$$

This is a contradiction and thus our assumption that $y_1$ and $y_2$ were distinct was false.

Now that we have shown that $g^{-1}$ exists, we must show that function composition is associative. Given three functions $A,B,C$ whose domains and ranges all agree, we can ask the question:

$$(C\circ B)\circ A\stackrel{?}{=}C\circ(B\circ A)$$

Indeed it does and we can show it via this simple chain of identities:

$$C\circ(B\circ A)(x)=C(B\circ A(x))=
C(B(A(x))=C\circ B(A(x))=(C\circ B)\circ A(x)$$

#### Part b
Prove that for any two functions $f_1,f_2:B\to C$ that $f_1\circ g=f_2\circ g\rightarrow f_1=f_2$. This statement is actually false in general.

Remember that we proved in part a that statements like this are true, only if $f_1$ and $f_2$ have inverse functions. However, since $f_1$ and $f_2$ are just generic functions that do not have to be injective, it is possible that they do not have functional inverses. If that is the case we cannot conclude that
$f_1\circ g=f_2\circ g\rightarrow f_1=f_2$. An example of a function without an inverse function is $f(x)=x^2$. This function has two inputs that correspond to the same output (except for 0).
### Problem 5
Prove that for every $n\in\mathbb{Z}^+$ there is a polynomial $p(x)$ with coefficients from this set $\{-1,0,1\}$ such that $n=p(3)$.

$$\left(\forall n\in\mathbb{Z}^+\right)\left(k_j \in\{-1,0,1\}\right)\sum_{j=0}^{m\in\mathbb{N}}k_j3^j=n$$

Not sure...

### Problem 6
$S\subseteq\mathbb{R}^+$ is an $\alpha$-narrow set  meaning:
$$\left(\forall x,y\in S\right)x-y\le\alpha$$

Show that this implies that there is a subset of $S$ that is $\beta$-narrow for any positive real $\beta$:
$$\left(\exists T\subseteq S\right)\left(\forall \beta\in\mathbb{R}^+\right)\left(\forall x,y\right)x-y\le\beta$$

<!-- First notice that because $S$ is $\alpha$-narrow, there is no subset it has no subset that is an interval (other than a trivial interval of one element). This is because there is a minimum spacing between any two elements of $S$ meaning that, for example, a number $\alpha/2$ away from an element does not exist in $S$.

If $S$ is infinite and yet no subset of it is an interval, this means that $S$ must have no upper bound (its elements explode to infinity) as that is the only other 'source' of infinity a subset of the positive reals could leverage. -->

<!-- Notice that because there is a maximum spacing between the elements of $S$ that it must be the subset of an interval whose length is at most $\alpha$. -->

We can break the statement into two cases: one where $\beta\ge\alpha$ and one where $\beta\lt\alpha$. This is because either:

$$\begin{align}
&\ \beta\ge\alpha\vee\neg\left(\beta\ge\alpha\right)\tag{law of excluded middle}\\
\equiv&\ \beta\ge\alpha\vee\beta\lt\alpha\tag{complement of $\ge$}\\
\end{align}$$

And so to prove this for any positive real $\beta$, it is sufficient to prove it for any $\beta$ greater or equal to $\alpha$ and any smaller.

For the first case it is trivial that there is a subset of $S$ that is $\beta$-narrow as $S$ itself is $\beta$-narrow. This is because:

$$\begin{align}
x-y\le\alpha\\
\alpha\le\beta\\
\hline
x-y\le\beta\tag{transitive property of $\le$}\\
\end{align}$$

So now we look at the $\beta\lt\alpha$ case. Notice that because there is a maximum spacing between the elements of $S$ that it must be the subset of an interval whose length is at most $\alpha$. Also notice that while there may be no subset of $S$ that is an interval, there must be an infinite subset of numbers in $S$ that are an arbitrarily small distance form each other.

This must be true as the only way for a subset of the reals to have an infinite size is to either be unbounded (have elements of an arbitrarily large size) and/or have elements that lie arbitrarily close to each other. Because $S$ is indeed bounded due to it being narrow, it must contain a set of elements that are as small as needed.

They are not necessarily *exactly* $\beta$ apart (they could all be rational numbers while $\beta$ could be any real) but there are always $2$ elements in $S$ that are less than $\beta$ apart. So simply take the subset of $S$ that contains two of those elements and you've got a $\beta$-narrow set.
