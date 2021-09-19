#include "main.h"

/*
#define Work_size 1024

sem_t bin_sem;
char work_area[Work_size];

void *th00_func(void *arg);

int main(int argc, char *argv[])
{
	int res;
	pthread_t th00;
	void *thread_res;

	//res = sem_init(&bin_sem,0,0);
	res = sem_open(&bin_sem,1,1);
	res = pthread_create(&th00,NULL,th00_func,NULL);
	printf("Irj be valamit:\n");

	while(strncmp("end", work_area, 3) != 0){
		fgets(work_area, Work_size, stdin);
		sem_post(&bin_sem);
	}

	printf("\nWait for thread finishing.\n");

	res = pthread_join(th00, &thread_res);
	printf("Thread joined.\n");
	//sem_destroy(&bin_sem);
	sem_close(&bin_sem);

	return 0;
}

void *th00_func(void *arg){
	printf("[+] TH00 started.\n");

	sleep(1);
	sem_wait(&bin_sem);
	while(strncmp("end", work_area, 3) != 0){
		printf("Ennyit cuccot irtal be: %d",strlen(work_area)-1);
		sem_wait(&bin_sem);
	}
	pthread_exit(NULL);
}
*/
#define Work_size 1024

sem_t bin_sem;
char work_area[Work_size];

void *th00_func(void *arg);
void *th01_func(void *arg);
void *th02_func(void *arg);

void *status;

sem_t *s0;
sem_t *s1;
//sem_t *s2;
static const char *semname_0 = "Semaphore_0";
static const char *semname_1 = "Semaphore_1";
//static const char *semname_2 = "Semaphore_2";

int main(int argc, char *argv[])
{
	pthread_t th00;
	pthread_t th01;
	pthread_t th02;

	pthread_create(&th00, NULL, th00_func, NULL);
	pthread_create(&th01, NULL, th01_func, NULL);
	pthread_create(&th02, NULL, th02_func, NULL);

	s0 = sem_open(semname_0, O_CREAT, 0777, 0);
	if(s0 == SEM_FAILED){
		fprintf(stderr, "%s\n", "ERROR creating semaphore semname1");
      	exit(EXIT_FAILURE);
	}

	s1 = sem_open(semname_1, O_CREAT, 0777, 0);
	if(s1 == SEM_FAILED){
		fprintf(stderr, "%s\n", "ERROR creating semaphore semname1");
      	exit(EXIT_FAILURE);
	}
/*
	s2 = sem_open(semname_2, O_CREATE, 0777, 0);
	if(s2 == SEM_FAILED){
		fprintf(stderr, "%s\n", "ERROR creating semaphore semname1");
      	exit(EXIT_FAILURE);
	}
*/
	while(strncmp("end", work_area, 3) != 0){
		fgets(work_area, Work_size, stdin);
		sem_post(s0);
	}

	printf("Atment\n");

	pthread_join(th00, &status);
	pthread_join(th01, &status);
	pthread_join(th02, &status);

	sem_unlink(semname_0);
	sem_unlink(semname_1);
//	sem_unlink(semname_2);

	printf("[+] Main thread stopped.\n");
	return 0;
}

void *th00_func(void *arg){
	printf("[+] TH00 init.\n");

	sem_wait(s0);
	while(strncmp("end", work_area, 3) != 0){
		printf("Ennyit karaktert irtal be: %d.\n", strlen(work_area)-1);
		sem_wait(s0);
	}
	sem_post(s1);
	printf("Thread00 finished.\n");
}

void *th01_func(void *arg){
	printf("[+] TH01 init.\n");
	sem_wait(s1);
	
	for(u8 i = 0; i < 5; i++){
		printf("th00: %i\n", i);
		sleep(1);
		//sem_wait(s0);
	}
	printf("Thread01 finished.\n");
}

void *th02_func(void *arg){
	while(1){
		printf("\t%s.\n", status);
		sleep(1);
	}
}

























