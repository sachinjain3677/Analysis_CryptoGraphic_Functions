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
### lib 
Contains codes for implementation of Sparse Matrix and Fast Walsh Transform algorithm in files named **sparse_matrix.h** and **walsh_transform.h** respectively.
### walsh_transform_main.cc
Contains the driver code for this algorithm.
### How to run
After **Cloning the repository** step, run the following commands in the same terminal window:
```
> cd Fast_Walsh_Transform
> g++ walsh_transform_main.cc
> ./a.out
```
> **Note:** If you are getting an error in the **g++** step, make sure your **c++** compiler is installed properly.

### Input/Output
Input to the algorithm is a vector of 2^n values corresponding to the truth table of our input boolean function. This can be specified by editing the **walsh_transform_main.cc** file.

The algorithm outputs the values of **Walsh Coefficients** corresponsing to the specified input in the terminal window.

### Example
Consider the following truth table as example. 

Input to the algorithm would be a vector containing the values specified in the **Y** column (in the same order). 

Corresponding output would be the values in the 4th column (**Walsh Transform**).
|X<sub>1</sub> | X<sub>2</sub> |Y    |Walsh Transform|
|:------------:|:-------------:|:---:|:-------------:|
|0             |0              |1    |3              |
|0             |1              |0    |1              |
|1             |0              |1    |-1             |
|1             |1              |1    |1              |

## ANF_to_Walsh
### How to run
After **Cloning the repository** step, run the following commands in the same terminal window:
```
> cd ANF_to_Walsh
> g++ anf_to_walsh_conversion.cpp
> ./a.out
```
> **Note:** If you are getting an error in the **g++** step, make sure your **c++** compiler is installed properly.

### Input/Output
#### p
Number of terms in the ANF representation if the input function.

#### m
Number of input variables in the function.

#### supAg
A matrix of size **p X m** representing the support of the input boolean function.

#### v
A vector of size **m**, representing the point, in its boolean form, at which Walsh coefficient is to be calculated.

### Example
Consider the following boolean function in its ANF form, **g = x<sub>1</sub> ⊕ x<sub>1</sub>.x<sub>2</sub>**.

Input variables for this example would be, 

**p = 2, m = 2**

**supAg = [[0, 1],** 
         **[1, 1]]**

Value of **v** represents the point at which we want to find the Walsh transform, lets keep it **v = [0, 0]** for this example. 


## Influence_from_ANF
### How to run
After **Cloning the repository** step, run the following commands in the same terminal window:
```
> cd Influence_from_ANF
> g++ influence_from_anf.cpp
> ./a.out
```
> **Note:** If you are getting an error in the **g++** step, make sure your **c++** compiler is installed properly.

### Input/Output
#### p
Number of terms in the ANF representation if the input function.

#### m
Number of input variables in the function.

#### supAg
A matrix of size **p X m** representing the support of the input boolean function.

#### v
A vector of size **m**, representing the point, in its boolean form, at which Walsh coefficient is to be calculated.

#### u
Specifies the number of the variable for which influence is to be calculated. For instance, if input variables are **(x<sub>1</sub>, x<sub>1</sub>, ..., x<sub>n</sub>)**, then influence of **x<sub>u</sub>** will be calculated.

### Example
Consider the following boolean function in its ANF form, **g = x<sub>1</sub> ⊕ x<sub>1</sub>.x<sub>2</sub>**.

Input variables for this example would be, 

**p = 2, m = 2**

**supAg = [[0, 1],** 
         **[1, 1]]**

Lets consider **u = 1** for this example, which represents **x<sub>1</sub>** as the target variable.

The output obtained for this case is **"influence of variable u on function f = 0.5"**.
