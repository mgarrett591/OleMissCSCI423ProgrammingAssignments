#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 500000000

double inside;
void *runner(void *param);

double random_double();

int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;


	inside = 0;

	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,(void *)1);

	pthread_join(tid,NULL);

	printf("pi = %lf\n", 4*inside/N);
}

void *runner(void *param)
{
	double x;
    double y;
    for(int i=0; i<N; i++){
        x = random_double();
        y = random_double();
        if(sqrt(x*x + y*y) < 1.0){
            inside++;
        }
    }
	pthread_exit(0);
}

double random_double() 
{    
    return random() / ((double)RAND_MAX + 1); 
}