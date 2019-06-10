#include <stdio.h>
#include <assert.h>
#include <pthread.h>

static volatile int suma=0;
static pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;

void *mythread1(void *arg){
	printf("start:debit\n");
	for(int i=0;i<1*1000*1000;i++){
		pthread_mutex_lock(&mutex);
		suma=suma+20;
		pthread_mutex_unlock(&mutex);
	}
	printf("stop:debit\n");
	return NULL;
}
void *mythread2( void *arg) {
	printf("start credit\n");
	for(int i=0;i<1*1000*1000;i++){
		pthread_mutex_lock(&mutex);
		suma=suma-10;
		pthread_mutex_unlock(&mutex);
	}
	printf("stop: credit\n");
	return NULL;
}

int main(int argc, char *argv[]){
	pthread_t t1,t2;
	int rc;
       printf("start:main\n");
       rc=pthread_create(&t1, NULL, mythread1, NULL); assert(rc==0);
       rc=pthread_create(&t2, NULL, mythread2, NULL); assert(rc==0);
       rc=pthread_join(t1,NULL); assert(rc==0);
       rc=pthread_join(t2, NULL); assert(rc==0);
       printf("stopr:main\n");
       printf("suma=%d\n", suma);
      return 0;
}
