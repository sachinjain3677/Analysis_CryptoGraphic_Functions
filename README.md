# Analysis of Boolean Functions
This project includes analysis and implmentation of some algorithms related to conversion of **boolean functions** from one representation to another.

## Prerequisites

 - c++ compiler
 - git command line interface

## Cloning the repository
Open a terminal window and run:
```
> git clone https://github.com/sachinjain3677/B.Tech-Project
> cd B.Tech-Project
```

## Fast_Walsh_Transform
### ./lib 
Contains codes for implementation of Sparse Matrix and Fast Walsh Transform algorithm in files named **sparse_matrix.h** and **walsh_transform.h** respectively.
### ./walsh_transform_main.cc
Contains the driver code for this algorithm.
### How to run
Assuming doing **Cloning the repository** step, run the following commands in the same terminal window:
```
> cd 'Fast_Walsh_Transform'
> g++ walsh_transform_main.cc
> ./a.out
```
> **Note:** If you are getting an error in the **g++** step, make sure your **c++** compiler is installed properly.

### Input/Output
Input to the algorithm is a vector of 2^n values corresponding to the truth table of our input boolean function. This can be specified by editing the **walsh_transform_main.cc** file.

The algorithm outputs the values of **Walsh Coefficients** corresponsing to the specified input in the terminal window.
