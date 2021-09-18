#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef uint8_t u8;

void *thread_00_func(void *arg);

int main(int argc, char *argv[])
{
	pthread_t th00;

	//printf("Na mehet.\n");
	//sleep(2);

	if(pthread_create(&th00,NULL,thread_00_func,NULL)){
		fprintf(stderr, "Error\n");
		exit(1);
	}

	//sleep(15);
	getc(stdin);
	printf("Main thread stoped\n");

	return 0;
}

void *thread_00_func(void *arg){
	printf("[+] TH00 started.\n");
	for(u8 i = 0; i < 10; i++){
		printf("th00: %d.\n", i);
		sleep(1);
	}

	printf("[+] TH00 finished\n");
}