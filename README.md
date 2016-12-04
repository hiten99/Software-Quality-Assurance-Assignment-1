# cs490-fall2015-sqa-assignment1
I have written code in c++.
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
