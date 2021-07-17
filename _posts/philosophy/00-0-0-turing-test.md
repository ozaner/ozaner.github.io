---
header:
  overlay_image: /assets/images/philosophy/philosophy-splash.jpg
  caption: "[__The School of Athens__](https://en.wikipedia.org/wiki/The_School_of_Athens) by Raphael"
title: On Turing's "Computing Machinery and Intelligence"
date: 2021-05-26
excerpt: "My thoughts and comments on Alan Turing's seminal 1950 paper."
categories:
  - posts
tags: 
  - philosophy
  - artificial-intelligence
---

## Background
The following is a summary, my thoughts, and possibly a bit more, of Alan Turing's seminal paper ["Computing Machinery and Intelligence"](https://academic.oup.com/mind/article-pdf/LIX/236/433/9866119/433.pdf). Each section, denoted by a §, of this post corresponds to the same-titled section of the paper.

<!-- (http://phil415.pbworks.com/f/TuringComputing.pdf) -->

As a quick background, the paper was published in the philosophy journal *Mind* in 1950 and laid out a method of testing the 'intellectual capabilities' of a machine: what is now known as the *Turing test*. The paper is a cornerstone of artificial intelligence, cognitive science, and the philosophy of the mind. Even further, the Turing test has become a mainstay of science fiction and popular culture.

<!--more-->

## §1. The Imitation Game
Turing wastes no time in posing the question of interest: "Can machines think?" But then immediately points out that key to this question are the definitions of 'machine' and 'think'. To avoid the murky issue of nailing down such definitions, Turing proposes an experiment called the *imitation game* or, as we know it today, the **Turing test**. The rules of the game are quite simple:

- There are two players, $A$ and $B$, and an interrogator.
- One of the two players is a computer and the other a human.
- It is the job of the interrogator, a human, to determine which of $A$ and $B$ is the human.
- To that end, the interrogator is able to communicate with $A$ and $B$ via text (e.g. a chatroom, teleprompter, etc.) and ask them any question they please.

It is with this 'Turing test' that we can rephrase our initial question of "Can a machine think?" to the more unambiguous "Can a machine fool an interrogator into thinking it is a human?" Of course, this still leaves 'machine' undefined but Turing will address that in §3.

## §2. Critique of the New Problem
Here Turing explains that doing the test over text abstracts away the physical formalities of fooling a human into thinking a machine isn't a robot. Remember, we are concerned with the "intellectual capacities of a man" not the physical ones. Of course, the interrogator can question the player's physical aspects (e.g. "are you made of flesh and bones?"), but the player is under no obligation to tell the truth.

Another important point here is that there may be some game-theoretic trickery going on with the test, leading to the best strategy for the computer *not* being to imitate a human (e.g. some sort of reverse psychology). While this seems unlikely, we will simply assume that the computer's best strategy to be labeled a human by the interrogator is to imitate one.

## §3. The Machines Concerned in the Game
It is in this paragraph that Turing addresses what constitutes a 'machine' that can take part in the imitation game. Turing initially sets out three criteria of our definition of machine:
- Permit any kind of engineering technique (no limits on what can be constructed).
- The engineering team does not have to fully understand how the machine works.
- Excludes "men born from the usual manner." (i.e. no humans)

He immediately notes, however, that it seems difficult/impossible to satisfy all three of these conditions. As a counterexample, he postulated that even if the engineering team were all of one sex, it might be possible to rear a human from a single skin cell (an impressive thought to have in 1950).

Ultimately, Turing decides to abandon the first criterion and restricts the kind of machine we will be focusing on to the **universal Turing machine** or, as he refers to it in the paper, the **digital computer**.

The reader may, at first glance, think this to be too limiting a restriction to our question. But they would be wrong. Indeed the mathematical idealization that is the universal Turing machine, realized by electronic digital computers, represents the most general\* of information manipulation. Any 'thinking' machine one could come up with (that could be constructed) would *necessarily* be less than or equivalent to a Turing machine.[^f1] (although that is a claim I'm making, not Turing.)

### *Regarding Quantum Computers
In the time since Turing has written this paper even more general models of computation have been discovered, with one in particular being the **quantum Turing machine** (QTM). This model of computation is concerned with the manipulation of quantum information and, unless some reality-shattering new physics is discovered, it would appear that this is the most general notion of computation in the universe.\*\*

That said, while quantum computers *are* more general than classical ones, they still cannot compute anything a classical one can't (in theory). The only difference between them is that quantum computers can solve a particular subset of problems, called BQP, faster than any classical computer.

Why I put 'in theory' in parenthesis above is because while the difference between quantum and classical is one of efficiency and not of computability, it is the case that algorithms that would take longer than the lifespan of the universe to run on a classical computer could run in a tractable time on a quantum one. That said, while this **quantum speedup** is real and has real-world implications on what problems humanity could possibly solve, that speedup is most likely not necessary for solving the Turing test. Even if it was, we can just as well prepend 'quantum' to all instances of 'computer' in the paper and continue without worry.

### **Regarding the Computation of the Universe
Taking quantum computing further, David Deutsch, progenitor of the QTM, argues (and I agree) that all physical phenomena in the universe are computable. Indeed, quantum physics has shown us that there are only 2 types of events that can occur in the universe: 1) the *deterministic* unitary transformation of a quantum system and 2) the *indeterministic* collapse of these quantum systems described only by probabilities. This is exactly what a quantum algorithm is: a sequence of unitary transforms and measurements (i.e. collapses). <!-- [^f2] -->

As quantum Turing machines can simulate any quantum system, it would stand to reason that all real-world phenomena are computable, that is, describable via some algorithm. We call this the Church-Turing-Deutsch (CTD) principle. <!-- I use CTD and its implications to argue against dualism in my paper [*"On the CTD Principle's Implications for the Mind"*](\hw\Spring%202019\Ghost%20in%20Machine\ctdpaper\main.pdf). -->

All that said, this is probably overkill for our goal of simply imitating human conversation. Indeed, while a program capable of doing this is mathematically guaranteed to exist in principle (as one could simply brute force simulate a human on a quantum computer), the more interesting question is whether humans could one day empirically create and run such a program. And, personally, I think the answer to that is a resounding... probably.

## §4. Digital Computers
Here Turing, sparing the reader the details, describes how a digital computer works using a simplified von Neumann model, i.e. using the concepts of store, executive unit, and control as well as conditionals and looping. The instructions such a machine could perform are very simple ones: write a 0 here, multiply these two numbers and store the result here, if there is a 1 here jump to this instruction, etc. I too will spare you the details as I don't feel it necessary to reiterate the rudiments of computation.

A key takeaway of this exposition is that anything a computer can do, a human could do as well by way of pencil and paper. It would just take much longer. Also of note, Turing briefly defines **programming** in this section:
> "To 'programme a machine to carry out the operation A' means to put the appropriate instruction table into the machine so that it will do A."

Indeed the programming we do today on our computers is, in a mathematically formal sense, equivalent to setting up the instruction table of a Turing machine.

In the next paragraph, Turing briefly touches on the notion of **probabilistic Turing machines**. That is, Turing machines that have access to random numbers. This is something a normal deterministic Turing machine cannot do. Such machines are more general models of computation than plain old Turing machines but, as I've mentioned before, are a subset of the even more general quantum Turing machine. As such, they don't have any bearing on the rest of the paper.

After this, Turing notes that the notion of a digital computer is not a new one, and refers back all the way to Charles Babbage and his plans for an [**Analytical Engine**](https://en.wikipedia.org/wiki/Analytical_Engine) in 1837. Unfortunately, however, his computer was never realized as he failed to garner sufficient funding. In particular, there wasn't much of a need for digital computers back in the 1800s, especially compared to Turing's era of code-breaking brought on by WWII.

Turing makes special note of the fact that, despite being totally mechanical rather than electrical like modern computers, the analytical engine is equivalent to any other digital computer. He does this because, apparently, some people attach special importance to the fact that both the human nervous system and digital computers are electrical. The existence of mechanical computers, then, rids us of any connection between the two based on some superstitious view of electricity. That said, it is no surprise that both nervous systems and digital computers use electricity as both systems require 'fast signaling' as Turing puts it.

## §5. Universality of Digital Computers
### Discrete State Machines
Here Turing goes on to tell us that a Turing machine is a type of **discrete-state machine** and elaborates on this concept. To that end, an important point he makes is that, given the inputs and current state of such a machine, its future behavior is fully determined. He likens this to the Laplacian view that if one knew the current state of the entire universe (the position and velocities of all particles, all forces, etc.), they could use classical mechanics to perfectly predict the future. We call this idea **Laplace's demon**[^f3]. The difference here, Turing notes, is that constructing a finite discrete-state machine is quite a bit more plausible than measuring the entire state of the universe.

Another important point he makes is that, unlike the regular continuous states we see in nature, these discrete states are resistant to small changes (i.e. they are not chaotic). Utilizing the Laplacian demon analogy, he notes that something as small as an electron being in a slightly different position might lead to radically different results in the calculation of the universe's future state (a phenomena commonly referred to as the **butterfly effect**).

Discrete state machines don't suffer from this problem as it is easy to distinguish their states from one another due to there being a range of continuous values that may correspond to them. A prototypical example of this is the representation of the 0 and 1 states in a digital computer as electrical voltages. Even if a voltage that was neither $0$ nor $1$ was registered, it could be reasonably assumed that the intended voltage is whatever is closer to either of the valid states ($0.3\approx0$, $0.9\approx1$).

### Universal Turing Machines
Moving along, Turing now takes a quick detour to talk about the number of representable states in a contemporary (i.e. 1950) digital computer. He uses the **Manchester Machine**, the first electronic stored-program computer as a measuring stick. It had $174,380$ bits (~$21.8$ kb) of storage, meaning it could represent $2^{174380}\approx10^{52500}$ different states.

Despite this complexity, we've established above that it should be possible to predict what this computer will do by simply having a copy of its instruction table and current state. And if a human could compute the future states of this machine via the table, why not another computer:

>"There is no reason why this calculation should not be carried out by means of a digital computer. Provided it could be carried sufficiently quickly the digital computer could mimic the behavior of any discrete state machine."

And with this Turing introduces us to the notion of a **universal Turing machine**, a Turing machine that can simulate any other Turing machine, even themselves. Digital computers, like the Manchester machine, are physical realizations of these.

A useful consequence of this is that any computational task can be done using a single device with sufficient resources. There is no need, in principle, to create new and different computers for different tasks as they are all computationally equivalent.

Indeed, you can reasonably think of your desktop computer as a universal Turing machine and the stored programs it runs as simulated Turing machines. No need to buy a PowerPoint machine when its program code (i.e. instructions) can be stored and ran (i.e. simulated) on your desktop PC instead.

Turing ends this section by simply restating the question posed in §3 "are there imaginable digital machines that can do well in the imitation game?" to the following, as he's shown, equivalent question:

> "Let us fix our attention on one particular digital computer $C$. Is it true that by modifying this computer to have an adequate storage, suitably increasing its speed of action, and providing it with an appropriate programme, $C$ can be made to play satisfactorily the part of $A$ in the imitation game, the part of $B$ being taken by a man?"

We can see that our question of interest is becoming more and more concrete.
<!-- That said, I feel like the Turing machine description was already sufficient. -->

## §6. Contrary Views on the Main Question
At this point, Turing is finally done providing the necessary background in §3-§5 and can now proceed to the philosophical content of the paper. Namely, we can now discuss whether a machine *can* indeed do well in the imitation game and how that relates to the original question of "Can a machine think?"

Before Turing continues to the possible objections, he gives his own opinion on the question:
> I believe that in about fifty years' time it will be possible, to programme computers, with a storage capacity of about $10^9$, to make them play the imitation game so well that an average interrogator will not have more than 70 per cent chance of making the right identification after five minutes of questioning.

Note that 50 years from the time of writing is the year 2000 and, while storage has certainly come a far way ($10^9$ bits is only $125$ MB), his other prediction was a little more off. We have only recently begun to understand the techniques, namely machine learning and natural language processing, that can make such a prediction come true. That said, I think today's technology[^f4] is more or less sufficient for a time limit of 5 minutes, assuming an average person is the interrogator and not a computer scientist who may know what to look for. Thus, taking what I said to heart, Turing may only be about 20 years off on his second prediction. Indeed, given another 10 or 15 years, we might be able to fool an interrogator for much longer, or even indefinite, periods of time.

More interestingly, at least from a philosophical perspective, is Turing's response to whether machines can "think":
>The original question, "Can machines think?" I believe to be too meaningless to deserve discussion. Nevertheless I believe that at the end of the century the use of words and general educated opinion will have altered so much that one will be able to speak of machines thinking without expecting to be contradicted.

<!-- While it is hard to judge exactly what Turing’s sentiment is from this small passage, I am in total agreement with him. In particular, I too imagine that by the time artificial intelligences are advanced enough to emulate human behaviors and intellect, people will inevitably personify them, just as we personify other humans. In such a future, it seems inevitable that we will associate the same ideas like ‘thinking’ and ‘feeling’ to machines just as we do to humans. -->

While it is hard to judge exactly what Turing's sentiment is from this small passage, I am in total agreement with him both in regards to the weak usage of the word 'think' as well as the strong one.

With regards to the weak usage, the use of phrases like "hold on, it's thinking" to refer to computers that have been computing something for a while, for example, is already commonplace. Further, we often describe deep learning algorithms, like those that generate text, art, and music, as 'thinking' or 'dreaming' whether or not we mean this seriously.

Regarding the stronger usage, I imagine that by the time artificial intelligences are advanced enough to emulate human behaviors and intellect, people will inevitably personify them just as we personify other humans. In such a future, it seems inevitable that we will associate the same ideas like 'thinking' and 'feeling' to machines just as we do to humans.

And indeed this should be the case. These programs, just like humans, are totally determined physical (and thus crucially, computable) processes. There is no room for anything that could differentiate a sufficiently advanced computer's 'thoughts' from that of a human other than one being made of flesh and the other silicon. Even then, that flesh could be simulated.

The notion of 'thinking', however defined, as anything special or reserved for humans is certainly nothing but an evolved/culturally learned propensity for humans to think of themselves as possessing some ephemeral 'soul' or 'free will'. To this sentiment, I point to the byproduct theory of religion.

In any case, we now move on to the second half of the paper: the objections. Turing considers 9 in total and, after each, provides his rebuttal. Like with the other sections, I will summarize Turing as well as provide my own commentary.

<details>
<summary><b>1. The Theological Objection</b></summary>
Turing phrases the theological objection as follows:

<blockquote>Thinking is a function of man's immortal soul. God has given an immortal soul to every man and woman, but not to any other animal or to machines. Hence no animal or machine can think.</blockquote>

<p>This argument is clearly shaky and we can see this by simply considering the arbitrary distinction between man and animal. Turing says he might be a little more sympathetic if they drew the line between animal and machine and not man and everything else. Moreover, the fact that different religions have different views on this makes the objection seem even more arbitrary.</p>

<p>Besides these immediate pushbacks, Turing attempts to level with the type of person who might make this objection in theological terms. He says that if God was really omnipotent he should be able to give animals, <i>or machines</i>, souls as long as they had the capacity for such (e.g. a particular mutation in the animal's brain or complex enough programming in the machine):</p>

<blockquote>In attempting to construct such machines we should not be irreverently usurping His power of creating souls, any more than we are in the procreation of children: rather we are, in either case, instruments of His will providing mansions for the souls that He creates.</blockquote>

<p>All that said, Turing still notes that he is 'not impressed' by theological arguments of any kind. He gives the example of the many inconsistencies in the Bible about the history and mechanics of the earth. In particular the Copernican theory of geocentrism.</p>

<p>I applaud Turing's attempt to help rationalize the notion of a machine thinking to a religious reader. I think it should be quite clear that the very notion of a soul (and all things theological) is nothing but a product of folk psychology. With that folk psychology being propped up by evolution, culture, and antiquated philosophy. (See my paper <a href="\hw\Spring%202019\humannaturepaper\paper.pdf"><i>"On Bloom's "Is God an Accident?""</i></a>)</p>
</details>

<details>
<summary><b>2. The 'Heads in the Sand' Objection</b></summary>

<blockquote>"The consequences of machines thinking would be too dreadful. Let us hope and believe that they cannot do so."</blockquote>

<p>While most wouldn't phrase their objection like this, it certainly captures the underlying thought behind many people's apprehension of considering 'thinking' machines. If humans are not unique in their capacity to think, what makes us superior? Nothing, it would seem. We can see that this objection is closely connected to, and equally ridiculous as, the first.</p>

<p>Turing, quite rightly so, doesn't feel the need to defend against this objection (sentiment really) and even quips:</p>

<blockquote>I do not think that this argument is sufficiently substantial to require refutation. Consolation would be more appropriate: perhaps this should be sought in the transmigration of souls.</blockquote>

<!-- *At least I think he meant it to be a quip...* -->

</details>

<details>
<summary><b>3. The Mathematical Objection</b></summary>

<p>This objection regards the fact that, as Gödel showed, any consistent logical system has statements that it cannot prove. Turing phrases this in terms of his own result on the halting problem, that is to say, there exist problems that a Turing machine could not solve. This, the objection posits, shows a deficiency in computer thinking where there appears to be none in human thinking.</p>

<p>Turing rebuttals that while any Turing machine has limitations, any importance to this fact would be accompanied by an underlying assumption that humans don't also have these limitations. Humans also give wrong answers much of the time.</p>

<blockquote>There would be no question of triumphing simultaneously over all machines. In short, then, there might be men cleverer than any given machine, but then again there might be other machines cleverer again, and so on.</blockquote>

<p>Turing gives a compelling justification but, personally, I think he can take it much farther. This particular objection really boils my blood as it seems so ridiculous. Of course there are unsolvable and unprovable problems. Gödel indeed showed that there is no consistent system (of useful power) that can prove its own consistency. But you'd be crazy to think that humans, physical systems, are above these limitations. If they were they'd be bona fide hypercomputers (putting this in terms of Turing's results) and we could use human minds to disprove Gödel and prove unprovable statements.</p>

<p> Humans' thoughts and actions don't appear to run into these logical limits because humans don't make true/provable statements. They are simply biological systems that respond to stimuli. Anything a human can do or be is under the purview of computation as they are totally physical systems. Just because a human mind doesn't have a Von Neumann architecture doesn't mean it can't be simulated by one, nor does it give it some magical power over them.</p>

<p>Some philosophers, who don't understand the physical significance of computation, point to humans' ability to change goals, think about many things at once, or some other feature of the mind, and that because the computer on their desktop doesn't seem to do those things, humans have some true physical advantage over them. This is simply not true. A human being changing goals or realizing it made an error is also just a series of computations. Only in that case, those computations were set up by evolution to have those features. A computer could just as well be programmed to do the same thing. There's no magical hyperturing 'soul' at the helm allowing the human mind to 'transcend' computation. If you believe that then you might as well tout objection 1.</p>

<p>In regards to the nature and limitations of the human mind, I point to my <a href="\hw\Spring%202019\Ghost%20in%20Machine\ctdpaper\main.pdf"><i>paper</i></a> on the CTD Principle and how it implies that humans, and everything else for that matter, are <i>necessarily</i> computable.</p>
</details>

<details>
<summary><b>4. The Argument from Consciousness</b></summary>

<p>Turing summarizes this objection via a quote by Professor Geoffrey Jefferson:</p>

<blockquote>"Not until a machine can write a sonnet or compose a concerto because of thoughts and emotions felt, and not by the chance fall of symbols, could we agree that machine equals brain-that is, not only write it but know that it had written it. No mechanism could feel (and not merely artificially signal, an easy contrivance) pleasure at its successes, grief when its valves fuse, be warmed by flattery, be made miserable by its mistakes, be charmed by sex, be angry or depressed when it cannot get what it wants."</blockquote>

<p>Turing recognizes this as a flat-out denial of the Turing test and notes that, at least taken to the extreme, Lister's view is that of the solipsist. That is to say "the only way by which one could be sure that machine thinks is to be the machine and to feel oneself thinking."</p>

<p>This point of view, while understandable, is hardly productive nor is it what we (I assume) usually believe. Humans usually believe that the humans around them who seem to have internal thoughts and feelings, which can't be verified, really do have them. As Turing puts it we "have the polite convention that everyone thinks".</p>

<p>Turing gives Jefferson, and those who hold similar views, the benefit of the doubt and assume they too hold this polite convention. If this is the case he believes it is possible to sway their opinions on the matter by demonstrating that a computer could actually demonstrate intelligence <i>viva voce</i>. That is, via an oral interrogation:</p>

<ul>
  <li>Interrogator: In the first line of your sonnet which reads "Shall I compare thee to a summer's day," would not "a spring day" do as well or better?</li>
  <li>Witness: It wouldn't scan.</li>
  <li>Interrogator: How about "a winter's day," That would scan all right.</li>
  <li>Witness: Yes, but nobody wants to be compared to a winter's day.</li>
  <li>Interrogator: Would you say Mr. Pickwick reminded you of Christmas?</li>
  <li>Witness: In a way.</li>
  <li>Interrogator: Yet Christmas is a winter's day, and I do not think Mr. Pickwick would mind the comparison.</li>
  <li>Witness: I don't think you're serious. By a winter's day one means a typical winter's day, rather than a special one like Christmas. </li>
</ul>
<br>

<p>Turing believes that Jefferson might be swayed if a computer demonstrated such an exchange.</p>

<p>I think this objection demonstrates well our own evolved dualist intuitions in not just the existence of 'consciousness' and 'thought', but that they exist only in those similar to us (e.g. other humans, those in the in-group, etc.) who surely have them. After all, when Turing mentioned "the polite convention that everyone thinks," it should be clear that the 'everyone' refers only to humans. Often not to animals, plants, and certainly not machines. Indeed, while in the past it might have been reasonable to think of oneself as operating at a higher level than a plant or even animal due to our cognitive abilities, language, etc, in a near future where machines are capable of all of those things, is it still reasonable to only see <i>ourselves</i> as able to have thoughts?</p>

<!-- <p>All that said, Turing makes a point of noting that he still thinks there are many mysteries regarding consciousness and that these need to be solved before this objection can be truly addressed.</p>

<p>Personally I believe that there are fewer mysteries of consciousness than we think. We truly are just bags of flesh controlled by neurological, biological, chemical, and ultimately physical interactions. The real 'hard problem of consciousness' is why we believe in such fantasies as phenomenal consciousness, souls, and other superstitions. This is partially answered by the byproduct theory (see Bloom), but a more sufficient answer must be provided by neuroscience as to why we tell ourselves we are somehow different than other physical systems. This would amount to an <i>illusionist</i> theory of mind (see Frankish).</p> -->
</details>

<details>
<summary><b>5. Arguments from Various Disabilities</b></summary>

<p>Here Turing considers a whole class of objections. They take the following form:</p>

<blockquote>"I grant you that you can make machines do all the things you have mentioned but you will never be able to make one to do $X$."</blockquote>

<p>Where $X$ is something like:</p>

<blockquote>"Be kind, resourceful, beautiful, friendly, have initiative, have a sense of humour, tell right from wrong, make mistakes, fall in love, enjoy strawberries and cream, make some one fall in love with it, learn from experience, use words properly, be the subject of its own thought, have as much diversity of behaviour as a man, do something really new. "</blockquote>

<p>Turing goes on to say that most of these objections are based on a flawed induction. That is to say, people have only ever known machines to be able to serve narrow purposes and to be useless in any other domain. Thus all computers must be like this. This sort of reasoning is standard, and indeed quite useful, to humans so it is no surprise that the average person couldn't imagine or believe computers could do these things as they've never seen any computer do anything similar.</p>

<p>Interestingly Turing claims that "[m]any of these limitations are associated with the very small storage capacity of most machines." And while it is probably true that a copious amount of storage space is a prerequisite to any impressive intelligent behavior displayed by a computer, recent advances in AI have shown us that it's not the whole story. It would seem that the methods by which we process and make sense of data are just as important, if not more important, than our capacity to collect and store that data. We have millions of books digitized yet, despite all these examples, no computer can yet produce a coherent, novel-length work. Throwing more data at a particular machine learning model can only do so much.</p>

<p>Moving on though, Turing notes that some of the objections of this form deserve special remarks. First is the claim that, unlike humans, "machine cannot make mistakes". This is a common misconception, even today, and Turing clears this up by delineating two different kinds of 'mistakes':</p>
<ul>
  <li><b>Errors of functioning</b>: a fault in the computer's hardware or programming.</li>
  <li><b>Errors of conclusion</b>: when the computer spits out an output (which we interpret to mean represent truth bearing statement/conclusion) that isn't correct.</li>
</ul>

<p>It is simple to see that computers can be programmed to be 'wrong'. I could, as Turing puts it, make a program that just spits out $0=1$. The conclusion the computer is making is false, but it is functioning correctly as it was programmed to give that output. As for the other type of error, we must make it clear that we are discussing the mathematical idealization that is the Turing machine and, as such, they <i>cannot</i> make these errors. While it's true that any physical realization of a Turing machine, like your phone, <i>can</i> make errors of functioning (e.g. a cosmic ray hitting your phone and flipping a bit), these are purely engineering concerns and shouldn't have any bearing on our philosophical consideration. And with sufficient engineering, we can always minimize the number of such mistakes that occur anyway.</p>

<p>Similarly, the errors humans make are errors of conclusion. We often make wrong conclusions based on faulty information or just bad programming (read: education). Of course, depending on what we mean by functioning properly, humans can also make errors of functioning (e.g. brain damage).</p>

<p>Another one of the claims is that "a machine cannot be the subject matter of its own thoughts." This isn't the case either, as it is totally possible for a universal Turing machine to simulate itself. After all, a universal turing machine is a Turing machine like any other. You can try this by emulating your PC on itself. The emulation will certainly run slower, with some polynomial overhead to be exact, but it is doable nonetheless.</p>

<!-- It is impossible for us to make an error of functioning, however, because we are functions of the matter we are comprised of, all of which invariably follows the laws of physics. -->

<p>And, as it turns out, a variety of the items Turing listed have been demonstrated in recent years:
<ul>
<li>Machine language models have shown the capability to use words properly to create coherent passages and even entire articles (see GPT-3)[^f3].</li>
<li>In regards to creating 'something new,' deep learning models have created original art, music, and poetry (at least as original as the art you or I could make).</li>
<li>There are documented cases of humans falling in love with machines, usually in the form of an artificial persona. Although to be fair, this is probably more a statement about human psychology rather than the capabilities of machines. We have yet to develop machines with personalities realistic enough to be truly endearing, especially enough to fall in love with (at least to my satisfaction...).</li>
</ul>

<!-- Consider a computer trying to solve the equation $2x=5$. If we consider that equation as part of its 'subject matter' then it seems clear that a computer that can reason about its own behavior (e.g. to help predict what altering its structure will do) would have itself as part of its subject matter. There is nothing paradoxical about this. -->

Turing wraps up this section by noting that this objection is mostly just objection 4 (the argument from consciousness) in disguise. He says this because even if we do make a machine that can, or at least appears to, be able to do $X$, it probably won't convince the objectors. They will simply claim that is nothing but the "chance fall of symbols" and that it is not <i>truly</i> performing $X$, whatever that means.</p>
</details>

<details>
<summary><b>6. Lady Lovelace's Objection</b></summary>

<p>Here Turing addresses the objection that computers are incapable of 'originality' or that they can't "take us by surprise". He points to a quote by Ada Lovelace in regards to the analytical engine:</p>

<blockquote>"The Analytical Engine has no pretensions whatever to originate anything. It can do whatever we know how to order it to perform. It can follow analysis; but it has no power of anticipating any analytical relations or truths."</blockquote>

<p markdown="1">To this Turing says that machines take him by surprise all the time. Granted this is because he does not carry out the calculations needed to predict its behavior by hand, but even in this case, Turing argues that "[t]here is nothing new under the sun." All our ideas are built on the 'shoulders of giants,' so to speak, from art to science. Throwing the kitchen sink at it, we can simply note that everything is a product of the cause and effect of general principles. Human minds are no more free from this than any other clump of matter. Indeed, with sufficient time and the initial conditions, one could simulate even a human mind on a computer or even by hand.[^f5]</p>

<p>Turing also notes that Lovelace had no context nor evidence to think that a computer could replicate human behaviors and originality. He points out that he has the benefit of recent advancements in science and biology and can see that the human brain is quite similar to a computer. Likewise, contemporary advances in topics like machine learning give us even greater insight than Turing had to the nature of intelligence and its relation to computation. Using computers to not just 'follow analysis,' as Lovelace puts it, but indeed create new ideas is commonplace today. We discuss the topic of learning machines further in §7.</p>
 <!-- (a potent <a href=https://www.nature.com/articles/d41586-019-03332-7">example</a> are AIs that can (re)discover the laws of physics on their own). -->
</details>

<details>
<summary><b>7. Argument from Continuity in the Nervous System</b></summary>
<p>This objection hinges on the fact that the nervous system is "certainly not a discrete-state machine", as Turing puts it, and thus a computer, being a discrete state system, could not mimic the behavior of the nervous system. In particular, the potentially chaotic behavior of a nervous system could not be accurately captured by a discrete state machine.</p>

<p>Turing counters this argument by noting that a computer <i>could</i> predict the output of some continuous device by having its output values perturbed with some probability distribution (with randomness, of course, being permitted by quantum or even probabilistic Turing machines).</p>

<p>Making this point finer though, I think we can establish a 2 point objection to this sort of argument:</p>

<p>1) A digital computer may not be able to output continuous values, but it can do any analog calculation to any desired accuracy. Any real-world process or system (e.g. a human brain) would have some practically limited precision and thus could be simulated given enough computing resources. That limitation could result from inaccuracies of measurement or, even if we somehow had a perfect measurement, we could only read a finite number of digits of the output before dying. Further, all real-world systems are ultimately quantum and this puts a hard limit on the precision a system needs before the observations are identical. And this is all assuming the human brain relies on such low-level chaos to function, which it most likely does not, making this point moot.</p>

<p>2) While a discrete system could not recreate some particular chaotic behavior perfectly, and thus presumably not at all by the butterfly effect, neither could an analog system (e.g. the brain) as it would have to be free of any perturbation from the environment (an impossible feat due to quantum mechanics). Put another way, the inaccuracies and errors that come from discretizing the nervous system in our hypothetical simulation of it may as well be indistinguishable from the random noise that pervades and affects real-life nervous systems.</p>
</details>

<details>
<summary><b>8. The Argument from Informality of Behaviour</b></summary>
The objection, in Turing's words, goes like this:

<blockquote>"If each man had a definite set of rules of conduct by which he regulated his life he would be no better than a machine. But there are no such rules, so men cannot be machines."</blockquote>

<p>Phrased differently it's something like, "a computer works by just following a set of instructions for each situation they could be in. Humans don't follow some set collection of rules depending on what situation they're in and thus cannot be machines."</p>

<p>The confusion the objector has can be cleared up by considering two different kinds of rules/instructions. What Turing calls 'rules of conduct' and 'laws of behavior.' A human may follow some rule of conduct for certain situations (e.g. stopping at a red light) and indeed that same human may not have a rule of conduct for certain situations (e.g. what if the stoplight is broken?), but crucially the human always follows the laws of psychology/biology/chemistry/physics. These rules are the so-called 'laws of behavior'.</p>

<p markdown="1">Taking this further, in view of the [computability of the universe](#regarding-the-computation-of-the-universe) I mentioned earlier, any particular human is equivalent to some quantum Turing machine.</p>

<p>Of course, the kind of person making such an objection may not buy that humans are purely physical, and thus follow physical laws. Indeed in their view, such a claim may amount to begging the question. In this case, Turing's response to the objection may be more suitable:</p>

<blockquote>I have set up on the Manchester computer a small programme using only 1000 units of storage, whereby the machine supplied with one sixteen figure number replies with another within two seconds. I would defy anyone to learn from these replies sufficient about the programme to be able to predict any replies to untried values.</blockquote>

<p>The point being that just because the task Turing posed is an extremely difficult one, it doesn't mean machines don't have a set of 'laws of behaviors' that they follow. We know that computers follow set laws, it just happens to be very difficult to find those laws from scratch. In the same vein, just because it is not obvious to us what 'laws of behaviors' humans follow, it doesn't mean they don't follow them.</p>
</details>

<details>
<summary><b>9. The Argument from Extrasensory Perception</b></summary>
<p>Any argument depending on ESP, telepathy, psychokinesis, or the like is clearly a ridiculous one and, if anything, is just a worse version of the theological objection. Upon first reading, I was under the impression that Turing was of a like-mind and that his inclusion of this section was tongue-in-cheek as well as maybe to cover <i>all</i> his bases. But, upon researching further, it would seem that some hold that he is indeed taking the argument somewhat seriously. This may be the result of studies by J.B. Rhine during the 1930s and 40s that seemed to provide some evidence of ESP (these results were, of course, invalidated much after Turing wrote this paper due to a variety of errors and fabricated data in the studies being revealed).</p>

<p>As such, it is conceivable that Turing, believing or not, would want to at least address this concern. In any case, we needn't bother with this objection as it doesn't really seem to be relevant anyway, at least to my eyes.</p>
</details>

## §7. Learning Machines
Turing begins this section by admitting that he has "no very convincing arguments of a positive nature to support [his] arguments." If he did, he notes, he wouldn't have spent so much time tackling the objections (i.e. making negative arguments).

### Supercritical Ideas
Turing starts by referring back to Lovelace's objection: that computers can only do what we tell them to do. He says it's as if someone 'injects' an idea into the computer (i.e. the input), it "responds to a certain extent" (i.e. computes it), and then drops into 'quiescence'. He likens it to a chord stuck on a piano, or a sub-critical pile of uranium atoms being struck causing nuclear fission and then dying out when all atoms have fissured. But what if the pile was *super*-critical? That is, the pile of uranium atoms was large enough such that when struck by a particle, it would undergo a sustained chain reaction of fission much like a nuclear reactor. Or, more dramatically, an out-of-control chain reaction leading to an explosion. (WWII ended just 5 years prior to this paper's publication so the analogy isn't as out of left field as you may think).

An idea presented to a mind will usually give rise to one or fewer ideas, what Turing would call sub-critical. But some ideas inspire us and give rise to many other ideas, generating their own ideas still. This is what Turing would call super-critical. Animal minds seem to be sub-critical. After all, they don't seem to come up with many ideas beyond basic responses to stimuli. However human minds seem super-critical, at least sometimes. Turing then uses this terminology to reframe the original question:

> "Can a machine be made to be super-critical?"

### Onions have Layers
This is all well and good, but how could one even program a mind? Or something similar enough to be called 'super-critical'? For this, Turing presents another analogy. Consider the functions of the brain we understand so well that we can describe them mechanically. An objector to the idea that the brain is indeed mechanical and not dualist in some nature might say "that's not the 'real' mind. The 'real' mind is underneath that boilerplate functionality". The best way for the scientist to rebuttal might be to look even deeper, peeling the layers of the brain back, like an onion, understanding its functions more and more. After a point though, there will be no more layers to peel back, the onion was always just layers of skin. There was no 'true' onion underneath.

Again, Turing doesn't claim this nor the last section to be convincing arguments. They just provide a way of at least conceiving of the mind as something not beyond physical construction. Especially to his contemporaries, who didn't have the benefit of decades of progress in computer science (much, of course, thanks to Turing), as well as the conceptual changes in our notion of the mind as physics and neuroscience have developed. And in any case, Turing notes that the only real proof that the Turing test may be passed is simply "waiting for the end of the century and then doing the experiment described."

### Programming a Mind
In the following paragraphs, Turing notes that the main challenge in creating a 'super-critical' program is not in hardware capabilities (e.g. memory, speed) but in the actual programming itself. I think most computer scientists would agree with him, at least mostly. After all, our current advances in machine learning were only possible by the increase in data and GPU power afforded in the past decade or so. Indeed, Turing estimated that only $10^9$ bits (126 MB) would be necessary to pass the Turing test, an estimate that falls short of the gigabytes (or even terabytes) needed to run/train the most advanced language models.

Getting back on track, how does Turing propose we construct the program? Well he begins by considering how a human mind comes to be. There are 3 components:
1. How the mind was at birth
2. The education the mind has received
3. Other experiences it has faced, that aren't education.

*That last one is a bit of a catch-all but it seems reasonable to divide experiences between education (formal knowledge) and everything else (informal knowledge).*

Turing proposes that we can reduce creating the program to 1) simulating a child-like mind, akin to the initial state described above, and then 2) subjecting it to something akin to education as well as 3) possibly other experiences. Operating on this 'blank slate' as Turing seems to imagine it, seems a much easier task than reverse-engineering an adult brain.

So now we have two problems, coming up with an initial 'child' machine, and educating it. For the former Turing suggests trial and error. He likens the process to evolution by natural selection:
- Structure of the child machine -> Hereditary Material (i.e. genes)
- Changes -> Mutations
- Natural Selection -> Judgement of the Experimenter.

Crucially, an active intelligent designer (i.e. the experimenter) would be much faster in producing positive changes, or mutations, in a model than natural selection. For the problem of education, Turing has two suggestions that would hopefully work together:
- A system of inference and logic to deduce claims about the world.
- A system of reward and punishment (think reinforcement learning).

## Thoughts on §7
For all the other sections, my thoughts were integrated into my summaries of Turing's words since I pretty much agreed with all his points, parroting in when I felt necessary. However, I don't think this last section is particularly convincing. While the idea is intuitive enough, the benefit of contemporary knowledge afforded by modern advances in computer science, biology, neuroscience, etc. tells me that this proposal doesn't have legs. Some problems include:
- The brittleness of logic-based reasoning in real-life situations.
  - Rule-based AI has had a long history of failure in computer science due to its proneness to failure.
- The overwhelming complexity of simulating brains. Even if much less than an entire simulation is necessary, computational cost still poses a much bigger problem than Turing realizes.
  - Even the huge deep neural networks calculated on supercomputers (in their current form) don't seem to be enough to, say, generate a full-length novel. Much less simulate a human's other cognitive abilities.

What seems far more tenable, to me at least, is a program that makes use of a machine learning model (either partially or entirely) that has a statistical understanding of language and thoughts. This has already been demonstrated in non-trivial cases.

But of course, hindsight is 20-20. In his defense, Turing's mention of using randomness and reinforcement learning seems right in line with contemporary approaches to AI. Further, I think if Turing was alive today and had access to this knowledge, this last section would be much different. However, maybe such hypotheticals are misguided considering so much of our knowledge is a result of his work, both directly via the theory of computing and indirectly via the advent of digital computers and their immeasurable effect on science and well... all other aspects of human life.

## Final Thoughts
So then, where does that leave us? I think there are a couple of takeaways our discussion has revealed:
- Turing was much ahead of his time in his consideration of artificial intelligence and its intimate relation with computation, as to be expected from the "Father of Computer Science."
- The mind is really something that can, and should, be considered physically, no matter how preposterous our evolved intuitions may seem to suggest this is.
- The Turing test is hardly a pipedream of contemporary computer scientists, and it has arguably already been passed in a limited capacity.

However, as with any good philosophical discussion, we are left with yet more questions:
- Is the Turing test a good test of 'consciousness'/something adjacent?
  - After all, I claim that it has already been solved in a limited capacity, yet the machines these models run on don't seem conscious in the slightest.
- Does the Turing test even need to be?
  - What even is consciousness?
  - Even if I gave you a computer that could respond perfectly as if it were a human (maybe it even panics that it is inside a computer since it thinks it is a real human), would you believe it to be conscious? What if it even had a physical form identical to a human (on the outside)?
  - Why do we believe those around us are conscious?

I have my own opinions on these questions, mostly taking the negative view that 'consciousness' isn't 'real' in some metaphysical sense and that, whatever you define consciousness to be, there exists a computer program that can simulate it. But these are claims too broad for this paper. What Turing asserted was more modest, at least by our standards. Yet despite this, his claims still remain controversial.

<!-- That a machine could think still is, and may always be, controversial. -->
<!-- Indeed, it would seem that there will always be a portion of the population that finds a thinking machine unthinkable. -->
<!-- Indeed, it would seem that, to many, that a machine could think is still unthinkable. -->
Indeed to many, that a machine could think is still, and may very well remain, unthinkable.
<!-- An impossibility... until it's not. -->

---

[^f1]: In fact strictly less than, as the mathematical formulation of a Turing machine calls for a countably infinite amount of memory. That said, this distinction needn't concern us as humans don't require a countably infinite amount of memory to function. Moreover, Turing machines can only use a finite amount of memory at one time anyway.

[^f2]: In regards to the gap between the uncountably infinite-dimensional states real-world quantum phenomena can hold as opposed to the finite-dimensional states of quantum computers, the Bekenstein bound shows us that the information contained in any given volume of space is proportional to its surface area and thus finite.

[^f3]: Of course, our modern view of physics doesn't allow for a Laplacian demon as, even if one got around the relativistic ambiguity of 'the current state of the universe', one would also have to contend with the fact that, on quantum scales, the universe and its laws are probabilistic.

[^f4]: If you haven't seen them already, algorithms like GPT-3, which represent the state of the art in language generation at the time of writing, are almost chillingly capable of producing believable text. I played around with a toy model of GPT-2, a much weaker model, as a project once and found that it was able to mimic not just English prose, but mimic a specific person's style of writing and even how they write equations in LaTeX!

[^f5]: A modern objector might point to quantum mechanics as producing indeterministic behavior that cannot be deterministically computed but, this is easily dealt with by simply considering the probability distribution of different thoughts a person might have rather than just one thought. On top of this, the human mind is almost certainly not sensitive enough to quantum fluctuations (at least locally) to make this an issue considering it operates on the level of neurons, which are many orders of magnitude larger than anything quantum.