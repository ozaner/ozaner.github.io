---
classes: wide
header:
  overlay_image: /assets/images/splash-images/sinnoh-rt-210.png
  caption: "[__Route 210__](https://bulbapedia.bulbagarden.net/wiki/Sinnoh_Route_210) in Sinnoh"
permalink: /portfolio/index.html
redirect_from:
  - /projects/

feature_row:
  - image_path: assets/images/projects/qRNG.png
    alt: "qRNG"
    title: "qRNG: A Quantum Random Number Generator"
    excerpt: "A python API for generating random numbers using IBM's publically available quantum computers."
    url: "https://github.com/ozanerhansha/qRNG"
    btn_label: "Code Here"
    btn_class: "btn--inverse"

  - image_path: /assets/images/projects/breast-cancer/project-icon.png
    alt: "BreastCancer"
    title: "Breast Cancer Classification Network"
    excerpt: "A neural network trained to distinguish between benign and malignant breast cancer cells with a ~90% accuracy."
    url: "/breast-cancer-classification/"
    btn_label: "Read More"
    btn_class: "btn--inverse"

  - image_path: /assets/images/projects/filetopng/songtopng.png
    alt: "FileToPNG"
    title: "FileToPNG: Encoding files as PNGs"
    excerpt: "A tool for converting files into a sendable image format. As it turns out, interesting aspects of the file can be gleaned by how its encoded form looks."
    url: "/filetopng/"
    btn_label: "Read More"
    btn_class: "btn--inverse"
feature_row2:
  - image_path: /assets/images/projects/pongAI/pongai.gif
    alt: "pongai"
    title: "Reinforcement Learning Pong AI"
    excerpt: "An neural network trained to play pong against a competent bot. While not perfect, with enough training it's win rate approaches ~90%."
    url: "/reinforcement-learning-pong"
    btn_label: "Read More"
    btn_class: "btn--inverse"

  - image_path: /assets/images/projects/eeg.png
    alt: "eeg"
    title: "Neurosky EEG Test App"
    excerpt: "An Android app that can communicate with a Neurosky EEG headset via bluetooth, allowing the user to output a CSV of their brainwaves at different key frequencies over time."
    url: "https://github.com/ozanerhansha/NeuroSkyTest"
    btn_label: "Code Here"
    btn_class: "btn--inverse"

  - image_path: /assets/images/projects/digit-classifier/test_screenshots.png
    alt: "digits"
    title: "Handwritten Digit Classifier"
    excerpt: "An android app demonstration of a model for classifying handwritten digits (0-9) using a convolutional neural network made in TensorFlow. It was trained on the [MNIST Dataset](http://yann.lecun.com/exdb/mnist/) on about 1,000,000 examples. You can find the model [here](https://github.com/ozanerhansha/NeuralNetworks/blob/master/src/MNIST/conv/mnist_convolutional.py)."
    url: "https://github.com/ozanerhansha/DigitClassifier"
    btn_label: "Code Here"
    btn_class: "btn--inverse"
---

<div style="margin-bottom:1cm" align="center"><font size="55">Selected Projects</font></div>

{% include feature_row type="left"%}
{% include feature_row id="feature_row2"%}
