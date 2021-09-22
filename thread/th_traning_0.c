#include "main.h"

void *func_th00(void *args);
void *func_th01(void *args);
void *func_th02(void *args);
void *func_th03(void *args);

sem_t *s0;
sem_t *s1;
static const char *semname_0 = "sema0";
static const char *semname_1 = "sema1";
volatile u32 X = 0, Y = 0;

int main(int argc, char *argv[])
{
	pthread_t th00, th01, th02, th03;
	void *status;

	printf("[+] Indul a progi...\n");

	s0 = sem_open(semname_0, O_CREAT, 0777, 0);
	if(s0 == SEM_FAILED){
		fprintf(stderr, "%s failed.\n", semname_0);
		exit(EXIT_FAILURE);
	}

	s1 = sem_open(semname_1, O_CREAT, 0777, 0);
	if(s1 == SEM_FAILED){
		fprintf(stderr, "%s failed.\n", semname_1);
		exit(EXIT_FAILURE);
	}

	for(u8 i = 4; i > 0; i--){
		printf("Sempost : %i\n", i);
		sem_post(s0);
		sem_post(s1);
	}

	pthread_create(&th00, NULL, func_th00, NULL);
	pthread_create(&th01, NULL, func_th01, NULL);
	pthread_create(&th02, NULL, func_th02, NULL);
	pthread_create(&th03, NULL, func_th03, NULL);

	pthread_join(th00, &status);
	pthread_join(th01, &status);
	pthread_join(th02, &status);
	pthread_join(th03, &status);

	sem_unlink(semname_0);
	sem_unlink(semname_1);

	printf("[+] Main thread finished.\n");
	return 0;
}

void *func_th00(void *args){
	while(1){
		sem_wait(s0);
		printf("-TH00-ból, X: %d.\n", X );		
		printf("===\n");
		//usleep(500000);
		X++;
		usleep(2000000);
		sem_post(s0);
	}
}

void *func_th01(void *args){
	usleep(20);
	while(1){
		sem_wait(s0);
		printf("-TH01-ból, X: %d.\n", X );
		printf("===\n");
		//usleep(500000);
		X++;
		usleep(2000000);
		sem_post(s0);
	}
}

void *func_th02(void *args){
	while(1){
		sem_wait(s1);
		printf("-TH02-ból, Y: %d.\n", Y );
		printf("===\n");
		//usleep(500000);
		//printf(");
		Y++;
		usleep(5000000);
		sem_post(s1);
	}
}

void *func_th03(void *args){
	usleep(20);
	while(1){
		sem_wait(s1);
		printf("-TH03-ból, Y: %d.\n", Y );
		printf("===\n");
		//usleep(500000);
		Y++;
		usleep(2000000);
		sem_post(s1);
	}
}

















