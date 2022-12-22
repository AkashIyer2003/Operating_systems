#include <stdio.h>
#include <unistd.h>
int main(){
	int fd1[2],fd2[2],pid;
	pipe(fd1);
	pipe(fd2);
	pid = fork();
	if (pid>0){
		printf("Parent sending 5 to child\n");
		int a, x = 5;
		write(fd1[1],&x,sizeof(x));
		printf("Parent recieving square of 5 from child\n");
		read(fd2[0],&a,sizeof(a));
		printf("parent prints: %d",a);
		close(fd2[0]);
		close(fd1[1]);
	}
	else{
		int y, b;
		printf("child recieves from parent and squares it\n");
		read(fd1[0],&y,sizeof(y));
		printf("child send back the squared no. back to parent\n");
		b = y * y ;
		write(fd2[1],&b,sizeof(b));
		close(fd1[0]);
		close(fd2[1]);
	}
}
