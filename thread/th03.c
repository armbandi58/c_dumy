//Vacsorazo filozofusok
/*LEhet késleltetni az egyiknek a létrehozását, vagy post-olok 5-t nem 4-t*/
#include "main.h"

void *func_th00(void *arg);
void *func_th01(void *arg);
void *func_th02(void *arg);
void *func_th03(void *arg);

sem_t *s0;
static const char *semname_0 = "Semaphore_0";

int main(int argc, char *argv[])
{
	pthread_t th00, th01, th02, th03;
	void *status;

	printf("Na had menjen\n");

	s0 = sem_open(semname_0, O_CREAT, 0777, 0);
	if(s0 == SEM_FAILED){
		fprintf(stderr, "%s failed\n", semname_0);
		exit(EXIT_FAILURE);
	}

	sem_post(s0);
	sem_post(s0);
	sem_post(s0);
	sem_post(s0);

	pthread_create(&th00, NULL, func_th00, NULL);
	pthread_create(&th01, NULL, func_th01, NULL);
	pthread_create(&th02, NULL, func_th02, NULL);
	pthread_create(&th03, NULL, func_th03, NULL);

	sem_post(s0);

	pthread_join(th00, &status);
	pthread_join(th01, &status);
	pthread_join(th02, &status);
	pthread_join(th03, &status);

	sem_unlink(semname_0);

	return 0;
}

void *func_th00(void *arg){
	sem_wait(s0);
	printf("PH0 active.\n");
	sleep(1);
	sem_wait(s0);
	printf("PH0 eat.\n");
	sleep(2);
	sem_post(s0);
	printf("PH0 finished.\n");
}

void *func_th01(void *arg){
	sem_wait(s0);
	printf("PH1 active.\n");
	sleep(1);
	sem_wait(s0);
	printf("PH1 eat.\n");
	sleep(2);
	sem_post(s0);
	printf("PH1 finished.\n");
}

void *func_th02(void *arg){
	sem_wait(s0);
	printf("PH2 active.\n");
	sleep(1);
	sem_wait(s0);
	printf("PH2 eat.\n");
	sleep(2);
	sem_post(s0);
	printf("PH2 finished.\n");
}

void *func_th03(void *arg){
	sem_wait(s0);
	printf("PH3 active.\n");
	sleep(1);
	sem_wait(s0);
	printf("PH3 eat.\n");
	sleep(2);
	sem_post(s0);
	printf("PH3 finished.\n");
}























