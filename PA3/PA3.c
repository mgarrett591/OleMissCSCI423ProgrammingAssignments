#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *meanRunner(void *param);
void *minRunner(void *param);
void *maxRunner(void *param);

int *data;
int N;

int main(int argc, char* argv[]){

    N = argc-1;
    int i = 0;

    if(argc<2){
        fprintf(stderr, "Usage: %s <at least one integer as input>\n", argv[0]);
        return 1;
    }

    //parse the args and toss 'em on da heap!
    data = (int *) malloc(sizeof(int)*(argc-1));
    for(i=0; i<N; i++){
        data[i]=atoi(argv[i+1]);
    }
    pthread_t meanFinder;
    pthread_t minFinder;
    pthread_t maxFinder;

    pthread_attr_t attr;
    pthread_attr_init(&attr);


    pthread_create(&meanFinder,&attr, meanRunner, (void *) data);
    pthread_create(&minFinder,&attr, minRunner, (void *) data);
    pthread_create(&maxFinder,&attr, maxRunner, (void *) data);

    pthread_join(meanFinder,NULL);
    pthread_join(minFinder,NULL);
    pthread_join(maxFinder,NULL);

    free(data);
    return 0;
}

void *meanRunner(void *param)
{
	int *data = (int*)param;
    int i;
    int sum = 0;
    for(i = 0; i<N; i++){
        sum+=data[i];
    }

	printf("The average value is %d\n", (sum/N));
	
	pthread_exit(0);
}

void *minRunner(void *param)
{
	int *data = (int*)param;
    int i;
    int min = data[0];
    for(i = 1; i<N; i++){
        if(data[i]<min){
            min=data[i];
        }
    }

	printf("The minimum value is %d\n", min);
	
	pthread_exit(0);
}

void *maxRunner(void *param)
{
	int *data = (int*)param;
    int i;
    int max = data[0];
    for(i = 1; i<N; i++){
        if(data[i]>max){
            max=data[i];
        }
    }

	printf("The maximum value is %d\n", max);
	
	pthread_exit(0);
}