## Stop Words
These are common or useless words that are filtered out before processing. Things like 'a', 'the', 'is' etc. For example, google filters out many stop words before querying as they usually don't help in finding relevant info.

## Tokenization
Not new to a cs student but in NLP this is a more nuainced topic. Because with natural language it is not always clear what delimits different tokens or words. Spaces and punctuation for english seems standard but what about single quotes? What if they're part of a contraction? Etc. Thankfully there are sufficient libraries for this purpose.

## Stemming
**Stemming** is the grouping of families of words into equivalence classes by, essentially, chopping them off at some point in the word. walking, walks and walker might all be chopped to walk. 

This is a nice example but sometimes a family like arguing, argue, and arguer, might be chopped to argu. This is alright though as the particular names of the equivalence classes aren't usually important, its the words (and thus meaning) they represent.

A more advanced but less broad version of this is **lemmaization** that seeks to, via morphology and linguistics, properly reduce words into their root forms (their lemmas) taking into account context and part of speech. this is a much harder problem and is still open really.

## Bigram
Bigrams are the $n=2$ case of $n$-grams. They are ordered pairs of words that appear next to each other in a corpus. Counting these occurrences can give us a discrete probability distribution:

$$P(w_n|w_{n-1})=\frac{P(w_n,w_{n-1})}{P(w_{n-1})}$$