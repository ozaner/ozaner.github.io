<!-- ---
layout: post
title: Numerical Analysis Notes Ch. 2
date: 2019-03-02
tags: math computer-science numerical-analysis
--- -->
My notes on Atkinson and Han's *Elementary Numerical Analysis*. Chapter 2 - Error and Computer Arithmetic.

## 2.1 Floating-Point Numbers
The binary floating point representation of a number $x$ is expressed in the following form:

$$x=\sigma\cdot\bar x\cdot 2^e$$

Where
- $\sigma$ is the sign of $x$. i.e. $\operatorname{sign}(x)$
- $\bar x$ is the significand. A binary fraction that satisfies $1_2\le\bar x\le10_2$.
- $e$ is the exponent. It represents how many binary places to move the significand $e=\lfloor\log_2 x\rfloor$.

<!--more-->

#### IEEE Floating Point
The IEEE floating point standard defines what a 32 bit and 64 bit version of a floating point representation looks like and how many bits are allocated to each component of the number

In the IEEE standard, the first digit of the significand is always a 1 so it is omitted (it is reinserted when the number is inserted into the ALU). Taking this into account, the 32 bit IEEE single precision float has a:
- Precision of 24 bits (23 bit significand + 1st implied bit)
- Exponent is a signed 8 bit integer. $e\in[-126,127]$.

![single](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e8/IEEE_754_Single_Floating_Point_Format.svg/618px-IEEE_754_Single_Floating_Point_Format.svg.png)

The 64 bit IEEE double precision float, aka the double, has a:
- Precision of 53 bits (52 bit significand + 1st implied bit)
- Exponent is a signed 11 bit integer. $e\in[-1022,1023]$.

![double](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a9/IEEE_754_Double_Floating_Point_Format.svg/618px-IEEE_754_Double_Floating_Point_Format.svg.png)

The 8/11 exponent bits actually represent a number $E$ which, when subtracted by 127/1023, represents the true exponent $e$:

$$\underbrace{E-127=e}_{\text{float}}\ \ \ \ \ \ \underbrace{E-1023=e}_{\text{double}}$$

This is done so that we can represent numbers of both extremely low and high magnitude. Also note that the sign bit is set to $0$ for positive numbers and $1$ for negative numbers.

#### Special Values
More on floats [here](http://steve.hollasch.net/cgindex/coding/ieeefloat.html).

**Zero**
Since we include the implied 1 in the IEEE definitions to save bits on precision, its impossible to define the floating point 0 in the natural way. Instead we define zero to just be either sign bit followed string of 0's:

$$fl(0)=0000\dots00_2=1000\dots00_2$$

This gives us both positive and negative zero, but they both evaluate and compare as if they were equivalent.

**Infinity**
The values infinity, or Inf, are represented by an exponent of all 1's and a significand of all 0's. The sign of Inf is still represented by the sign bit:

$$+\infty=0\underbrace{1111\dots}_{e}\underbrace{0000\dots00}_{\bar x}{}_2\ \ \ \ -\infty=1\underbrace{1111\dots}_{e}\underbrace{0000\dots00}_{\bar x}{}_2$$

**NaN**
Not a number, or NaN, refer to floating point numbers that aren't defined to represent any particular real number. These are numbers with an exponent of all 1's and a fraction that is non-zero (oe else it would be infinity).

**Denormalized Numbers**
When the exponent is all zeros, not representing zero but the actual exponent bits are zeroed out, the number is called denormalized and there is an implicit leading 0 rather than leading 1. These numbers are of the form:

$$\sigma\cdot 0.\bar x\cdot 2^{-126\text{ or } -1023}$$

### 2.1.1 Accuracy of Floating-Point Representation
#### Machine Epsilon
One important way we can measure how accurately we can store a number in a particular floating point representation is via its **machine epsilon**. This value is the difference between 1 and the smallest numbers greater than 1 that can be stored in the format. In a single precision float, that number is:

$$1.\underbrace{000000000000000000001}_{23 \text{ places}}{}_2$$

Thus the machine epsilon of a float is:

$$\epsilon_{f}=2^{-23}\approx 1.19\times 10^{-7}$$

This tells us that a single precision float can only store 23 bits, or **about 7 decimal digits**, of accuracy. Likewise, for double precision floats, the machine epsilon is:

$$\epsilon_{d}=2^{-52}\approx 2.22\times 10^{-16}$$

Giving us 52 bits, or **approximately 16 decimal digits**, of numerical precision.

#### Largest Integer Interval
Another way to quantify the accuracy of a float is to find the largest integer $M$ such that for any integer $x\in[0,M]$ can be represented exactly by a float. This is the following number:

$$2^n=1.\underbrace{000\dots00}_{n\text{ bits}}{}_2\times 2^n$$

Where $n$ is the number of bits in the significand. Note that larger integers can be stored in floating point, but it is no longer the case that *all* positive integers less than them can also be stored. That is to say, gaps begin to appear between the integers in floating point representations past the constant $M$.

For a single precision float with a 24 bit significand (23 + an implicit bit), this gives us:

$$M_f=2^{24}=16777216\approx 1.7\times 10^7$$

And so all 7 digit integers are representable as a floats, and some 8 digit numbers as well. For example, the first integer not representable is $2^{24}+1=16777217$. For doubles we have:

$$M_d=2^{53}=9007199254740992\approx9.0\times 10^{15}$$

And so, likewise, a double can represent any 15 digit integer and most 16 digit integers.

### 2.1.2 Rounding and Truncating
When converting some real number to it's floating point representation, there must be some lost in precision in order to have a finite representation of the number. We can phrase this as:

$$\operatorname{fl}(x)=x(1+\epsilon)$$

*Where $\epsilon$ is a small number.*

Note that this makes $\operatorname{fl}(x)$ a *pertubation* of $x$. The floating point standard deals with this loss in precision past the last bit in two ways:

The simplest method is to **truncate** the digits following the final bit of the significand. With $n$ being the bits of the significand (23/54), $\epsilon$ is bounded like so:

$$-2^{-(n-1)}\le\epsilon\le 0$$

Another option is to **round** the number to the nearest floating point representation. This would be the same as truncation but if the $n+1$th digit (the digit just after the truncation) is a 1, then add a 1 to the significand. Here $\epsilon$ is bounded like so:

$$-2^{-n}\le\epsilon\le 2^{-n}$$

<details open>
<summary><h3 class="inline">Problems</h3></summary>

<h4>Problem 1</h4>
<b>Question:</b> Use MATLAB to find the binary IEEE double representation of the following numbers:

$$8,12,1.5,0.5,1.25$$

<b>Solution:</b> Using the following MATLAB command <code>dec2bin(typecast(x, 'uint64'),64)</code> where <code>x</code> is our input stored as a double, we get:

<ul>
<li>$fl(8)=0100000000100000000000000000000000000000000000000000000000000000$</li>
<li>$fl(12)=0100000000101000000000000000000000000000000000000000000000000000$</li>
<li>$fl(1.5)=0011111111111000000000000000000000000000000000000000000000000000$</li>
<li>$fl(0.5)=0011111111100000000000000000000000000000000000000000000000000000$</li>
<li>$fl(1.25)=0011111111110100000000000000000000000000000000000000000000000000$</li>
</ul>

</details>

### 2.1.3 Implications of Float Representations

## 2.2 Error