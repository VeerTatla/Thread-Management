 /*
Veer Tatla cssc1153
Josh Robey cssc1126
CS570 Assignment 1
bots.c

This program creates 7 threads that run concurrently
displaying certain message for even and odd numberes
threads. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "bots.h"


FILE *QUOTE;
sem_t FLAG;



void thread_creator()
{
    //Initialize FLAG semaphore
    sem_init(&FLAG, 0, 1);

    //create thread id's    
    int num_of_threads = 7;
    int id[num_of_threads];
    
    int i;    
    for(i = 0; i < 7; i++)
    {
        id[i] = i;
    }

    //Value of each thread's id
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
    pthread_t thread5;
    pthread_t thread6;
    pthread_t thread7;

    //Create 7 threads
    pthread_create(&thread1, NULL, (void *) &pid_filewriter, (void *) &id[0]);
    pthread_create(&thread2, NULL, (void *) &pid_filewriter, (void *) &id[1]);
    pthread_create(&thread3, NULL, (void *) &pid_filewriter, (void *) &id[2]);
    pthread_create(&thread4, NULL, (void *) &pid_filewriter, (void *) &id[3]);
    pthread_create(&thread5, NULL, (void *) &pid_filewriter, (void *) &id[4]);
    pthread_create(&thread6, NULL, (void *) &pid_filewriter, (void *) &id[5]);
    pthread_create(&thread7, NULL, (void *) &pid_filewriter, (void *) &id[6]);
    
    //Uses pthread_join() to force each thread to wait on the termination of the previous thread
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
    pthread_join(thread6, NULL);
    pthread_join(thread7, NULL);
    
    //Destroy FLAG semaphore
    sem_destroy(&FLAG);
}


void pid_filewriter(void *thread_pointer)
{    
    int thread_number = *((int *) thread_pointer);

    //Force program to 2 seconds initially to begin
    sleep(2);
    fflush(stdout);
    int timer_counter = 2;

    int i;
    for(i = 1; i <= 7; i++)
    {
        sem_wait(&FLAG);
        
        //Has the program suspend 1 second each loop to allow semaphore switching, otherwise it happens too fast
        sleep(1);        
        timer_counter++;
	
	

        //Output to console notifying which thread is running and will be printed to QUOTE.txt
        fprintf(stderr, "Thread %d is running < %d >.\r\n", thread_number, pthread_self());

        //Opens QUOTE.txt for appending
        QUOTE = fopen("QUOTE.txt", "a");


        //Determines the proper quote to print to QUOTE.txt
        if(QUOTE != NULL)
        {
            if (thread_number % 2 == 0)
            {
	    	sleep(2);
                fprintf(QUOTE, "Thread id %d < %d >. Controlling complexity is the essence of computer programming.\r\n", thread_number, pthread_self());                
                sem_post(&FLAG);
            }
            else
            {	
	    	sleep(3);
                fprintf(QUOTE, "Thread id %d < %d >. Computer science is no more about computers than astronomy is about telescopes.\r\n", thread_number, pthread_self());                
                sem_post(&FLAG);
            }
            fclose(QUOTE);            
        }
             
    }
    pthread_exit(0);
}

int main (int argc, char const *argv[])
{
	QUOTE = fopen("QUOTE.txt", "w+");
	fprintf(QUOTE, "Parent process id: %d\r\n", getppid());
	fclose(QUOTE);
	
    	thread_creator();
    	printf("Completed 49 file writes to QUOTE.txt. Closing... \r\n");
    	return 0;
}
