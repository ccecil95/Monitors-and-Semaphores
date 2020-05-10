//MONITROS AND SEMAPHORES
//Christy Cecil 
//CST-221


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void myfunc1 ( void *ptr );
void myfunc2 ( void *ptr );

char buf[24];
sem_t mutex;


int main(int argc, char *argv [])
{
	pthread_t thread1;
	pthread_t thread2;
	
	char *msg1 = "Thread 1";
	char *msg2 = "Thread 2";
	
	
	sem_init(&mutex, 0, 1);
	//i will have to initialize the semaphore
	
	pthread_create (&thread1, NULL, (void *) &myfunc1, (void *) msg1);
	pthread_create (&thread2, NULL, (void *) &myfunc2, (void *) msg2);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	sem_destroy(&mutex);
	//once initialized I will need to destroy it.
	
	return 0;
}

void myfunc1 ( void *ptr )
{
	char *msg = (char *)ptr;
	
	printf("%s\n", msg);
	
	sem_wait(&mutex);
	printf(buf, "%s", "Supercalafragalisticespialidocious!\n");
	sem_post(&mutex);
	
	pthread_exit(0);
}

//not sure why printf is not working doe :/

void myfunc2 ( void *ptr )
{
	char *msg = (char *)ptr;
	
	printf("%s\n", msg);
	
	sem_wait(&mutex);
	printf("%s\n", buf);
	sem_post(&mutex);
	
	//I will use the sem_wait for my desired result.
	pthread_exit(0);
}

//I found a helpful youtube video, the name of the User is Shellwave. 
