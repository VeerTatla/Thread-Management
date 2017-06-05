############################
#Veer Tatla cssc1153       #
#Josh Robey cssc1126       #
#Makefile for Assignment 1.#
############################


all:
	cc -pthread -o bots bots.c
	
run: all

	./bots
