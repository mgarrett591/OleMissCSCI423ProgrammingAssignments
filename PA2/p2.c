#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char * argv[]){
    if(argc!=2){
        fprintf(stderr,"Usage: %s <starting value>\n",argv[0]);
        return -1;
    }
    int value = atoi(argv[1]);
    if(value<1){
        fprintf(stderr,"<starting value> should be a positive integer\n");
        return -1;
    }
    pid_t pid;
	pid=fork();
    if (pid<0){ 
		fprintf(stderr, "A Fork related error has ocured\n");
		return -1;
	}
	else if (pid==0)
	{ 
        printf("%d", value);
        while(value!=1){
            if(value%2==0){
                value=value/2;
            }
            else{
                value=(3*value)+1;
            }
            printf(", %d", value);
        }
        printf("\n");

	}
	else
	{
		wait(NULL);
	}
	
	return 0;
}