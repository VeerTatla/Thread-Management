README.md
CS570 Assignment 1
Veerparatap Tatla cssc1153
Josh Robey cssc1126
CS570 Operating Systems, Summer 2017
Assignment #1: Thread management


File Manifest:
1.) bots.c -----> Main program that does work for managing threads.
2.) bots.h------> Contains headers for bots.c
3.) Makefile----> Automates process for compiling program.
4.) Quote.txt---> Sample output file of running program. 
5.) README.md---> Has all information about program.

Compile and run instructions:
At the command line to compile type-
$ make
Then to run executable simply type-
$ bots

Significant design choiices:

We decided to make the main() function as short as possible.
We simply wanted that portion to execute our other functions
rather than have everything jumbled up in there. 

Lessons learned:

We learned a lot about multithreading and how to start processes. 
We also learned a lot about various IPC algorithms while choosing
the right one for this project. Another important aspect we learned was
in thread scheduling and how to properly use semaphores.

