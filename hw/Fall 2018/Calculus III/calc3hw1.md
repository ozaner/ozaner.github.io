<b>Ozaner Hansha</b>
September 17th, 2018<br>

## Honors Calculus III HW 1
### Exercise 1.2
$\mathbf a:=(5,2)\ \ \mathbf b:=(2,-1)\ \ \mathbf c:=(1,1)$

#### Part 1
Express $\mathbf a$ as a linear combination of $\mathbf b$ and $\mathbf c$:

$$\begin{align}
\mathbf a&=s\mathbf b+t\mathbf c\\
(5,2)&=s(2,-1)+t(1,1)\\
&=(2s,-s)+(t,t)\\
&=(2s+t,t-s)
\end{align}$$

As the components of the vectors are independent under addition, this implies the following two scalar equations:

$$\begin{align}
2s+t&=5\tag{1st Component}\\
t-s&=2\tag{2nd Component}
\end{align}$$

Which can then be solved via some simple algebraic manipulations:

$$\begin{align}
2s+t&=5 \\
+\ \ 2(t-s&=2)\\
\hline
3t&=9\\
\rightarrow t&=3
\end{align}$$

Plugging this back in the first equation we find that:

$$\begin{align}
2s+3=5\rightarrow s=1
\end{align}$$

And so $\mathbf a$ can be written as the following linear combination:

$$\mathbf a=\mathbf b+3\mathbf c\tag*{$\square$}$$

#### Part 2
Express $\mathbf b$ as a linear combination of $\mathbf a$ and $\mathbf c$.

We know the following is true from **Part 1**:

$$\mathbf a=\mathbf b+3\mathbf c$$

Subtracting $-3\mathbf c$ from both sides (which is valid as all vectors have an additive inverse) we see that we are done:

$$\mathbf b=\mathbf a-3\mathbf c\tag*{$\square$}$$

#### Part 3
Express $\mathbf c$ as a linear combination of $\mathbf a$ and $\mathbf b$.

Again, we can leverage a previous result to prove the above. Here I use **Part 1** once more:

$$\begin{align}
&\ \mathbf a=\mathbf b+3\mathbf c \\
\rightarrow&\ 3\mathbf c=\mathbf a-\mathbf b \\
\rightarrow&\ \mathbf c=\frac{1}{3}\mathbf a-\frac{1}{3}\mathbf b \tag*{$\square$}

\end{align}$$

### Exercise 1.4
$\mathbf x:=(4,7,-4,1,2,-2)\ \ \mathbf y:=(2,1,2,2,-1,-1)$

#### Part 1
Compute $\|\mathbf x\|$ where $\operatorname{dim}(\mathbf x)=6$:

$$\|\mathbf x\|=\sqrt{\mathbf x\cdot \mathbf x}=\sqrt{\sum_{i=1}^{6}x_i^2}\\
=\sqrt{4^2+7^2+(-4)^2+1^2+2^2+(-2)^2}=3\sqrt{10}\approx 9.487$$

#### Part 2
Compute $\|\mathbf y\|$ where $\operatorname{dim}(\mathbf y)=6$:

$$\|\mathbf y\|=\sqrt{\mathbf y\cdot \mathbf y}=\sqrt{\sum_{i=1}^{6}y_i^2}\\
=\sqrt{2^2+1^2+2^2+2^2+(-1)^2+(-1)^2}=\sqrt{15}\approx 3.872$$

#### Part 3
Compute the angle $\theta$ between $\mathbf x$ and $\mathbf y$.

First we compute the dot product between $\mathbf x$ and $\mathbf y$:

$$\mathbf x\cdot \mathbf y=\sum_{i=1}^{6}x_iy_i\\=4(2)+7(1)-4(2)+1(2)+2(-1)-2(-1)=9$$

Now, given the geometric definition of the dot product:

$$\mathbf x\cdot \mathbf y=\|x\|\|y\|\cos \theta$$

We can plug in the value for $\mathbf x\cdot \mathbf y$ we found above along with the values of $\|x\|$ and $\|y\|$ we found in **Part 1** and **Part 2** respectively:

$$\begin{align}
9&=3\sqrt{10}\cdot \sqrt{15}\cos \theta\\
&=15\sqrt{6}\cos \theta\\
\rightarrow 3&=5\sqrt{6}\cos \theta
\rightarrow \frac{\sqrt 6}{10}=\cos \theta\\
\end{align}$$

Now we can simply take the $\cos^{-1}$ of both sides to solve for $\theta$:

$$\begin{align}
\cos^{-1}\cos \theta&=\cos^{-1}\frac{\sqrt 6}{10}\\
\theta&\approx 1.3233\tag*{$\square$}
\end{align}$$

### Exercise 1.6
$\mathbf x:=(-5,2,5)\ \ \mathbf y:=(1,2,1)$

Is the angle $\theta$ between $\mathbf x$ and $\mathbf y$ acute or obtuse?

We first need to compute $\|x\|, \|y\|,$ and $\mathbf x\cdot \mathbf y$:

$$\begin{align}
\|x\|&=\sqrt{(-5)^2+2^2+5^2}&&=3\sqrt 6\\
\|y\|&=\sqrt{1^2+2^2+1^2}&&=\sqrt 6\\
\mathbf x \cdot \mathbf y&=-5(1)+2(2)+5(1)&&=4\\
\end{align}$$

Now we can plug these into the formula for $\cos \theta$:

$$\begin{align}
\cos \theta&=\frac{\mathbf x\cdot\mathbf y}{\|x\|\|y\|}\\
&=\frac{4}{3\sqrt 6\cdot \sqrt 6}=\frac{2}{9}
\end{align}$$

Now we can get the angle by taking the $\cos^{-1}$ of both sides:

$$\begin{align}
\cos^{-1}\cos \theta&=\cos^{-1}\frac{2}{9}\\
\theta&\approx 1.3467\\
\end{align}$$

An acute angle is any element of the interval $(0,\frac{\pi}{2})$ and an obtuse angle is any element of $(\frac{\pi}{2},\pi)$. Notice that $\frac{\pi}{2}\approx 1.571\gt 1.347\approx\theta$ and thus the angle between $\mathbf x$ and $\mathbf y$ is acute. $\tag*{\(\square\)}$

### Exercise 1.8
Prove that for any 3 vectors $\mathbf a,\mathbf b,\mathbf c\in\mathbb{R^3}$ where $\mathbf a\not=\mathbf0$, that $\mathbf b=\mathbf c$ iff $\mathbf a\cdot \mathbf b=\mathbf a\cdot \mathbf c$ and $\mathbf a\times \mathbf b=\mathbf a\times \mathbf c$

First we use the distributive rules of the dot and cross product, respectively, to establish the following equivalent statements:

$$\begin{align}
\mathbf a\cdot \mathbf b=\mathbf a\cdot \mathbf c&\iff \mathbf a\cdot \mathbf b-\mathbf a\cdot \mathbf c=0\\&\iff\mathbf a\cdot(\mathbf b-\mathbf c)=0\tag{1}\\
\mathbf a\times \mathbf b=\mathbf a\times \mathbf c&\iff \mathbf a\times \mathbf b-\mathbf a\times \mathbf c=\mathbf 0\\&\iff\mathbf a\times(\mathbf b-\mathbf c)=\mathbf 0\tag{2}\\
\end{align}$$

Notice that Eq. 1 implies that $\mathbf b-\mathbf c$ is either $\mathbf 0$ or orthogonal to $\mathbf a$ (because $\mathbf a\not=\mathbf 0$). However notice that Eq. 2 implies that $\mathbf b-\mathbf c$ is either $\mathbf 0$ or parallel to $\mathbf a$ (again because $\mathbf a\not=\mathbf 0$).

The only way for both these conditions to be true is if $\mathbf b-\mathbf c=\mathbf 0$ which is logically equivalent to the statement $\mathbf b=\mathbf c$.

*We could also phrase it as the zero vector being vacuously orthogonal and parallel to every other vector.* $\tag*{\(\square\)}$

### Exercise 1.10
$\mathbf a:=(-1,1,2)\ \ \mathbf b:=(2,-1,1)$
#### Part 1
Find the set of vectors $\mathbf x$ such that $\mathbf a\times \mathbf x=(-2,4,-3)$ and $\mathbf b\cdot\mathbf x=2$

From the explicit definition of the cross product we find that, given a vector $\mathbf x=(x_1,x_2,x_3)$ it's cross product with $\mathbf a$ should be in the following form:

$$\mathbf a\times\mathbf x=(x_3-2x_2,2x_1+x_3,-x_2-x_1)=(-2,4,3)$$

We can also construct another equation using the dot product of $\mathbf b$ and $\mathbf x$:

$$\mathbf a\cdot\mathbf x=2x_1-x_2+x_3=2$$

Now we can split up the vector equation given by the cross product into 3 separate scalar ones and write it along side the scalar equation given by the dot product condition:

$$\begin{align}
x_3-2x_2=-2\tag{1}\\
2x_1+x_3=4\tag{2}\\
-x_2-x_1=-3\tag{3}\\
2x_1-x_2+x_3=2\tag{4}
\end{align}$$

Notice that we have a set of 4 equations for 3 unknowns, implying that the system has no solution unless one or more of the equations is a linear combination of the others.

We'll just slog through some algebra to show that no contradiction arises when we take all 4 equations to be true. Here we subtract Eq. 2 from Eq. 4:

$$\begin{align}
2x_1+x_3=4\\
-\hspace{14pt}2x_1-x_2+x_3=2\\
\hline
\boxed{x_2=2}
\end{align}$$

Plugging $x_2$ into Eq. 1 we find:

$$x_3-2(2)=-2\rightarrow \boxed{x_3=2}$$

Now plugging this into Eq. 2 we arrive at:

$$2x_1+2=4\rightarrow \boxed{x_1=1}$$

Now to verify that there is no contradiction we plug $x_1$ and $x_2$ into Eq. 3:

$$-x_2-x_1=-3\\
-2-1=-3\\$$

And so all 4 equations can be simultaneously satisfied by a single vector: $(1,2,2)$.

#### Part 2
Find the set of vectors $\mathbf x$ such that $\mathbf a\times \mathbf x=(2,4,3)$ and $\mathbf b\cdot\mathbf x=2$

We can set up a set of equations similar to the ones used in part 1:

$$\mathbf a\times\mathbf x=(x_3-2x_2,2x_1+x_3,-x_2-x_1)=(2,4,3)$$

$$\mathbf a\cdot\mathbf x=2x_1-x_2+x_3=2$$

Now we just split them into 4 scalar equations:

$$\begin{align}
x_3-2x_2=2\tag{1}\\
2x_1+x_3=4\tag{2}\\
-x_2-x_1=3\tag{3}\\
2x_1-x_2+x_3=2\tag{4}
\end{align}$$

Again, we'll assume that all 4 equations are true until we find a contradiction:

$$\begin{align}
2x_1+x_3=4\\
-\hspace{14pt}2x_1-x_2+x_3=2\\
\hline
\boxed{x_2=2}
\end{align}$$

Plugging $x_2$ into Eq. 1 we find:

$$x_3-2(2)=2\rightarrow \boxed{x_3=6}$$

Now plugging this into Eq. 2 we arrive at:

$$2x_1+6=4\rightarrow \boxed{x_1=-1}$$

Now to verify that there is no contradiction we plug $x_1,x_2$ into Eq. 3:

$$-x_2-x_1=3\\
-2-(-1)=-1\\
-1\not=3$$

We've come across a contradiction which means our assumptions that all 4 equations could be simultaneously satisfied was false. Thus the set of vectors that satisfy the given conditions is the null set $\emptyset$.

#### Part 3
What vector from the set $\{\mathbf x\in\mathbb{R}^3\mid\mathbf a\times\mathbf x=(-2,4,-3)\}$ is closest to $(1,1,1)$?

Any vector $\mathbf x$ in the above set will satisfy the following equations (which we got from part 1):

$$\begin{align}
x_3-2x_2=2\tag{1}\\
2x_1+x_3=4\tag{2}\\
-x_2-x_1=-3\tag{3}\\
\end{align}$$

Now we solve for $x_1,x_2$ and $x_3$ in terms of a single variable. Here I'll use $x_1$

$$\boxed{x_1=x_1}$$

$$-x_2-x_1=-3\rightarrow \boxed{x_2=3-x_1}$$

$$2x_1+x_3=4\rightarrow \boxed{x_3=4-2x_1}$$

And so the vector $\mathbf x$ has one degree of freedom and we have parameterized it to the variable $x_1$:

$$\mathbf x=(x_1,3-x_1,4-2x_1)$$

Now to find the vector closest to $(1,1,1)$ we simply find the norm of $\mathbf x - (1,1,1)$:

$$\begin{align}
\|\mathbf x - (1,1,1)\|&=\sqrt{(x_1-1)^2+(3-x_1-1)^2+(4-2x_1-1)^2}\\
&=\sqrt{(x_1-1)^2+(2-x_1)^2+(3-2x_1)^2}\\
&=\sqrt{6x_1^2-18x_1+14}\tag{foiling}
\end{align}$$

Now our problem is equivalent to minimizing the function defined above. We can rename it $f(x)$ and remove the subscript for clarity:

$$f(x)=\sqrt{6x^2-18x+14}$$

To find the minimum we must take the derivative of the function and set it equal to $0$ to find it's critical points:

$$\begin{align}
0&=\frac{d}{dx}\sqrt{6x^2-18x+14}\\
&=\frac{1}{2\sqrt{6x^2-18x+14}}\cdot\frac{d}{dx}(6x^2-18x+14)\\
&=\frac{1}{2\sqrt{6x^2-18x+14}}\cdot(12x-18)\\
&=\frac{6x-9}{\sqrt{6x^2-18x+14}}
\end{align}$$

Note that a fraction can only equal $0$ if it's numerator does, thus:

$$\begin{align}
\frac{6x-9}{\sqrt{6x^2-18x+14}}=0&\rightarrow 6x-9=0\\
&\rightarrow x=\frac{3}{2}
\end{align}$$

Testing for values after and before $x=\frac{3}{2}$ will verify that it is indeed a minimum:

*even though we know that $x=\frac{3}{2}$ must be a minimum given that the equation models the distances of vectors, which certainly have a minimum but not a maximum*

$$f(1)=\sqrt{14}\approx3.741\\
f\left(\frac{3}{2}\right)=\frac{1}{2}=0.5\\
f(2)=\sqrt{2}\approx1.414$$

And so $x=\frac{3}{2}$ is indeed a minimum. The vector is then given by the parametrization shown above:

$$\mathbf x=(x_1,3-x_1,4-2x_1)=\boxed{\left(\frac{3}{2},\frac{3}{2},1\right)}$$

### Exercise 1.12
Show that for any 4 vectors $\mathbf a,\mathbf b,\mathbf c,\mathbf x\in\mathbb{R}^3$, where $\mathbf a,\mathbf b,\mathbf c$ are non-zero, that the following is true:

$$\mathbf a\times(\mathbf b\times(\mathbf c\times \mathbf x))=\mathbf 0\leftrightarrow \mathbf b \perp \mathbf c\wedge (\exists\lambda\in\mathbb{R})\ \mathbf a=\lambda\mathbf c$$

To simplify this proof we'll first split this proposition $P$ into 3 propositions:

$$\begin{align}
P_1&\equiv\mathbf a\times(\mathbf b\times(\mathbf c\times \mathbf x))=\mathbf 0\\
P_2&\equiv\mathbf b \perp \mathbf c\\
P_3&\equiv(\exists\lambda\in\mathbb{R})\ \mathbf a=\lambda\mathbf c
\end{align}$$

Now we have to prove the following:

$$P_1\leftrightarrow P_2\wedge P_3$$

Which is equivalent to proving the following two statements:

$$\begin{align}
P_1&\rightarrow P_2\wedge P_3\tag{Lemma 1}\\
P_1&\leftarrow P_2\wedge P_3\tag{Lemma 2}
\end{align}$$

Which we'll call lemma 1 and 2 respectively.

#### Rephrasing the Propositions
Let's start off by rewriting $P_1$:

$$\begin{align}
P_1&\equiv\mathbf a\times(\mathbf b\times(\mathbf c\times \mathbf x))=\mathbf 0\\
&\equiv\mathbf a\times((\mathbf b\cdot\mathbf x)\mathbf c-(\mathbf b\cdot \mathbf c)\mathbf x)=\mathbf 0\tag{Lagrange's formula}\\
&\equiv(\mathbf b\cdot\mathbf x)(\mathbf a\times\mathbf c)-(\mathbf b\cdot \mathbf c)(\mathbf a\times\mathbf x)=\mathbf 0\tag{Distributive Prop.}\\
&\equiv(\mathbf b\cdot\mathbf x)(\mathbf a\times\mathbf c)=(\mathbf b\cdot \mathbf c)(\mathbf a\times\mathbf x)\\
\end{align}$$

Now notice that we can rephrase $P_2$ as:

$$\begin{align}
P_2&\equiv\mathbf b \perp \mathbf c\\
&\equiv\mathbf b \cdot \mathbf c=0
\end{align}$$

And finally, we can express $P_3$ as:

$$\begin{align}
P_3&\equiv(\exists\lambda\in\mathbb{R})\ \mathbf a=\lambda\mathbf c\\
&\equiv\mathbf a\parallel\mathbf c\\
&\equiv\mathbf a\times\mathbf c=\mathbf 0\\
\end{align}$$

#### Lemma 1
Proving the first half of the proposition is simply a matter of substitution. Given that $\mathbf b \cdot \mathbf c=0$ ($P_2$) and that $\mathbf a\times\mathbf c=\mathbf 0$ ($P_3$):

$$\begin{align}
P_1&\equiv \left(\mathbf b\cdot\mathbf x\right)\left(\mathbf a\times\mathbf c\right)=\left(\mathbf b\cdot \mathbf c\right)\left(\mathbf a\times\mathbf x\right)\\
&\equiv\left(\mathbf b\cdot\mathbf x\right)\left(\mathbf 0\right)=\left(0\right)\left(\mathbf a\times\mathbf x\right)\\
&\equiv\mathbf 0=\mathbf 0\\
&\equiv T
\end{align}$$

And so we have shown that $P_1$ is true assuming $P_2$ and $P_3$. More formally:

$$P_2\wedge P_3\rightarrow P_1$$

#### Lemma 2
<!-- ~~No *fucking* clue~~ This lemma is a bit harder to prove than the last... -->

Notice that we can rewrite $P_1$ by distributing the constants into the cross product:

$$\begin{align}
P_1&\equiv \left(\mathbf b\cdot\mathbf x\right)\left(\mathbf a\times\mathbf c\right)=\left(\mathbf b\cdot \mathbf c\right)\left(\mathbf a\times\mathbf x\right)\\
&\equiv \left(\mathbf a\times\left(\mathbf b\cdot\mathbf x\right)\mathbf c\right)=\left(\mathbf a\times\left(\mathbf b\cdot \mathbf c\right)\mathbf x\right)\\
\end{align}$$

We can further simplify this by calling $s:=(\mathbf b\cdot\mathbf x)$ and $t:=(\mathbf b\cdot\mathbf c)$, subtracting one side from the other and using the distributive property:

$$\begin{align}
P_1&\equiv\left(\mathbf a\times s\mathbf c\right)=\left(\mathbf a\times t\mathbf x\right)\\
&\equiv\left(\mathbf a\times s\mathbf c\right)-\left(\mathbf a\times t\mathbf x\right)=0\\
&\equiv\mathbf a\times \left(s\mathbf c-t\mathbf x\right)=0\\
\end{align}$$

Notice because $\mathbf a\not=\mathbf 0$, and that $\mathbf c-\mathbf x$ is coplanar to $s\mathbf c-t\mathbf x$, then $\mathbf c-\mathbf x$ is parallel to $\mathbf a$. So $(\mathbf a\times \mathbf c)=0\equiv P_3$

This means that $\mathbf b\cdot\mathbf c$ must equal $0$ because there are some $\mathbf x$ such that $(\mathbf a\times\mathbf x)$ is not $\mathbf 0$. Thus for $P_1$ to be true $\mathbf b\cdot \mathbf c=0$ thus $P_2$.

<!-- Now note that if two vectors, in this case $\mathbf a\times s\mathbf c$ and $\mathbf a\times t\mathbf x$, cancel out to $\mathbf 0$ then they must be additive inverses of each other. All additive inverses are parallel to each other (they are scaled by -1). As such the cross product of these two vectors must also be $\mathbf 0$:

$$\left(\mathbf a\times s\mathbf c\right)\times \left(\mathbf a\times t\mathbf x\right)=0$$

Now, using the distributive property twice over, we can show:

$$\begin{align}
s\left(\mathbf a\times \mathbf c\right)&\times t\left(\mathbf a\times\mathbf x\right)=0\\
(st)\left(\mathbf a\times \mathbf c\right)&\times \left(\mathbf a\times\mathbf x\right)=0\\
\end{align}$$
 -->
