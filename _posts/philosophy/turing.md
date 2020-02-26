---
header:
  overlay_image: /assets/images/philosophy/philosophy-splash.jpg
  caption: "[__The School of Athens__](https://en.wikipedia.org/wiki/The_School_of_Athens) by Raphael"
title: On Turing's "Computing Machinery and Intelligence"
date: 2019-02-09
excerpt: "My thoughts and comments on Alan Turing's seminal 1950 paper."
categories:
  - posts
tags: 
  - philosophy
  - artificial-intelligence
---

## Background
These are my thoughts, summary, and possibly a bit more, on Alan Turing's seminal 1950 paper ["Computing Machinery and Intelligence"](https://academic.oup.com/mind/article-pdf/LIX/236/433/9866119/433.pdf). Each section (denoted by §) of this post corresponds to the same titled section of the paper.

<!-- (http://phil415.pbworks.com/f/TuringComputing.pdf) -->

As a quick background, the paper was published in the philosophy journal *Mind* in 1950 and laid out a method of testing the 'intellectual capabilities' of a machine: the Turing test. The paper is a cornerstone of artificial intelligence, cognitive science, and the philosophy of the mind. Even further, the Turing test has become a mainstay of popular culture and science fiction.

<!--more-->

## §1. The Imitation Game
Turing wastes no time in posing the question of interest: "Can machines think?" but then immediately points out that key to this question is the definition of 'machine' and 'think'. To avoid the murky issue of nailing down such definitions, Turing proposes an experiment called the *imitation game* or, as we know it today, the **Turing test**. The rules of the game are quite simple:

- There are two players $A$ and $B$ and an interrogator.
- One of the two players is a computer and the other a human.
- It is the interrogator's job (also a human) to determine which of the two is the computer and which the human.
- To that end, the interrogator is able to communicate with $A$ and $B$ via text (a chatroom, teleprompter, etc.) and ask them any question they please.

It is with this Turing test that we can rephrase our initial question of "Can a machine think?" to the more unambiguous "Can a machine fool the interrogator into thinking it is a human?" Of course, this still leaves 'machine' undefined but Turing will address that in §3.

## §2. Critique of the New Problem
Here Turing explains that doing the test over text abstracts away the physical formalities of fooling a human to thinking a machine isn't a robot. Remember, we are concerned with the "intellectual capacities of a man" not the physical ones. Of course, the interrogator can question the player's physical aspects, but the player is under no obligation to tell the truth.

Another important point here is that there may be some game theoretic trickery going on with the test, leading to the best strategy for the computer *not* being to imitate a human. While this seems unlikely, we will simply assume that the computer's best strategy to be labeled a human by the interrogator is to imitate one.

## §3. The Machines concerned in the Game
It is in this paragraph that Turing addresses what constitutes a 'machine' that can take part in the imitation game. After mulling the possibility of simply rearing a human (maybe even in such a way as to have arisen from a single cell and not normal procreation), Turing restricts the kind of machine we will be focusing on to the **universal Turing machine** or, as he refers to it in the paper, the **digital computer**.

The reader may, at first glance, think this to be too limiting a restriction to our question, but they would be wrong. Indeed the mathematical idealization that is the universal Turing machine, realized by electronic digital computers, represents the most general\* of information manipulation. The very notion of computation is defined by them. Any 'thinking' machine one could come up with (that could be constructed) would *necessarily* be less than or equivalent to a Turing machine.[^f1]

**

### *Regarding Quantum Computers
In the time since Turing has written this paper an even more general model of computation has been discovered, namely the **quantum Turing machine**. This model of computation is concerned with the manipulation of quantum information and, unless some reality shattering new physics is discovered, it would appear that this is the most general notion of computation in the universe (more on that below).

That said, while quantum computers *are* more general than classical ones, they still cannot compute anything a classical one can't (in theory). The only difference between them is that quantum computers can solve a particular subset of problems, called BQP, faster than any classical computer.

Why I put 'in theory' in parenthesis above is because while the difference between quantum and classical is one of efficiency and not of computability, it is the case that algorithms that would take longer than the lifespan of the universe to run on a classical computer could run in a tractable time on a quantum one. That said, while this *quantum speedup* is real and has real world implications on what problems humanity could possibly solve, that speedup is most likely not necessary for solving the Turing test. Even if it was, we can just as well prepend 'quantum' to all instances of 'computer' in the paper and continue without a worry.

### Regarding the Computation of the Universe
Taking quantum computing further, I'd argue that all things in the universe are computable. Indeed, quantum physics has shown us that there are only 2 types of events that can occur in the universe: 1) the *deterministic* unitary transformation of a quantum system and 2) the *indeterministic* collapse of these quantum systems described only by probabilities. This is exactly what a quantum algorithm is: a sequence of unitary transforms and measurements (i.e. collapses). It would stand to reason, then, that all real world phenomena are computable, that is, describable via some algorithm, even thought itself (unless you believe that it is something immaterial and thus not bound by the laws of physics, a ridiculous supposition that I tackle in my paper [*"On the CTD Principle's Implications for the Mind"*](\hw\Spring%202019\Ghost%20in%20Machine\ctdpaper\main.pdf))

*In regards to the gap between the uncountably infinite dimensional states real world quantum phenomena can hold as opposed to the finite dimensional states of quantum computers, I would qualify my statement as "all things in the universe are computable to a desired precision." Although I may not even need such a qualification if there are hard limits on the scales that can be observed.*

All that said, this is probably overkill for our goal of simply imitating human conversation. Putting aside the fact that such a program is mathematically guaranteed to exist, I think the answer to the more interesting question of whether humans can empirically create such a program is a resounding "most likely".

## §4. Digital Computers
Here Turing, sparing the reader the details, describes how a digital computer works using a simplified von Neumann model, i.e. using the concepts of store, executive unit, and control as well as conditionals and looping. The instructions such a machine could perform are very simple ones: write a 0 here, multiply these two numbers and store the result here, if there is a 1 here jump to this instruction, etc. I too will spare you the details as I don't feel it necessary to reiterate the rudiments of computing's foundations.

A key take away of this exposition is that anything a computer can do a human could do as well, just much more slowly. Also of note, Turing briefly defines **programming** in this section:
> "To 'programme a machine to carry out the operation A' means to put the appropriate instruction table into the machine so that it will do A."

Indeed the programming we do today on our computers is, in a mathematically formal sense, equivalent to setting up the instruction table of a Turing machine.

In the next paragraph, Turing briefly touches on the notion of probabilistic Turing machines. That is, Turing machines that can generate random numbers. This is something a normal, deterministic Turing machine cannot do. Such machines are more general models of computation than plain old Turing machines but, as I've mentioned before, are a subset of the even more general quantum Turing machine. As such, they really don't have any bearing on the rest of the paper.

After this, Turing notes that the notion of a 'digital computer' is not a new one, and goes back all the way to Charles Babbage and his plans for an [*Analytical Engine*](https://en.wikipedia.org/wiki/Analytical_Engine) in 1837. His computer, however, was unfortunately never realized as he failed garner sufficient funding. In particular there wasn't much of a need for digital computers back in the 1800s, especially compared to Turing's era of code breaking brought on by WWII.

Turing makes special note of the fact that, despite being totally mechanical rather than electrical like modern computers, the analytical engine is totally equivalent to any other digital computer. He does this because, apparently, some people attached special importance to the fact that both the human nervous system and digital computers are electrical. The existence of mechanical computers, then, rids us of any connection between the two based on some superstitious view of electricity. That said, it is no surprise that both nervous systems and digital computers use electricity as both systems require 'fast signaling' as Turing puts it.

## §5. Universality of Digital Computers
### Discrete State Machines
Here Turing goes on to tell us that a Turing machine is a type of **discrete state machine** and elaborates on this concept. To that end, an important point he makes is that, given the inputs and current state of such a machine, its future behavior is fully determined. He likens this to the Laplacian view that if one knew the current state of the entire universe (the position and velocities of all particles, all forces, etc.), they could use classical mechanics to calculate the future. This idea is called Laplace's demon. The difference here, Turing notes, is that constructing a finite discrete state machine is quite a bit more plausible then measuring the entire state of the universe.

*Of course, our modern view of physics doesn't allow for a Laplacian demon as, even if one got around the relativistic ambiguity of 'the current state of the universe', one would also have to contend with the fact that, on quantum scales, the universe and its laws are probablistic.*

Another important point he makes is that, unlike the regular continuous states we see in nature, these discrete states are resistant to small changes, i.e. they are not chaotic. Utilizing the Laplacian demon analogy, he notes that something as small as an electron being in a slightly different position might lead to radically different results in the calculation of the universe's future state (a phenomena commonly referred to as the butterfly effect).

Discrete state machines don't suffer from this problem as it is easy to distinguish their states from one another due to there being a finite (or in the case of Turing machines, *countably* infinite) number of them. An obvious example of this is the representation of 0 and 1 in digital computers as electrical voltages. Even if a voltage that was neither 0 nor 1 was registered, it could be reasonably assumed that the intended voltage is whatever is closer to either of the valid states ($0.3\approx0$, $0.9\approx1$).

### Universal Turing Machines
Moving along, Turing now takes a quick detour to talk about the number of representable states in a contemporary (1950) digital computer. He uses the 'Manchester Machine', the first electronic stored-program computer as a measuring stick. It had 174,380 bits (~21.8 kb) of storage meaning it could represent $2^{174380}\approx10^{52500}$ different states.

Despite this complexity, we've established above that it should be possible to predict what this computer will do by simply having a copy of its instruction table and current state. And if a human could compute the future states of this machine via the table, why not another computer:

>"There is no reason why this calculation should not be carried out by means of a digital computer. Provided it could be carried sufficiently quickly the digital computer could mimic the behavior of any discrete state machine."

And with this Turing introduces us to the notion of a **universal Turing machine**, a Turing machine that can simulate any other Turing machine, even themselves. Digital computers, like the Manchester machine, are physical realizations these.

A useful consequences of this is that any computational task can be done using a single device with sufficient resources. There is no need, in principal, to create new and different computers for different tasks as they are all computationally equivalent.

*Indeed you can reasonably think of your desktop computer as a universal Turing machine, and the stored programs it runs as simulated Turing machines. No need to buy a powerpoint machine when its program code (i.e. instructions) can be stored and ran (i.e. simulated) instead.*

Turing ends this section by simply restating the question posed in §3 "are there imaginable digital machines that can do well in the imitation game?" to the following, as he's shown, equivalent question:

> "Let us fix our attention on one particular digital computer $C$. Is it true that by modifying this computer to have an adequate storage, suitably increasing its speed of action, and providing it with an appropriate programme, $C$ can be made to play satisfactorily the part of $A$ in the imitation game, the part of $B$ being taken by a man?"

We can see that our question of interest is becoming more and more concrete.
<!-- That said, I feel like the Turing machine description was already sufficient. -->

## §6. Contrary Views on the Main Question
At this point Turing is finally done providing the necessary background in §3-§5 and can now proceed to the philosophical content of the paper. Namely, we can now discuss whether a machine *can* indeed do well in the imitation game and how that relates to the original question of "Can a machine think?"

Before Turing continues to the possible objections, he gives his own opinion on the question:
> I believe that in about fifty years' time it will be possible, to programme computers, with a storage capacity of about $10^9$, to make them play the imitation game so well that an average interrogator will not have more than 70 per cent chance of making the right identification after five minutes of questioning.

Note that 50 years from the time of writing is the year 2000 and, while storage has certainly come a far way, his other predication was certainly off. We have only recently begun to understand the techniques, namely machine learning and natural language processing, that could make such a prediction come true. That said, with the giant strides made in these fields everyday, it may be the case that Turing will only be 25 to 30 years off the mark. But hey, my prediction might be just as off.

More interestingly, at least from a philosophical perspective, is Turing's response to whether machines can "think":
>The original question, "Can machines think?" I believe to be too meaningless to deserve discussion. Nevertheless I believe that at the end of the century the use of words and general educated opinion will have altered so much that one will be able to speak of machines thinking without expecting to be contradicted.

While it is hard to judge exactly what Turing's sentiment is from this small passage, I am in total agreement with him. In particular, I too imagine that by the time artificial intelligences are advanced enough to emulate human behaviors and intellect, people will inevitably personify them, just as we personify other humans. In such a future, it seems inevitable that we will associate the same ideas like 'thinking' and 'feeling' to machines just as we do to humans.

And indeed this should be the case. These robots, just like humans, are totally determined machines that run based off of totally physical (and crucially, computable) processes. There is no room for anything that could differentiate a computer's 'thoughts' from that of a human other than one being made of flesh and the other silicon. Even then, that flesh could be simulated.

The notion of 'thinking', however defined, as anything special or reserved for humans is certainly nothing but an evolved/culturally learned propensity for humans to think of themselves as possessing some ephemeral 'soul' or 'free will'. To this sentiment I point to the byproduct theory of religion.

In any case, we now move on to the second half of the paper: the objections. Turing considers 9 in total and, after each, provides his rebuttal.

<details>
<summary><h4 class="inline">1. The Theological Objection</h4></summary>

<p>Turing phrases the theological objection as follows:</p>

<blockquote>Thinking is a function of man's immortal soul. God has given an immortal soul to every man and woman, but not to any other animal or to machines. Hence no animal or machine can think.</blockquote>

<p>This argument is clearly shaky and we can see this by simply considering the arbitrary distinction between man and animal. Turing says he might be a little more sympathetic if they drew the line between animal and machine and not man and everything else. Moreover, the fact that different religions have different views on this makes the objection seem even more arbitrary.</p>

<p>Besides these immediate pushbacks, Turing attempts to level with the type of person who might make this objection in theological terms. He says that if God was really omnipotent he should be able to give animals, or machines, souls as long as they had the capacity for such (e.g. a particular mutation in the animal's brain or complex enough programming in the machine).</p>

<blockquote>In attempting to construct such machines we should not be irreverently usurping His power of creating souls, any more than we are in the procreation of children: rather we are, in either case, instruments of His will providing mansions for the souls that He creates.</blockquote>

<p>All that said, Turing still notes that he is 'not impressed' by theological arguments of any kind. He gives the example of the many inconsistencies in the Bible about the history and mechanics of the earth. In particular the Copernican theory of geocentrism.</p>

<p>I applaud Turing's attempt to help rationalize the notion of machine thinking to a religious reader. I think it should be quite clear that the very notion of a soul (and all things theological) is nothing but a product of folk psychology. With that folk psychology being propped up by evolution, culture, and antiquated philosophy. (See my paper <a href="\hw\Spring%202019\humannaturepaper\paper.pdf"><i>"On Bloom's "Is God an Accident?""</i></a>)</p>
</details>

<details>
<summary><h4 class="inline">2. The 'Heads in the Sand' Objection</h4></summary>

<blockquote>"The consequences of machines thinking would be too dreadful. Let us hope and believe that they cannot do so."</blockquote>

<p>While nobody would actually phrase their objection like this, it certainly captures the underlying thought behind many people's apprehension of considering 'thinking' machines. If humans are not unique in their capacity to think, what makes us superior? Nothing, it would seem. We can see that this objection is closely connected to the first (and equally ridiculous).</p>

<p>Turing, quite rightly so, doesn't feel the need to defend against this objection, sentiment really, and even quips:</p>

<blockquote>I do not think that this argument is sufficiently substantial to require refutation. Consolation would be more appropriate: perhaps this should be sought in the transmigration of souls.</blockquote>

<!-- *At least I think he meant it to be a quip...* -->

</details>

<details>
<summary><h4 class="inline">3. The Mathematical Objection</h4></summary>

<p>This objection regards the fact that, as Gödel showed, any consistent logical system has statements that it cannot prove. Turing phrases this in terms of his own result on the halting problem, that is to say, there exists problems that a Turing machine could not solve. This, the argument posits, shows a deficiency in computer thinking where there appears to be none in human thinking.</p>

<p>Turing rebuttals that while any Turing machine has limitations, any importance to this fact would be accompanied by an underlying assumption that humans don't also have these limitations. Humans also give wrong answers much of the time.</p>

<blockquote>There would be no question of triumphing simultaneously over all machines. In short, then, there might be men cleverer than any given machine, but then again there might be other machines cleverer again, and so on.</blockquote>

<p>Turing gives a compelling justification but, personally, I think he can take it much farther. This particular objection really boils my blood as it seem so ridiculous. Of course there are unsolvable and unprovable problems. Gödel indeed showed that there is no consistent system (of useful power) that can simultaneously prove its consistency. But you'd be crazy to think that humans, physical systems, are above these limitations. If they were they'd be bona fide hypercomputers (putting this in terms of Turing's results) and we could use human minds to disprove Gödel and prove unprovable statements.</p>

<p>Humans thoughts and actions don't run into these logical limits because humans don't make true/provable statements. They are simply biological systems that respond to stimuli. Anything a human can do or be is under the purview of computation as they are totally physical systems. Just because a human mind doesn't have a Von Neumann architecture doesn't mean it can't be simulated by one, nor does it give it some magical power over them.</p>

<p>Some philosophers, who don't understand the physical significance of computation, point to humans' ability to change goals, think about many things at once, or some other feature of the mind, and that because the computer on their desktop doesn't seem to do those things that humans have some true physical advantage over them. This is simply not true. A human being changing goals or realizing it made an error is also just a series of computations. Only in that case those computations were setup by evolution to have those features. A computer could just as well be programmed to do the same thing. There's no magical hyperturing 'soul' at the helm allowing the human mind to 'transcend' computation. If you believe that then you might as well tout objection 1.</p>

<p>In regards to the nature and limitations of the human mind, I point once again to my <a href="\hw\Spring%202019\Ghost%20in%20Machine\ctdpaper\main.pdf"><i>paper</i></a> on the CTD Principle and how it implies that humans, and everything else for that matter, are <i>necessarily</i> computable.</p>
</details>

<details>
<summary><h4 class="inline">4. The Argument from Consciousness</h4></summary>

<p>Turing summarizes this objection via a quote by Professor Geoffrey Jefferson:</p>

<blockquote>"Not until a machine can write a sonnet or compose a concerto because of thoughts and emotions felt, and not by the chance fall of symbols, could we agree that machine equals brain-that is, not only write it but know that it had written it. No mechanism could feel (and not merely artificially signal, an easy contrivance) pleasure at its successes, grief when its valves fuse, be warmed by flattery, be made miserable by its mistakes, be charmed by sex, be angry or depressed when it cannot get what it wants."</blockquote>

<p>Turing recognizes this as a flat out denial of the Turing test and notes that, at least taken to the extreme, Lister's view is that of the solipsist. That is to say "the only way by which one could be sure that machine thinks is to be the machine and to feel oneself thinking."</p>

<p>This point of view, while understandable, is hardly productive nor is it what we (I assume) usually believe. Humans usually believe that the humans around them who seem to have internal thoughts and feelings, which can't be verified, really do have them. As Turing puts it we "have the polite convention that everyone thinks".</p>

<p>Turing gives Jefferson, and those who hold similar views, the benefit of the doubt and assume they too hold this polite convention. If this is the case he believes it is possible to sway their opinions on the matter by demonstrating that a computer could actually demonstrate intelligence <i>viva voce</i>. That is, via an oral interrogation:</p>

- Interrogator: In the first line of your sonnet which reads "Shall I compare thee to a summer's day," would not "a spring day" do as well or better?
- Witness: It wouldn't scan.
- Interrogator: How about "a winter's day," That would scan all right.
- Witness: Yes, but nobody wants to be compared to a winter's day. 
- Interrogator: Would you say Mr. Pickwick reminded you of Christmas?
- Witness: In a way.
- Interrogator: Yet Christmas is a winter's day, and I do not think Mr. Pickwick would mind the comparison.
- Witness: I don't think you're serious. By a winter's day one means a typical winter's day, rather than a special one like Christmas. 

<p>Turing believes that Jefferson might be swayed if a computer demonstrated such an exchange.</p>

<p>All that said, Turing makes a point of noting that he still thinks there are many mysteries regarding consciousness and that these need to be solved before the object this paper can be truly addressed.</p>

<p>Personally I believe that there are fewer mysteries of consciousness than we think. We truly are just bags of flesh controlled by neurological, biological, chemical, and ultimately physical interactions. The real 'hard problem of consciousness' is why we believe in such fantasies as phenomenal consciousness, souls, and =other superstitions. This is partially answered by the byproduct theory (see Bloom), but a more sufficient answer must be provided by neuroscientist as to why we tell ourselves we are somehow different than other physical systems. This would amount to an <i>illusionist</i> theory of mind (see Frankish).</p>
</details>

<details>
<summary><h4 class="inline">5. Arguments from Various Disabilities</h4></summary>

<p>Here Turing considers a whole class of objections. THey take the following form:</p>

<blockquote>"I grant you that you can make machines do all the things you have mentioned but you will never be able to make one to do $X$."</blockquote>

<p>Where $X$ is something like:</p>

<blockquote>"Be kind, resourceful, beautiful, friendly, have initiative, have a sense of humour, tell right from wrong, make mistakes, fall in love, enjoy strawberries and cream, make some one fall in love with it, learn from experience, use words properly, be the subject of its own thought, have as much diversity of behaviour as a man, do something really new. "</blockquote>

<p>Turing goes to say that most of these objections are based on a flawed induction. That is to say, people have only ever known machines to be able to serve narrow purposes and are totally useless in any other domain. Thus all computers must be like this. This reasoning is a subconscious facet of human reasoning and so it is no surprise that humans can't imagine or believe computers could do these things as they've never seen any computer do anything similar.</p>

<p>Interestingly Turing claims that "[m]any of these limitations are associated with the very small storage capacity of most machines." And while it is probably true that a copious amount of storage space is a prerequisite to any impressive intelligent behavior displayed by a computer, recent advances in AI have showed us that its not the whole story. It would seem that the methods by which we process and make sense of data are just as important, if not more important, than our capacity to collect and store that data. We have millions of books digitized yet, despite all these examples, no computer can yet produce a coherent, novel length work. Throwing more data at an a particular machine learning model can only do so much.</p>

<p>Moving on though, Turing notes that some of the objections of this form deserve special remarks. First is the claim that, unlike humans, "machine cannot make mistakes". Turing clears up this confusion by delineating two different kinds of 'mistakes'. <i>Errors of functioning</i> being a fault in the computer's hardware or programming, and <i>errors of conclusion</i> being when the computer spits out an output (which we interpret to mean represent truth bearing statement/conclusion) that isn't correct.</p>

<p>It is simple to see that computers can be programmed to be 'wrong'. I could, as Turing puts it, make a program that just spits out $0=1$. The conclusion the computer is making is false, but it is functioning correctly as it was programmed to give that output. As for the other type of error, we must make it clear that we are discussing the mathematical idealization that is the Turing machine and, as such, they <i>cannot</i> make make these errors. While its true that any physical realization of a Turing machine, like your phone, <i>can</i> make errors of functioning (e.g. a cosmic ray hitting your phone and flipping a bit), these are purely engineering concerns and shouldn't have any bearing on our philosophical consideration. And with sufficient engineering, we can always minimize the number of such mistakes that occur anyway.</p>

<p>Similarly, the errors humans make are errors of conclusion. We often make wrong conclusions based on faulty information or just bad programming (i.e. education). It is impossible for us to make an error of functioning, however, because we are functions of the matter we are comprised of, all of which invariably follows the laws of physics.</p>

<p>Another interesting claim is that "a machine cannot be the subject matter of its own thoughts." This isn't the case, however, as it is totally for a universal Turing machine to simulate itself. You can try this by emulating your PC on itself. The emulation will certainly run slower, but it is doable nonetheless.</p>

<!-- Consider a computer trying to solve the equation $2x=5$. If we consider that equation as part of its 'subject matter' than it seems clear that a computer that can reason about its own behavior (e.g. to help predict what altering its structure will do) would have itself as part of is subject matter. There is nothing paradoxical about this. -->

<p>Turing wraps up this section by noting that this objection is mostly just the argument from consciousness one in disguise. He says this because even if we do make a machine that can, or at least appears to, be able to do $X$, it probably won't convince the objectors. They will simply claim that is nothing but the 'chance fall of symbols' and that it is not <i>truly</i> performing $X$, whatever that means.</p>
</details>

<details>
<summary><h4 class="inline">6. Lady Lovelace's Objection</h4></summary>

<p>Here Turing addresses the objection that computers are incapable of 'originality' or that they can't 'take us by surprise'. He points to a quote by Ada Lovelace in regards to the analytical engine:</p>

<blockquote>"The Analytical Engine has no pretensions whatever to originate anything. It can do whatever we know how to order it to perform. It can follow analysis; but it has no power of anticipating any analytical relations or truths."</blockquote>

<p>To this Turing says that machines take him by surprise all the time. Granted this is because he does not carry out the calculations needed to predict its behavior by hand. But even in this case, Turing argues that "[t]here is nothing new under the sun." Everything is a product of the cause and effect of general principles. Human minds are no more free from this than any other clump of matter. Indeed, with sufficient time and the initial conditions, one could simulate even a human mind on a computer or even by hand.</p>

<p><i>A modern objector might point to quantum mechanics as producing indeterministic behavior that cannot be deterministically computed but, this is easily dealt with by simply considering the probability distribution of different thoughts a person might have rather than just one thought. On top of this, the human mind is most likely not sensitive enough quantum fluctuations to make this an issue considering it operates on the level of neurons, which are many orders of magnitude larger than anything quantum.</i></p>

<p>Turing also notes that Lovelace had no context nor evidence to think that a computer could replicate human behaviors and originality. He points out that he has the benefit of recent advancements in science and biology and can see that the human brain is quite similar to a computer. Likewise, contemporary advances in topics like machine learning give us even greater insight than Turing had to the nature of intelligence and its relation to computation. We cover this topic in the next section.</p>
</details>

<details>
<summary><h4 class="inline">7. Argument from Continuity in the Nervous System</h4></summary>



</details>

<details>
<summary><h4 class="inline">8. The Argument from Informality of Behaviour</h4></summary>



</details>

<details>
<summary><h4 class="inline">9. The Argument from Extrasensory Perception</h4></summary>



</details>

## §7. Learning Machines
The beginnings of AI. some may say this passage is the start of AI (or at least computational based AI)


edit section 3 machine learing i think i interpreted that incorrectly.
### Regarding Machine Learning
Another interesting point Turing made when considering what machines would be applicable is:

> "...to allow the possibility that an engineer or team of engineers may construct a machine which works, but whose manner of operation cannot be satisfactorily described by its constructors because they have applied a method which is largely experimental."

To any computer scientist of the modern age, a single thought comes to mind when reading that passage: **machine learning**. In particular, artificial neural networks and deep learning. These relatively new, at least in practice, models of computation have proven to be able to tackle tasks 'classical AI' could never have hoped to accomplish. From diagnosing patients, writing poetry, composing music, and driving cars, there have been few domains untouched by the rise of machine learning in our society, and those few will invariably become even fewer. That Turing might even have had an inkling of such a possibility is incredible. Due to the nature of human intelligence, that is, an intelligence cobbled up by the random statistical processes of evolution and culture, techniques where we do not explicitly know/program our machines (a la machine learning) seem all but necessary to solve the Turing test.

<!-- footer -->

[^f1]: In fact strictly less than, as the mathematical formulation of a Turing machine calls for a countably infinite amount of memory. That said, this distinction needn't concern us as humans don't require a countably infinite amount of memory to function. Moreover Turing machines can only use a finite amount of memory at one time anyway.