# Artificial Neural Networks in Regards to Cognition
## What are Neural Networks?
Artificial neural networks (ANNs) are models of computation that take inspiration from the neuronal structure of the brain. They are composed of several nodes (analogous to neurons) that are set up in layers.

Each layer connects to the next in a sequential manner (at least in the more simple cases) to form an interconnected function, with the first layer representing some *input* and the last layer representing some *output*. In a very general sense, each layer can be thought of as abstracting out some information from the previous layer.

![](https://icdn5.digitaltrends.com/image/artificial_neural_network_1-791x388.jpg)

Mathematically speaking, the input is some n-dimensional *feature* vector which contains, what is hopefully, pertinent information to the desired output. Each line from a node to a node in the next layer is a single number between 0 and 1. As a whole, the set of weights from one layer to the next is represented by a matrix. But before a layer (vector) can be transformed by the connections (multiplied by a matrix) it must undergo a **nonlinear transformation** via some **activation function**.

![](/assets/comp_sci/cogscihw2.png)

Thus a given model of an ANN is just a mathematical equation expressed in linear algebraic terms. In fact, the image above is represented by the following equation:

$$\hat{y}=\operatorname{softmax}(W_1\mathbf{x}+b_1)$$

*Where $W_1$ are the weights of the first (and only) layer, $b_1$ is a bias for that layer, $\mathbf x$ is the input and $\hat y$ is the output. Softmax is a particular activation function but any could be used.*

For example, the first layer may take in the raw image data of a camera. The next layer may take this data and (via a set of trained weights) infer some structure from this raw data such as the position of straight lines. The next layer may infer the existence of closed shapes, and the next layer still may infer basic objects form these shapes. This continues on and on until we reach the final layer: the output. In this case it is a percentage of confidence that the image is of a cat, dog, car, etc.

### Training
ANN's mainly 'learn' (that is update their internal parameters to make more accurate predictions) by comparing the outputted answer to a given desired answer, and adjusting the parameters very slightly in the direction of outputting the directed answer.

*(in practice this is done by some optimization algorithm that usually makes use of partial derivatives but this is not too important).*

## Analogues to the Human Mind
From its mode of information processing to its structure, it's obvious that ANN's mirror many important aspects of the human mind.  As such, despite not truly representing a human mind, they are invaluable in researching and understanding the more computational and functional aspects of cognition as a whole. Here are some more pointed examples of this connection:

#### Learning from Example
Notice that ANN's learn in the same way one might teach an animal or small child something: reinforcement. Show it examples of good behavior and tell it to mimic it and show it examples of bad behavior and tell it to avoid it. This method is surprisingly effective in training ANNs to provide useful output.

One of the major caveats in this method however, is that any decent ANN requires mounds of data already labeled 'good' and 'bad' (or 'dog' and 'cat' or whatever is being taught). This isn't as much of a problem to humans who can learn in more complicated and independent ways. An ability allowed by our environment as well as our own biology which biases our brains to be more apt at certain tasks.

#### The Brain is an ANN
The brain can be considered an ANN itself with sensory neurons serving as input (the world you perceive), the interconnected multilayered biological neural network (your brain) serving as the hidden layers, and motor neurons (your physical actions) serving as outputs.

Of course this is not a perfect analogy but is a more than decent starting point for many researchers.

#### Abstraction
ANNs take what is usually raw and objective data and slowly but surely transform it into more abstract and focused information. This is exactly what the human mind does. It takes in a whole host of sensory stimuli and outputs a rich experience of a comprehensive world with objects and interactions between those objects. Indeed our own eyes seem to be simply biological versions of the (admittedly oversimplified) ANN shown above.

#### Emergent Complexity
It is important to note, both for nodes in an ANN and neurons in a human mind, that each atomic element (not literally atoms but the basic components of the mind) is identical to any other. Yet when put together, these atoms can form some of the most complex objects imaginable.

What *is* different in ANN's and brains is the weights between the nodes/neurons. Different weights mean different networks, and similar weights mean similar networks.
