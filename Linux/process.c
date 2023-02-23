#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//僵尸进程
int main()
{
	printf("I am running...\n");
	pid_t id = fork();
	if(id == 0){ //child
		int count = 5;
		while(count){
			printf("I am child...PID:%d, PPID:%d, count:%d\n", getpid(), getppid(), count);
			sleep(1);
			count--;
		}
		printf("child quit...\n");
		exit(1);
	}
	else if(id > 0){ //father
		while(1){
			printf("I am father...PID:%d, PPID:%d\n", getpid(), getppid());
			sleep(1);
		}
	}
	else{ //fork error
	}
	return 0;
} 


//孤儿进程
int main()
{
	printf("I am running...\n");
	pid_t id = fork();
	if(id == 0){ //child
		while(1){
			printf("I am child...PID:%d, PPID:%d\n", getpid(), getppid());
			sleep(1);
		}
	}
	else if(id > 0){ //father
		int count = 5;
		while(count){
			printf("I am father...PID:%d, PPID:%d, count:%d\n", getpid(), getppid(), count);
			sleep(1);
			count--;
		}
		printf("father quit...\n");
		exit(0);
	}
	else{ //fork error
	}
	return 0;
} 
