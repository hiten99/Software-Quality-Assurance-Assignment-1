# cs590-fall2015-sqa-assignment1
CS 59000 - Software Quality Assurance Functional Testing Input Generators
The purpose of this assignment is to create an input generator that can be used to test your previously implemented programs. You will be implementing the following input generators: 
1. Boundary Value Analysis 
2. Worst-case Robustness 
3. Weak Normal Equivalence Class
4. Weak Robust Equivalence Class 

The generator must prompt the user for the following information in the order below: 
1. The user must select one of the 4 options above
2. The user selects the number of variables
3. The user inputs the range of the variables (e.g., (1,3), [5, 90])

The generator then outputs the test cases to the screen such that each row is a test case, and each column in each row is the value of its corresponding variable. Do not add any header information to the generated output.

Here is an example test configuration that is prompted in file format:
1         # Generator 
3         # Number of variables
(1, 60)   # Variable 1
[52, 67]  # Variable 2 
(-1, 34]  # Variable 3
The # is not included in the input and is meant to convey a comment.

Steps to run:
Important Note:
Download and install MPC in your machine.
Check whether MPC is there in your directory and PATH/environment variables for MPC are set in your machine(pegasus).
Also give permissions to all the files :
chmod +x *.cpp
chmod +x *.h
chmod +x assignment1.mpc

To run code on pegasus follow commands below:
>export PATH=/usr/local/gcc/bin/:$PATH
>mwc.pl -type make -features cpp11=1
>make
>./assignment1
