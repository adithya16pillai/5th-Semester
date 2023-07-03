// C program to demonstrate working of Semaphores
//to run cc -pthread IPC-semaphore1.c
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t mutex;
void* thread(void* arg)
{
//wait
sem_wait(&mutex);
printf("\n%ld Entered the critical section..\n",pthread_self());
//critical section
  
sleep(4);
  
//signal
printf("\n%ldJust Exiting critical ection...\n",pthread_self());
sem_post(&mutex);
}
int main()
{
sem_init(&mutex, 0, 1); 
//Argument-1 sem : Specifies the semaphore to be initialized.
//Argument-2 pshared : This argument specifies whether or not the newly initialized semaphore is shared between processes or between threads. A non-zero value means the semaphore is shared between processes and a value of zero means it is shared between threads.
//Argument-3 value : Specifies the value to assign to the newly initialized semaphore.
  
pthread_t t1,t2;
pthread_create(&t1,NULL,thread,NULL);
//sleep(2);
pthread_create(&t2,NULL,thread,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
sem_destroy(&mutex);
return 0;
}