#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<strings.h>
#include<limits.h>
#include<pthread.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<sched.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<pthread.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<sched.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>


int main(int argc , char* argv[]){
	double start = clock();
   	pid_t x = fork();
   	if(x==0){
   		int n = nice(0);
   		printf("%d\n",n );
   		printf("in child %d\n" , x);
		for(long int i = 0 ; i<4294967296 ; i++){
			continue;
		}
		while(1){continue;}
	}
	else{
		wait(NULL); 
		printf("Completed process A\n");
		printf("time A: %f\n",(double)(clock()-start));

	}
	return 0;
}