#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
#include<stdlib.h>
#include <strings.h>
#include <limits.h>
#include<pthread.h>
#include<sys/wait.h>
#define _POSIX_SOURCE
double timeA ; 
double timeB ; 
double timeC ; 
pid_t x;
pid_t y;
pid_t z;
int flagA = 0; 
int flagB = 0;
int flagC = 0;
int main(){
		int in; 
		int status;
		double startTime = clock(); 
		x = fork();
		if(x == 0){
			char *args[] = {NULL , NULL , NULL , NULL}; 
			execv("./bashA", args);
		}
		else{
			y = fork();
			if(y == 0){
				char *args[] = {NULL , NULL , NULL , NULL}; 
				execv("./bashB", args);
			}
			else{
				z = fork();
				if(z==0){
					char *args[] = {NULL , NULL , NULL , NULL}; 
					execv("./bashC", args);
				}
				else{
					while(((x = waitpid(x, &status, WNOHANG))!=-1 || (y = waitpid(y, &status, WNOHANG))!=-1) || ((z = waitpid(z, &status, WNOHANG))!=-1)){
						printf("waiting for end of a child process, can't continue parent\n");			
						wait(NULL); 
					}					
				}
			}
		}
	printf("parent reached :)\n" );
	return 0;
}










