#include "main.h"

void *func_ph00(void *arg);
void *func_ph01(void *arg);
void *func_ph02(void *arg);
void *func_ph03(void *arg);

pthread_mutex_t v0, v1, v2, v3;

int main(int argc, char *argv[])
{
	pthread_t th00, th01, th02, th03;
	void *status;
	int res;

	res = pthread_mutex_init(&v0, NULL);
	res = pthread_mutex_init(&v1, NULL);
	res = pthread_mutex_init(&v2, NULL);
	res = pthread_mutex_init(&v3, NULL);

	pthread_create(&th00, NULL, func_ph00,NULL);
	pthread_create(&th01, NULL, func_ph01,NULL);
	pthread_create(&th02, NULL, func_ph02,NULL);
	pthread_create(&th03, NULL, func_ph03,NULL);

	pthread_join(th00, &status);
	pthread_join(th01, &status);
	pthread_join(th02, &status);
	pthread_join(th03, &status);

	pthread_mutex_destroy(&v0);
	pthread_mutex_destroy(&v1);
	pthread_mutex_destroy(&v2);
	pthread_mutex_destroy(&v3);

	return 0;
}

void *func_ph00(void *arg){
	sleep(3);
	printf("PH00 activeted.\n");
	pthread_mutex_lock(&v0);
	usleep(500000);
	pthread_mutex_lock(&v3);
	printf("PH00 jot erez.\n");
	usleep(1000000);
	pthread_mutex_unlock(&v0);
	pthread_mutex_unlock(&v3);

	printf("PH00 finished.\n");

	pthread_exit(NULL);

}

void *func_ph01(void *arg){
	printf("PH01 activeted.\n");
	pthread_mutex_lock(&v1);
	usleep(500000);
	pthread_mutex_lock(&v0);
	printf("PH01 jot erez.\n");
	usleep(1000000);
	pthread_mutex_unlock(&v1);
	pthread_mutex_unlock(&v0);

	printf("PH01 finished.\n");

	pthread_exit(NULL);
}

void *func_ph02(void *arg){
	printf("PH02 activeted.\n");
	pthread_mutex_lock(&v2);
	usleep(500000);
	pthread_mutex_lock(&v1);
	printf("PH02 jot erez.\n");
	usleep(1000000);
	pthread_mutex_unlock(&v2);
	pthread_mutex_unlock(&v1);

	printf("PH02 finished.\n");

	pthread_exit(NULL);

}

void *func_ph03(void *arg){
	printf("PH03 activeted.\n");
	pthread_mutex_lock(&v3);
	usleep(500000);
	pthread_mutex_lock(&v2);
	printf("PH03 jot erez.\n");
	usleep(1000000);
	pthread_mutex_unlock(&v3);
	pthread_mutex_unlock(&v2);

	printf("PH03 finished.\n");

	pthread_exit(NULL);	
}






















