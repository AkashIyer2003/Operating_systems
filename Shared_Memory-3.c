#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<unistd.h>

int main()
{
        key_t key2 = ftok("shmfile2",66);
        int shmid2 = shmget(key2,1024,0666|IPC_CREAT);
        char *str = (char*) shmat(shmid2,(void*)0,0);
        printf("Entered data: %s",str);
	return 0;
}


