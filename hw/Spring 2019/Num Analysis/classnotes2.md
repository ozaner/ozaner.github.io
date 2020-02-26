justMidterm I
on Chapter 4 (Rootfinding)
and Chapter 6 (Linear Systems)

study hw and examples in textbook. one page cheat sheet allowed. no calculators

## 8.9 Nonlinear systems
For a non linear system of $n$ equations, here we show 2:
- $f(x,y)=0$
- $g(x,y)=0$

#### Newton's Method for Nonlinear Systems
Estimate using tangent plane rather than tangent line. The equation of a tangent plane is:
$$p(x,y)=f(x_0,y_0)+f_x(x_0,y_0)(x-x_0)+f_y(x_0,y_0)(y-y_0)$$

So we approximate $f$ and $g$ by finding their tangent planes $p$ and $q$ at $(x_0.y_0)$ and finding *their* zeros:
- $p(x,y)=0$
- $q(x,y)=0$

As a matrix we get:
$$\begin{bmatrix}
    f_x(x_0,y_0) & f_y(x_0,y_0)\\
    g_x(x_0,y_0) & g_y(x_0,y_0)
\end{bmatrix}
\begin{bmatrix}
    x-x_0\\
    y-y_0
\end{bmatrix}=
\begin{bmatrix}
    -f(x_0,y_0)\\
    -g(x_0,y_0)
\end{bmatrix}$$

We plug in the initial guess, as the change in $x$ and $y$ and solve for $x$ and $y$ then iterate.

#### Error Analysis
Let $\vec \alpha=[x,y]$ be a solution of the linear system:
- $f(x,y)=0$
- $g(x,y)=0$

Assume $f$ and $g$ are smooth, if $\|\vec \alpha-\vec x_k\|\le \epsilon$ and:

$$\left|\begin{matrix}
    f_x & f_y\\
    g_x & g_y
\end{matrix}\right|\not= 0$$

Then the following holds:

$$\|\vec \alpha-\vec x_{k+1}\|\le c\|\vec\alpha-\vec x_k\|^2$$

That is to say, the error converges quadratically.

#### Application
Consider a function $f(x,y)$. We can find the minimum by equivalently finding where its derivative equals $(0,0)$.

## Solving Linear Systems
#### LU Decomposition

The complexity of LU decomposition on an $n\times n$ matrix is $O(\frac{2}{3}n^3)$.

#### Error in solving linear system
Consider solving $A\vec x=\vec b$ by LU decomposition. The error $\vec x_{true}-\vec x$ will be huge especially as the matrix grows, yet the the residual $A\vec x-\vec b$ will be small. What's the deal?

Consider the $L_\infty$ norm:

$$\|\vec v\|_ \infty=\max_{i=1,2,\cdots, n}|v_i|$$

With this norm, our error is instead $\|\vec x_{true}-\vec x\|_ \infty$.

Now consider the following matrix norm:

$$\|A\|_ \infty=\max_{i=1,2,\cdots, n}\left(\sum_{j=1}^n|a_{ij}|\right)=\left\|\left(\|\vec a_i\|_ 1\right)\right\|_ \infty$$

These norms satsify the triangle inequalities and:

$$\|A\vec x\|\le\|A\|\|\vec x\|$$

Given:

- $A\vec x = \vec b$
- $A\hat x = \hat b=\vec b +\vec \epsilon$

then:

$$\frac{\|\vec x-\hat x\|}{\|\vec x\|}\le \|A\|\|A^{-1}\|\frac{\|\vec b-\hat b\|}{\|\vec b\|}$$

Our relative error is thus bounded by the right hand side. We call the following term the conditional number of the matrix:

$$\operatorname{cond}(A)=\|A\|\|A^{-1}\|$$

From this we can conclude that if $\operatorname{cond}(A)$ is small, then a small perturbation in $\vec b$ does not produce a large error in $\vec x$.
When this is the case, we say the problem is **well-conditioned**. Otherwise it is ill-conditioned.

## Iterative Methods of Linear Systems
Some motivation for considering an iterative method: In many cases for the equation $A\vec x=\vec b$, the matrix $A$ is sparse (doesn't have many non-zero entries). An example might be a diagonal or tridiagonal matrix.

The complexity of matrix-vector multiplication of a, say, $n\times n$ tridiagonal matrix is only rows(3*s and 2+s) giving us $O(5n)$. This is to say that the complexity of sparse matrix-multiplication is much less than full matrix multiplication.

Given a system $A\vec x=\vec b$ we decompose the $A$ matrix into:

$$A=D+L+U$$

Where:
- $D$ is a diagonal matrix
- $L$ is a strictly lower triangular matrix
- $U$ is a strictly upper triangular matrix

#### Method 1: Jacobi Iteration
Given an initial guess $\vec x^{(0)}$ the Jacobi iteration is:

$$\vec x^{(k+1)} = D^{-1}\left(\vec b - (L+U)\vec x^{(k)}\right)$$

Inverting a diagonal matrix is as simple as inverting all its elements, i.e.  $O(n)$ time.

#### Method 2: Gauss–Seidel Iteration
Given an initial guess $\vec x^{(0)}$ the Gauss–Seidel iteration is:

$$\vec x^{(k+1)} = (L+D)^{-1}\left(\vec b - U\vec x^{(k)}\right)$$

or:

$$(L+D)\vec x^{(k+1)} = \vec b - U\vec x^{(k)}$$

In this second form, we can solve the system by forward substitution and avoid having to compute an inverse matrix.

#### Error of these Methods
The general form of these two methods is:

$$N\vec x^{(k+1)} = \vec b + P\vec x^{(k)}$$

Where the system $N\vec x=\vec f$ is hopefully easy to solve.

In Jacobi:
- $N=D$
- $P= -(L+U)$

In Gauss–Seidel
- $N=D+L$
- $P=-U$

If the method's iterates do converge to the solution, i.e.:

$$\lim_{k\to\infty}\vec x^{(k)}=\vec x$$

Then it will be a fixed point. Subtracting this from the iteration we find:

$$\begin{align*}
N\vec x &= \vec b + P\vec x\tag{fixed point}\\
-(N\vec x^{(k+1)} &= \vec b + P\vec x^{(k)})\tag{iteration}\\
\hline
N(\vec x-\vec x^{(k+1)})&=P(\vec x-\vec x^{(k+1)})
\end{align*}$$

Define the error at step k as:

$$\vec e^{(k)}=\vec x - \vec x^{(k)}$$

Thus the error is given by:

$$\vec e^{(k+1)}= N^{-1}Pe^{(k)}=M\vec e^{(k)}$$

#### Convergence & Diagonal Dominance
The convergence this method is guaranteed only when $\|M\|<1$ where the norm is the max of the sum of the magnitude of each row.

A matrix $A$ is **diagonal dominant** if:

$$\sum_{j=1\\j\not= i}^n |a_{ij}|<|a_{ii}|$$

That is to say the sum of the magnitude of all the (off diagonal) elements is less than that of the magnitude of the diagonal element.

This is relevant because the Jacobi iteration always converges when $A$ is diagonally dominant. In fact, it converges *exactly* when $A$ is diagonally dominant.

The same is true for the Gauss–Seidel method except it also converges when the matrix is symmetric and positive definite.

#### Complexity
If $A$ is sparse then the complexity of each iteration is given below.

For Jacobi the complexity of solving $(L+U)\vec x^{(k)}$ is on the order of $n$.

## 7.1 Computing Eigenvalues
Given an $n\times n$ matrix $A$, we say that $\lambda\in\mathbb R$ is an eigenvalue and $\vec v$ an eigenvector of $A$ if:

$$A\vec v=\lambda\vec v$$

Recall that to find the eigenvalues of $A$ we use its characteristic polynomial:

$$p(\lambda)=\det(A-\lambda I_n)$$

The roots of this equation are the eigenvalues of $A$. To find the associated eigenvectors of these values, we solve for them like so:

$$(A-\lambda_iI_n)\vec v_i=\vec 0$$

Note that the characteristic polynomial of $A$ is an $n$th degree polynomial and thus has $n$ complex roots.

#### Symmetric Matrices
If a matrix $A$ is symmetric (i.e. $A=A^\top$), then all $n$ eigenvalues (with possible duplicates) are real and all their associated eigenvectors form an orthogonal basis of $\mathbb R^n$ (and not a lower dimension), further we can make this orthonormal by just choosing those with length 1.

### Power Method
Computing the determinant of a matrix is a difficult calculation, and finding the roots of a polynomial is also difficult and isn't generally numerically unstable.

One method that gets around this is the power method, which approximates the largest magnitude eigenvalue (and its corresponding eigenvector) of a symmetric matrix $A$.

Given some initial guess $\vec v^{(0)}$ of the eigenvector, the iteration is:

$$\vec v^{(k+1)}=\frac{A\vec v^{(k)}}{\|A\vec v^{(k)}\|}$$

*Notice we normalize the iteration at each step.*

This iteration will converge to the largest eigenvector.

#### Error
The error of this method is given by:

$$\|\vec v^{(k)}-\vec v_1\|\approx O\left(\frac{\lambda_2}{\lambda_1}\right)^k$$
