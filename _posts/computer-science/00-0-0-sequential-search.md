---
header:
  overlay_image: /assets/images/comp_sci/lovelaceBanner.jfif
  caption: "[__Ada Lovelace__](https://twitter.com/DocR0cket/status/962840105793835008/photo/1) by @DocR0cket"
title: Sequential Search
date: 2018-10-09
excerpt: "Defining and analyzing the sequential search algorithm."
categories:
  - posts
tags: 
  - computer-science
  - algorithms
---

**Sequential search**, or linear search, is a search algorithm implemented on lists. It is one of the most intuitive (some might even say naïve) approaches to search: simply look at all entries in order until the element is found.

Given a **target** value, the algorithm iterates through every entry on the list and compares it to the target. If they match then it is a **successful search** and the algorithm returns `true`. If the end of the list is reached and no match was found, it is an **unsuccessful search** and the algorithm returns `false`.

A useful modification of this algorithm is to return the index of the target in the list when a match is found rather than just `true`. In the case of an unsuccessful search, a special number denoting a failure would be returned instead, usually -1. This slight modification makes our output more useful, despite having no effect on the number of steps the algorithm takes. As such, we might as well implement this version instead.

## Implementation
### Pseudocode
Given a list $L$ of length $n$ with the $i$th element denoted $L_i$, and a target value denoted $T$:
<p></p>

> **for** $i$ from $0$ to $n-1$:
    <br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** $L_i=T$:<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**return** $i$<br>
**return** $-1$

### Java
````java
int search(List<T> list, T target) {
  for(int i = 0; i < list.size(); i++)
    if(target.equals(list.get(i)))
      return i;
  return -1;
}
````
Notice we used `target`'s implementation of the `equals` method rather than `list.get(i)`'s. Doing this allows us to change our definition of equality by extending `T` and overloading the method. This gives us greater flexibility in our criterion for search.
<!-- {: .notice--info} -->

<!-- ### Python
````python
def search(L, T):
  for True in range(len(L)):
    if L[i] == T:
      return True
  return False
```` -->

## Usage
Sequential search is rarely used in practice due to better alternatives such as binary search and hash tables. That said, sequential search has the advantage of being both simple to implement and not requiring the list to be sorted. As a result, it is commonly implemented on unsorted lists as they cannot leverage any better alternatives... at least not with a classical computer.[^f1]

Also, in cases where the list is small or searching is not too common, sequential search may actually prove to be a faster solution as it does not require the list in question to be sorted beforehand.

## Analysis
### Time Complexity
The basic and dominant operation of sequential search (and search algorithms in general) is comparison. Thus we can measure the running time of this algorithm by counting the number of comparisons it makes given a list of size $n$.

<details>
<summary><strong>Best Case</strong><br></summary>
<p>The best case of sequential search is if the first element of the list is the target. In this case it takes only 1 comparison to return the successful search. Thus the best case complexity is $O(1)$.</p>
</details>

<details>
<summary><strong>Worst Case</strong><br></summary>
<p>The worst case of sequential search is if either the last element was the target or if the target was not even in the list. Both cases would take $n$ comparisons, with $n$ being the size of the list in question. Thus the worst case complexity is $O(n)$.</p>

<p>But this assumes the target only appears on the list once/never. In general, it could appear $k$ times. The worst configuration for the target elements to be in is if they are all at the end of the list, in which case we would need $n-k+1$ comparisons to get to the first instance of the target. Giving us a more general worst case complexity of $O(n-k)$</p>
</details>

<details>
<summary><strong>Average Case</strong><br></summary>
The average case complexity of a search algorithm is the sum of the times it takes to search for each element divided by the number of elements. More formally:

$$\frac{s_1+s_2+\cdots+s_n}{n}=\displaystyle \sum_{i=1}^n\frac{s_i}{n}$$

<i>Where $s_i$ is the time it takes to search for the $i$th element, and $n$ is the length of the list.</i><p></p>

In sequential search, we have to perform $i$ comparisons to return $i$th element. Because of this we can write:

$$\frac{1+2+\cdots+n}{n}=\frac{n(n+1)}{2}\cdot\frac{1}{n}=\frac{n+1}{2}$$

But this assumes the target only appears once on the list. In general, it could appear $k$ times (randomly strewn about) in which case there is a more general average case:

$$\frac{n+1}{k+1}$$

Thus the average case complexity of sequential search is $O(\frac{n}{k})$ or $O(n)$ if we don't vary $k$.
<p></p>

<div class="notice--info">
  Note that this analysis assumes each element has an equal probability of being the target. This assumption is removed in one of the variations of sequential search shown below.
</div>
</details>

### Space Complexity
The algorithm is iterative, meaning the only space needed is the single variable that keeps track of the index of the current element being checked. As such, sequential search always has a constant spatial complexity $O(1)$.

We can sum this up with the following table:

|Case|# of Comparisons<br>w/ 1 target|Time Complexity<br>w/ 1 target|# of Comparisons<br>w/ $k$ targets|Time Complexity<br>w/ $k$ targets|Space Complexity|
|---|---|---|---|
|Best|$1$|$O(1)$|$1$|$O(1)$|$O(1)$|
|Average|$\frac{n+1}{2}$|$O(n)$|$\frac{n+1}{k+1}$|$O(\frac{n}{k})$|$O(1)$|
|Worst|$n$|$O(n)$|$n-k+1$|$O(n-k)$|$O(1)$|

## Variations

### Probabilistic List
Recall that our analysis of the complexity of sequential search assumed that each element in the list was equally likely (i.e a $\frac{1}{n}$ chance) to be searched for. If we remove this assumption, we are left with a more general case with the $i$th element having some probability $p_i$ of being searched for. Whenever we are analyzing the success case of the average complexity, these probabilities should all sum to 1:

$$\sum_{i=1}^n p_i=1$$

*Just like before, the failure case will always take $n$ comparisons.*

We can express the average running time of a probabilistic search algorithm like so:

$$p_1s_1+p_2s_2+\cdots+p_ns_n=\sum_{i=1}^np_is_i$$

Since sequential search takes $i$ comparisons at the $i$th element, we can rewrite this for probabilistic sequential search as:

$$p_1+2p_2+\cdots+np_n=\sum_{i=1}^nip_i$$

If we know what frequency with which certain targets are searched for, we can rearrange the list such that things with a higher probability of being searched for are near the beginning. Thereby reducing the amount of comparisons needed on average.

A way to implement this in practice might be to move recently searched items 1 place forward in the list (assuming the order of the list is not critical). This would eventually settle the list into to its ideal form, assuming the elements were searched with certain probabilities.

If we are given a particular probability distribution, we can make stronger statements about the complexity of the search. For example, if the distribution is geometric and the elements are arranged from most to least likely, the average complexity will be $O(1)$.

### Ordered List
A different assumption we can remove is that the list is unsorted. Indeed, if we instead assume that the list *is* sorted we can improve the number of comparisons linear search takes. This is because we can stop checking once we have passed a value greater than the target (although it is still $O(n)$). Here is some pseudocode:

Given a list $L$ of length $n$ with the $i$th element denoted $L_i$ the target value denoted $T$ and $L_0\le L_1\le \cdots\le L_n$:

> **for** $i$ from $0$ to $n-1$:
    <br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** $L_i\ge T$:<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if** $L_i=T$:<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **return** $i$<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**else**<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **return** $-1$<br>
    **return** $-1$

<!-- <blockquote><font color="black"><b>for</b> $i$ from $1$ to $n$:
    <br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>if</b> $L_i\ge T$:<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>return</b> $i$<br>
<b>return</b> $L_i=T$ </font></blockquote> -->

Of course, because we have stipulated that the list be sorted, there are now faster search algorithms that are available to search the list, like binary search. This obviates the use of sequential sort.

<!-- footer -->

[^f1]: Using a quantum computer, it is actually possible to sort an unordered list in $O(\sqrt n)$ time using [Grover's algorithm](https://en.wikipedia.org/wiki/Grover%27s_algorithm). Even more interestingly, non-local theories of quantum mechanics allow for this problem to be done in $O(\sqrt[3]{n})$ time. These time complexities are opposed to a classical computer, which could only hope to solve the problem in $O(n)$ time.