## Chapter 2 Examples
#### Example 5h, a
Probability that 1 player get all 13 spades:

$$\begin{align*}
\frac{\overbrace{4\binom{13}{13}}^{4 \text{ hands}}\overbrace{\binom{39}{13}\binom{26}{13}\binom{13}{13}}^{\text{other hands}}}{\binom{52}{13,13,13,13}}=\frac{4\binom{39}{13}\binom{26}{13}}{\binom{52}{13}\binom{39}{13}\binom{26}{13}}=\frac{4}{\binom{52}{13}}=6.3\cdot 10^{-12}
\end{align*}$$

#### Example 5h, b
Probability that each of 4 players gets a spade:

$$\begin{align*}
P(E)&=\frac{\overbrace{4}^{4\text{ spades}}\binom{48}{12}3\binom{36}{12} 2\binom{24}{12}1\binom{12}{12}}{\binom{52}{13}\binom{39}{13}\binom{26}{13}\binom{13}{13}}=\frac{4!\binom{48}{12,12,12,12}}{\binom{52}{13,13,13,13}}\\
&=\frac{4!\frac{48!}{12!12!12!12!}}{\frac{52!}{13!13!13!13!}}=\frac{4!(13!)^448!}{(12!)^452!}=\frac{13^44!}{52\cdot 51\cdot 50\cdot 49}=.1055
\end{align*}$$

<!-- #### Prob 2
Probability person A's hand has at least 1 card form each suit. We'll compute the complement of this first:

$$\begin{align*}
\frac{4\overbrace{\binom{52-13}{13}}^{\text{missing cases}}-\overbrace{\binom{4}{2}\binom{52-26}{13}}^{\text{overcounting}}}{\binom{52}{13}}
\end{align*}$$ -->

## In Class
#### 1
Probability of that we have at least 1 card from each suit from drawing 13 cards.


Probability of choosing 4 cards, and having more than 1 from each suit:

$$\frac{13\cdot13\cdot13\cdot13}{\binom{52}{4}}$$

Probability of choosing 5 cards, and having more than 1 from each suit, now one suit of 4 will have 2 cards:

$$\frac{4\binom{13}{2}\cdot13\cdot13\cdot13}{\binom{52}{5}}$$

Probability of choosing 6 cards, and having more than 1 from each suit, now we could have suits numbering $3,1,1,1$ or $2,2,1,1$:

$$\text{case 2}=\frac{\binom{4}{2}\binom{13}{2}\binom{13}{2}\cdot13\cdot13}{\binom{52}{6}}$$


#### 2
Choose 26 cards from a 52 card deck. What is the probability that there are at least 2 cards from each suit. To solve this we will is solve for the probability of its complement, i.e. the probability of the union of the event that each suit has less than 2 cards.  First we can ask what is the probability of getting less than 2 (i.e. 1 or 0) cards from a particular suit, say diamonds:

$$P(\diamondsuit_{0,1})=\frac{\overbrace{\binom{52-13}{26}}^{\text{no }\diamondsuit}+\overbrace{13}^{1\diamondsuit}\overbrace{\binom{52-13}{25}}^{25\text{ non-}\diamondsuit}}{\binom{52}{26}}$$

Now consider the intersection of two of these events, say for diamonds and hearts:

$$P(\diamondsuit_{0,1}\cap{\heartsuit}_{0,1})=\frac{\overbrace{\binom{52-13}{26}}^{\text{no }\diamondsuit}+\overbrace{13}^{1\diamondsuit}\overbrace{\binom{52-13}{25}}^{25\text{ non-}\diamondsuit}}{\binom{52}{26}}$$

Also notice that it is impossible for 3 suits, and thus 4, to have less than 2 cards each and still add to 26. And so, the final inclusion-exclusion expression is:

$$P({\diamondsuit}_{0,1}\cup{\heartsuit}_{0,1}\cup{\spadesuit}_{0,1}\cup{\clubsuit}_{0,1})=\frac{4P({\diamondsuit}_{0,1})-\binom{4}{2}P({\diamondsuit}_{0,1}\cap{\heartsuit}_{0,1})+0-0}{\binom{52}{26}}$$

#### Blackjack
Probability that 2 cards from a 52 card deck give a blackjack (ace and a {10,J,Q, or K})?

$$\frac{4\cdot(4+4+4+4)}{\binom{52}{2}}$$

## Birthday Paradox w/ Poisson Distribution
#### Birthday Paradox $n=23$
For 23 people, what is the probability that at least 2 people share the same birthday? We can compute the complement, that nobody shares a birthday, giving us:

$$1-\frac{365\cdot364\cdot363\cdots(365-22)}{365^{23}}=1-\frac{365!}{365^{23}(365-21)!}$$

#### Poisson Approximation
We have $\binom{23}{2}$ pairs with an expected number of pairs $\lambda$ sharing the same birthday:

$$\binom{23}{2}\frac{1}{365}=\lambda\approx \ln 2$$

Assuming the Poisson distribution, the probability that that no pair has the same birthday, $k=0$, is:

$$P(\text{no birthdays shared})\approx P(X=k)=\frac{\lambda^k}{k!e^\lambda}=\frac{\lambda^0}{0!e^\lambda}=e^{-\lambda}$$

Now we can solve for $\lambda$ by setting it equal to $50\%$ which corresponds, almost, to $n=23$:

$$e^{-\lambda}=\frac{1}{2}\implies \lambda = \ln 2$$

#### Poisson Approximation w/ Triple Birthdays
What is the number of people $n$ such that the probability at least 3 people share a birthday is 50%?

$$\binom{n}{3}\frac{1}{365^2}=\lambda$$

When we set $\lambda$ equal to the probability that no three people share a birthday (same as above) we get approximately the same answer:

$$e^{-\lambda}=\frac{1}{2}\implies \lambda=\ln 2$$

Now we can solve for $n$ like so:

$$\lambda=\binom{n}{3}\frac{1}{365^2}=\ln 2\implies n\approx84$$

#### An Exact Solution
What, exactly, is the probability that among 84 people there are no shared birthdays? We calculate each case where only pairs of birthdays happen.

$$\begin{align*}\underbrace{\frac{365!}{365^{84}(365-84)!}}_{k=0}&+\underbrace{\binom{84}{2}\frac{365!}{365^{84}(365-85)!}}_{k=1}\\
&+\underbrace{\frac{\binom{84}{2}\binom{82}{2}}{2!}\frac{365!}{365^{84}(365-86)!}}_{k=2}\\
&+\underbrace{\frac{\binom{84}{2}\binom{82}{2}\binom{80}{2}}{3!}\frac{365!}{365^{84}(365-87)!}}_{k=2}+\cdots\\
&=\sum_{k=0}^{42}\frac{\binom{84}{2}\binom{82}{2}\cdots\binom{84-2k+2}{2}}{k!}\frac{365\cdot364\cdots(282+k)}{365^{84}}
\end{align*}$$

*Where $k$ is how many pairs share a birthday.*
