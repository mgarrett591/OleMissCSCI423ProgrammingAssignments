#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 500000000

double inside;
int total;
void *runner(void *param);

double random_double();

pthread_mutex_t mutex;

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr,"usage: a.out <number of threads>\n");
		return -1;
	}

	int T = atoi(argv[1]);

	if (T < 0) {
		fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
		return -1;
	}

	pthread_t tid[T];
	pthread_attr_t attr;

	int i;
	inside = 0;
	total = 0;

	pthread_mutex_init(&mutex,NULL);

	pthread_attr_init(&attr);
	int overflow = N%T;
	for (i=0; i<overflow; i++)
		pthread_create(&tid[i],&attr,runner,(void *)(N/T)+1);

	for (i=0; i<T-overflow; i++)
		pthread_create(&tid[i],&attr,runner,(void *)(N/T));

	for (i=0; i<T; i++)
		pthread_join(tid[i],NULL);

	printf("pi = %lf\n",4*inside/N);
	
}

void *runner(void *param)
{
	int n=(int)param;
	double x;
    double y;
	for(int i=0; i<n; i++){
		x = random_double();
        y = random_double();
		if(sqrt(x*x + y*y) < 1.0){
			pthread_mutex_lock(&mutex);
				inside++;
			pthread_mutex_unlock(&mutex);
        }
	}
	pthread_exit(0);
}

double random_double() 
{    
    return random() / ((double)RAND_MAX + 1); 
}