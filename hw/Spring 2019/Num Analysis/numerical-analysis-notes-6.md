<!-- ---
layout: post
title: Numerical Analysis Notes Ch. 6
date: 2019-03-23
tags: math computer-science numerical-analysis
--- -->
My notes on Atkinson and Han's *Elementary Numerical Analysis*. Chapter 6 - Solution of Systems of Linear Equations.

## 6.1 Systems of Linear Equations
A system of $n$ linear equations in $n$ variables is a collection of equations of the following form:

$$\begin{matrix}
a_{11}x_1+a_{12}+\cdots+a_{1n}x_n=b_1\\
a_{11}x_1+a_{12}+\cdots+a_{1n}x_n=b_2\\
\vdots\\
a_{n1}x_1+a_{n2}+\cdots+a_{nn}x_n=b_n\\
\end{matrix}$$

Given $n^2$ constants denoted $a_{ij}$ and $n$ other constants denoted $b_i$, the aim is to find $(x_i)_{i=0}^n$ that simultaneously satisfy all $n$ equations. Notice that these equations are naturally represented in matrix algebra:

$$\underbrace{\begin{bmatrix}
a_{11} & a_{12} & \cdots & a_{1n}\\
a_{21} & a_{12} & \cdots & a_{1n}\\
\vdots & \vdots & \ddots & \vdots\\
a_{n1} & a_{n2} & \cdots & a_{nn}\\
\end{bmatrix}}_{A}
\underbrace{\begin{bmatrix}
x_{1}\\x_{2}\\\vdots\\x_{n}\\
\end{bmatrix}}_{\vec x}=\underbrace{\begin{bmatrix}
b_{1}\\b_{2}\\\vdots\\b_{n}\\
\end{bmatrix}}_{\vec b}$$

And so any $n$th order linear system is given by the following equation:

$$A\vec x=\vec b$$

## Problems
What is Polynomial interpolation?
<!-- #### Problem 1
**Question:**

**Answer:** -->

## 6.2 Matrix Arithmetic
I'll skip the introductory linear algebra for now. Suffice to say $m\times n$ matrices form a vector space under the normal elementwise addition and scalar multiplication. There's also matrix multiplication which, on the set of invertible $n\times n$ matrices, forms an algebra over a field.

Also, every matrix represents a linear map $f$ from some finite dimensional module to another:

$$f:V\to W\ \ \ \ \ \ \ \ \ \ \ \ \ f(\vec x)=A\vec x$$

Where $\vec x\in V$, and $A\in V\times W$ thus having dimensions $\dim(V)\times\dim(W)$. The converse is also true, that is every finite dimensional linear map can be represented by a finite matrix. Adding and compositing these linear maps is analogous to adding and multiplying matrices.

Noninvertible matrices are called **singular** (i.e. $\det A = 0$) and invertible ones called **nonsingular**. Only square matrices can be invertible, but rectangular ones can have left/right inverses.

#### Row Operations
Row operations are and transformation of a matrix that is a composition of the following 3 basic operations:

- Interchanging two rows.
- Multiplying a row by a nonzero scalar.
- Adding a linear combination of rows to another row.

While these operations change the matrix, they do not change the solution to the equation $A\vec x=\vec b$ and so can be used to solve for $\vec x$.

#### Solvability of Linear Systems
Consider the linear system $A\vec x=\vec b$ for some square matrix $A$. When $\vec b=\vec 0$ the system is called **homogenous**. When $\vec b \not= \vec 0$ it is **non-homogenous**. Every non-homogenous system has an associated homogenous one by setting $\vec b := \vec 0$. I terms of solvability, note that all 4 of the following propositions are equivalent:

- The system has a unique solution $\vec x$
- The system has at least one solution $\vec x$
- The homogenous form of the system has a unique solution.
- $\det(A)\not=0$
- $\exists A^{-1}, \ A^{-1}A=I$

Any one of these propositions implies that $\vec x = A^{-1}\vec b$.

## Problems
#### Problem 1
**Question a:** Simplify this expression:

$$2\begin{bmatrix}
1 & 0\\
-1 & 3
\end{bmatrix}+
\begin{bmatrix}
1 & 1\\
1 & -1
\end{bmatrix}
\begin{bmatrix}
2 & 3\\
1 & 3
\end{bmatrix}$$

**Answer:** The answer is:

$$\begin{bmatrix}
2 & 0\\
-2 & 6
\end{bmatrix}+
\begin{bmatrix}
3 & 6\\
1 & 0
\end{bmatrix}=
\begin{bmatrix}
5 & 6\\
-1 & 6
\end{bmatrix}$$

**Question b:** Simplify this expression:
$$\begin{bmatrix}
1 & 2\\
0 & 3
\end{bmatrix}
\begin{bmatrix}
a & b\\
0 & c
\end{bmatrix}$$

**Answer:** The answer is:

$$\begin{bmatrix}
a & b+2c\\
0 & 3c
\end{bmatrix}$$

**Question c:** Solve for $B$:

$$A=I_3-2ww^\top, \ \ \ \ \ \ \ w^\top=\left[\frac{1}{3},\frac{2}{3},\frac{2}{3}\right], \ \ \ \ \ \ \ B=A^2$$

**Answer:** First we solve for $ww^\top$:

$$ww^\top=\frac{1}{3^2}\begin{bmatrix}
1\\2\\2
\end{bmatrix}\left[1,2,2\right]=
\frac{1}{9}\begin{bmatrix}
1 & 2 & 2\\
2 & 4 & 4\\
2 & 4 & 4
\end{bmatrix}$$

Substituting this in, we find that $A$ is:

$$A=I_3-\frac{2}{9}\begin{bmatrix}
1 & 2 & 2\\
2 & 4 & 4\\
2 & 4 & 4
\end{bmatrix}=\frac{1}{9}\begin{bmatrix}
8 & -2 & -2\\
-2 & 5 & -4\\
-2 & -4 & 5
\end{bmatrix}$$

And finally, by squaring this matrix we arrive at:

$$B=A^2=\frac{1}{9^2}\begin{bmatrix}
8 & -2 & -2\\
-2 & 5 & -4\\
-2 & -4 & 5
\end{bmatrix}
\begin{bmatrix}
8 & -2 & -2\\
-2 & 5 & -4\\
-2 & -4 & 5
\end{bmatrix}=\frac{1}{9}\begin{bmatrix}
8 & -2 & -2\\
-2 & 5 & -4\\
-2 & -4 & 5
\end{bmatrix}$$

**Question d:** Solve for $B$:

$$A=\begin{bmatrix}
\cos\theta & \sin\theta\\
-\sin\theta & \cos\theta
\end{bmatrix},\ \ \ \ \ \ \ B=AA^\top$$

**Answer:** Note that $A^\top$ is also $A^{-1}$ and so $B$ is just the identity:

$$B=AA^\top=\begin{bmatrix}
\cos\theta & \sin\theta\\
-\sin\theta & \cos\theta
\end{bmatrix}\begin{bmatrix}
\cos\theta & -\sin\theta\\
\sin\theta & \cos\theta
\end{bmatrix}=\begin{bmatrix}
1&0\\0&1
\end{bmatrix}=I$$

**Question e:** Solve for $B$:

$$A=\begin{bmatrix}
2 & 1 & 0 & \cdots & 0\\
1 & 2 & 1 & \ddots & \vdots\\
0 & \ddots & \ddots & \ddots & 0\\
\vdots & \ddots & 1 & 2 & 1\\
0 & \cdots & 0 & 1 & 2
\end{bmatrix},\ \ \ \ \ \ \ \ B=A^2$$

<!-- **Answer:**

$$A^2=\begin{bmatrix}
5 & 4 & 1 & \cdots & 0\\
4 & 5 & 1 & \ddots & \vdots\\
0 & \ddots & \ddots & \ddots & 0\\
\vdots & \ddots & 1 & 2 & 1\\
0 & \cdots & 0 & 1 & 2
\end{bmatrix}$$ -->

#### Problem 2
**Question:** Consider an $n$th order diagonal matrix:

$$D=\begin{bmatrix}
\lambda_1&0&\cdots&0\\
0&\lambda_2&\cdots&0\\
\vdots&\vdots&\ddots&\vdots\\
0&0&\cdots&\lambda_n\\
\end{bmatrix}$$

Give a simple rule for computing the product $AD$ and $DA$ where $A$ is ana arbitrary $n$th order matrix.

**Answer:** The matrix product $DA$ just has the $i$th row of $A$ scaled by $\lambda_i$:

$$(DA)_ {ij}=\lambda_iA_{ij}$$

Similarly, the product $AD$ has the $i$th column of $A$ scaled by $\lambda_i$:

$$(AD)_ {ij}=\lambda_jA_{ij}$$

#### Problem 3
**Question:**

**Answer:**

## 6.3 Gaussian Elimination
This is a method of solving a system of linear equations. Before we perform it, it is useful to represent our system of $n$ equations in $n$ variables ($A\vec x=\vec b$) as an $n\times(n+1)$ **augmented matrix** like so:

$$(A|b)=\left[\begin{array}{cccc|c}
a_{11}&a_{12}&\cdots&a_{1n}&b_1\\
a_{21}&a_{22}&\cdots&a_{2n}&b_2\\
\vdots&\vdots&\ddots&\vdots&\vdots\\
a_{n1}&a_{n2}&\cdots&a_{nn}&b_n\\
\end{array}\right]$$

Using $R_i$ to denote the $i$th row of the matrix, Gaussian Elimination in 3 dimensions is as follows:

- $R_2-\frac{a_{21}}{a_{11}}R_1:=R_2$ Zero out first variable in row 2
- $R_3-\frac{a_{31}}{a_{11}}R_1:=R_3$ Zero out first variable in row 3
- $R_3-\frac{a_{32}}{a_{22}}R_2:=R_3$ Zero out second variable in row 3

<!-- $$\left[\begin{array}{ccc|c}
a_{11}&a_{12}&a_{13}&b_1\\
a_{21}&a_{22}&a_{23}&b_2\\
a_{31}&a_{32}&a_{33}&b_3\\
\end{array}\right]$$ -->

After Gaussian elimination, we are left with a matrix in row echelon form:

$$\left[\begin{array}{ccccc|c}
a_{11}&a_{12}&a_{13}&\cdots&a_{1n}&b_1\\
0&a_{22}&a_{23}&\cdots&a_{2n}&b_2\\
0&0&a_{33}&\cdots&a_{3n}&b_3\\
\vdots&\vdots&\vdots&\ddots&\vdots&\vdots\\
0&0&\cdots&0&a_{nn}&b_n\\
\end{array}\right]$$

Solving for $\vec x$ is now as simple as back-substituting each component from the bottom up. We start with $x_n=\frac{b_n}{a_nn}$, then substitute that into row $n-1$ solve the linear equation and continue upwards.

#### Partial Pivoting
An underlying assumption we've made above is that the none of the elements of the form $a_{ii}=0$. We can remedy this by noting that, assuming the matrix is nonsingular, there will always be a row that has a non-zero entry in the $i$th column (that is to say no columns are the zero vector). Because of this, we can interchange the rows so that $(\forall i)\ a_{ii}\not=0$.

Even further this *partial pivoting* can help reduce numerical instability. At the start of each step $k$ of the elimination we should pivot, i.e. move up, the row $i>k$ with the largest element in column $k$. *Complete pivoting* takes this further by interchanging the columns as well, but this is usually unnecessary as the added stability isn't worth the cost of searching.

#### Inverse Matrices
We can use Gaussian elimination to calculate inverse matrices. Given an $n$th order matrix $A$, it's inverse $X=A^{-1}$ obeys the following:

$$AX=I$$

We can split this up into $n$ systems of $n$ equations:

$$(A\vec x_{* i}=\vec e_i)_ {i=1}^n$$

Where $\vec e_i$ is the $i$th basis vector, and thus the $i$th column of $I$. And $\vec x_{* i}$ is the $i$th column of $X$. Solving all $n$ of these systems and putting together all resulting column vectors gives us the inverse $X=A^{-1}$.

That said, the process can be done quicker by simply augmenting the entire identity matrix to $A$ and solving $(A|I)$, rather than one column at a time. We can perform Gaussian elimination on this new matrix as before, and translate it back into $n$ systems of equations. Alternatively we can continue to perform row operations on the augmented matrix until the left side is the identity matrix. The resulting matrix on the right side will be $A^{-1}$.

#### Complexity
Refer to the textbook for a more detailed count of the operations (additions, multiplications, divisions) but the overall complexity of Gaussian elimination is around $\frac{n^3}{3}$.

This is 3 times better than the $n^3$ operations that outright finding the inverse of a matrix (and using it to find $\vec x$) would take. You'll notice, though, that they both have $O(n^3)$ time complexity.

## LU Decomposition
LU decomposition uses Gaussian elimination to factor a matrix $A$ into the product of a lower triangular matrix $L$ and an upper triangular matrix $U$:

$$A=LU$$

$U$ will end up being our row echelon form matrix from performing Gaussian elimination on $A$. The elements of $L$ will be of the form:

$$\left[\begin{array}{cccc}
1&0&\cdots&0\\
l_{21}&1&\cdots&0\\
\vdots&\vdots&\ddots&\vdots\\
l_{n1}&l_{n2}&\cdots&1\\
\end{array}\right]$$

The elements below $L$'s diagonal are the multipliers (including the negative sign) used in performing Gaussian elimination on $A$ to produce $U$.

#### Direct Solution
A simpler solution (I find) is to multiply the two triangular matrices and set their product equal to $A$. Solving the resulting system of equations will result in all elements being known.

#### LUP decomposition Partial Pivoting
When our decomposition is done with partial pivoting, we need to add a permutation matrix $P$ to account for the row switches:

$$PA=LU$$

*We can move the inverse of $P$, also a permutation matrix, to the other side giving us $LUP$.*