#include <stdio.h>
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
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZED;
int  sum(void* arg){
	int thnum=(int) arg;
	for(int i=0;i<len;i++){
		if(i%thnum==0)
		if(isPrime(nums[i])){
			pthread_mutex_lock(&mutex);
			suma=suma+nums[i];
			pthread_mutex_unlock(&mutex);
	}
}
	return suma;
}

int main(int argc, char* argv[])
{
   int nums[100];
   for(int i=0;i<100;i++){
	   nums[i]=7e8+i;
   }
   pthread_t t0,t1;
  pthread_create(&t0,NULL,sum,(void*) 0)
	  pthread_join(t0, NULL);
   printf("%d\n", suma);

return 0;
}
