#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
# define N 5
int l = 1;
int r = 1;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
void Wait(int side){
    while(side == 0);
    pthread_mutex_lock(&mutex1);
    side = 0;
    pthread_mutex_unlock(&mutex1);
}
void Signal(int side){
    pthread_mutex_lock(&mutex1);
    side = 1;
    pthread_mutex_unlock(&mutex1);
}
void* philosopher(void* i){
    printf("%i\n",i);
    printf("Philosopher %i is waiting for left chopstick\n",i);
    Wait(l);
    printf("Philosopher %i got left chopstick\n",i);
    printf("Philosopher %i is waiting for right chopstick\n",i);
    Wait(r);
    printf("Philosopher %i got right chopstick\n",i);
    printf("Philosopher %i is eating\n",i);
    sleep(2);
    Signal(l);
    Signal(r);
}
int main(){
    pthread_t t[5];
    for(int i = 0; i < 5; i++){
        pthread_create(&t[i],NULL,philosopher,(void*) i);
    }
    for(int i = 0; i < 5; i++){
        pthread_join(t[i],NULL);
    }
}