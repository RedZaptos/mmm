#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
#include<stdlib.h>
#include <strings.h>
#include <limits.h>
#include<pthread.h>


int main(int argc , char* argv[]){
	double start = clock();
	// struct sched_param param;
 //   	int pid_num = 0;
 //   	param.sched_priority = 0;
 //   	sched_setscheduler(pid_num, SCHED_OTHER, &param);
   	pid_t x = fork();
   	if(x==0){
   		int n = nice(0);
   		printf("%d\n",n );
   		printf("in child %d\n" , x);
		for(long int i = 0 ; i<4294967296 ; i++){
			if(i==4294967295){printf("omg\n");}
			continue;
		}
		while(1){continue;}
	}
	else{
		wait(NULL); 
		printf("Completed process B\n");
		printf("time B: %f\n",(double)(clock()-start));

	}
	return 0;
}