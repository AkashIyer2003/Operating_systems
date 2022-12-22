#include<stdio.h>
#include<unistd.h>
int main(){
    int fd1[2],fd2[2],pid;
    pipe(fd1);
    pipe(fd2);
    pid = fork();
    if(pid>0){
        int x =5;
        write(fd1[1],&x,sizeof(x));
        close(fd1[1]);
    }
    else{
        int a;
        read(fd1[0],&a,sizeof(a));
        printf("%d",a);
        close(fd1[0]);
    }
}