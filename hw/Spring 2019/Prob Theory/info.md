jbeck@math.rutgers.edu
office hours: Tue & Wed, 1:40-3pm in Hill-222
Sheldon Ross: Probability, Ch 2-3

#### Notes 2/21
Quiz Monday Feb 25
Textbook, notes, and **calculator** are ok

**Exercise 25 Ch. 2**
This is the level of an extra credit problem(?) he spent a while on it though and it seemed important

$$P\left(\bigcup_{k=1}^\infty E_k\right)=\sum_{k=1}^\infty E_k=\frac{4}{36}\sum_{k=1}^\infty\left(\frac{36-4-6}{36}\right)^{k-1}$$

$$=\frac{1}{9}\cdot\frac{1}{1-\frac{26}{36}}=\frac{2}{5}$$

Explanation:
http://mathforum.org/library/drmath/view/61207.html

Side note: when you solve out the probability that 7 comes before 5 you get 3/5. This means the probability that neither 5 nor 7 appears is 0%.

#### Prob 1
Probability that adam and caroline have the same sum:

$$=2\left(\frac{1}{36}\right)^2+2\left(\frac{2}{36}\right)^2+2\left(\frac{3}{36}\right)^2+\cdots+\left(\frac{6}{36}\right)^2$$

*1/36 is prob for 2 and 12, 2/36 for 3 and 11 and so on until 6/36 for 7. Note the 7 prob (6/36) is only multiplied by 1. (odd number of sums 2,3,4,5,6,7,8,9,10,11,12).*

#### Prob 2
100 girls and 100 boys. We randomly select 100 students. What is the probability that we have 50 girls:

$$=\frac{\binom{100}{50}\cdot\binom{100}{50}}{\binom{200}{100}}=\frac{(100!)^4}{200!(50!)^4}\approx blah$$

*If we have 50 girls (first term) we must have 50 boys (second term).*

We can approximate it using the prob using Stirling's approx:

$$n!\approx(n/e)^n\sqrt{2\pi n}$$

#### Prob 3 (HW i guess)
We have an integer line. You start at 0. You roll a dice to see how many steps forward you go. What's the probability you land on the number 1000, which has goose poop on it?

#### Prob 4
A: we have 2 dice we roll them 24 times. Whats the prob that (6,6) is never rolled?

B: we have 3 dice we roll them 144 times. Whats the prob that (6,6,6) is never rolled?

Are they the same? No, they are very close though.

$$P(A)=\left(\frac{36-1}{36}\right)^{24}=\left(1-\frac{1}{36}\right)^{24}=\left(1-\frac{2/3}{24}\right)^{24}\approx e^{-24}=.50859$$

$$P(B)=\left(\frac{216-1}{216}\right)^{144}=\left(1-\frac{1}{216}\right)^{144}=\left(1-\frac{2/3}{144}\right)^{144}\approx e^{-24}=.512\cdots$$

Because

$$(1-\frac{c}{n})^n\approx e^{-c}$$
