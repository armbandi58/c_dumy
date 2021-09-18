#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef uint8_t u8;

void *th00_func(void *arg);
void *th01_func(void *arg);
void *th02_func(void *arg);

int main(int argc, char *argv[])
{
	pthread_t myThread00, myThread01, myThread02;

	if(pthread_create(&myThread00,NULL,th00_func,NULL)){
		fprintf(stderr, "Error.\n");
	}

	if(pthread_create(&myThread01,NULL,th01_func,NULL)){
		fprintf(stderr, "Error.\n");
	}

	if(pthread_create(&myThread02,NULL,th02_func,NULL)){
		fprintf(stderr, "Error.\n");
	}

	if(pthread_join(myThread02,NULL)){
		fprintf(stderr, "Error.\n");
	}

	if(pthread_join(myThread00,NULL)){
		fprintf(stderr, "Error.\n");
	}

	if(pthread_join(myThread01,NULL)){
		fprintf(stderr, "Error.\n");
	}

	printf("[+] Main thread stopped\n");
	return 0;
}

void *th00_func(void *arg){
	printf("[+] TH00 started.\n");
	for(u8 i = 0; i < 5; i++){
		printf("th00: %d\n", i);
		sleep(2);
	}
	printf("TH00 finished.\n");
}

void *th01_func(void *arg){
	printf("[+] TH01 started.\n");

	for(u8 i = 0; i < 5; i++){
		printf("th01: %d\n", i);
		sleep(1);
	}
	printf("TH01 finished.\n");
}

void *th02_func(void *arg){
	char buff[80];

	printf("Lokjed:\n");
	scanf("%s",buff);
	printf("%s\n",buff);
	fflush(stdout);
}





















