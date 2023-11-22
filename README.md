# MACHINE LEARNING IN C - [Simple Neural Network]

- This is a simple demo of how neural networks work under the
hood implemented in C.

- The network is very light with an input data/vector feeding into a
single neuron over many iterations. 

- The size of the input data is a matrix/array of dimension (15, 2),
where the first column is the input and the second column is the label.

- The network was trained on a simple insurance dataset in the [data.h]
file, which shows the likely-hood of a person buying an insurance.

- Some model parameters are saved in the [main.c] file after training which give
a good loss and inference.

# HOW TO RUN FILE
NB: Your training data must be in the same format as the sample data in [data.h]
file so that the network can process correctly, as this is the required input shape/size
to the network. But hey, I invite you to mess around.😊😊

- In the [main.c] file, there are functions for training and inference.

- To train the model on the provided data or your custom data, you have to call the
train function in the [main] function of the [main.c] file and run the [build.sh] script for
linux platforms or [build.bat] for windows to kick off training

- The loss will be displayed after the training and you can copy the values and infer
from the model on a test set.

- Special thanks to [youtube.com/tsoding daily] for a great and insightful tutorial.