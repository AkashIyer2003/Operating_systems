#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int MAXSIZE = 5;
int a[100];
int front=-1, end=-1, count=0;
pthread_mutex_t lock;

float genWaitTime(){
	time_t t;
    	time(&t);
    	int x = t;
    	srand(x);
	float w = (rand()%100)*0.0123;	
	return w;	
}

void producer(int message){

	for (int i=0;i<10;i++){
		printf("sleeping p%d\n",message);
		sleep(genWaitTime());
		while(count>=MAXSIZE) printf("");
	
		//locking and changing count
		pthread_mutex_lock(&lock);
		count++;
		pthread_mutex_unlock(&lock);
		
		printf("as %d writing : %d\n",message,message);
		a[++end] = message;	
	}
}

void consumer(int number){

	for (int i=0;i<10;i++){
		printf("sleeping c%d\n",number);
		sleep(genWaitTime());
	
	
		while(count<=0) printf("");
	
		//locking and changing count
		pthread_mutex_lock(&lock);
		count--;
		pthread_mutex_unlock(&lock);
	
		int received = a[++front];	
		printf("as consumer %d received %d\n",number,received);
	}
}




void main(){
	pthread_t p1,p2,p3,p4,p5,c1,c2,c3,c4,c5;
	pthread_create(&p1,NULL,(void *)producer,(void*)1);
	pthread_create(&p2,NULL,(void *)producer,(void*)2);	
	pthread_create(&c1,NULL,(void *)consumer,(void*)1);
	pthread_create(&c2,NULL,(void *)consumer,(void*)2);
	

	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	pthread_join(c1,NULL);
	pthread_join(c2,NULL);

}
