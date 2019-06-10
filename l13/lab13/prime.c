#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>

int isPrime(int x)
{
    for(int d=2;d<=x/2;d++){
	    if(x%d==0)
           return 0;
    }
    return -1;
}
long long suma=0;
long long nums[100];
int len=100;
int numThreads=1;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZED;
int  sum(void* arg){
	int thnum=(int) arg;
	for(int i=0;i<len;i++){
		if(i%thnum==indexThread)
		if(isPrime(nums[i])){
			pthread_mutex_lock(&mutex);
			suma=suma+nums[i];
			printf("indexThread=%d num=%d\n", indexThread, nums[i]);
			pthread_mutex_unlock(&mutex);
	}
}
	return suma;
	}
#define  NUMTHREADS 2;

int main(int argc, char* argv[])
{
   int nums[100];
   for(int i=0;i<100;i++){
	   nums[i]=7e8+i;
   }
   int numThreads=atoi(argv[1]);
   pthread_t t[MAX_THREADS];
   for(int i=0;i<numThread;i++){
	   pthread_created(&t[i], NULL, sumPrimes, (void*)i);
   }
   for(int i=0; i<numThread;i++)
   {
	   pthread_join(t[i], NULL);
   }
   printf("%d\n", suma);

return 0;
}
