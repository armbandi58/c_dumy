#include "includes.h"

int main()
{
	char c;
	char buff[1024];
	int shmid;
	char *shmptr;

	shmid = shmget(1234, 1024, IPC_CREAT|0666);
	if(shmid < 0){
		fprintf(stderr, "Sikertelen foglalas.\n");
		return 1;
	}

	shmptr = shmat(shmid, 0, 0);
	if(shmptr == NULL){
		fprintf(stderr, "Nem sikerult felcsatlakozni\n");
		return 1;
	}

	while(1){
		while(shmptr[1023] == 0){
			usleep(100);
		}
		if(shmptr[1023] == 'q')
			break;

		printf("%s", shmptr);
		fflush(stdout);
		shmptr[1023] = 0;
	}
	sleep(1);
	printf("[+] Shutdown...\n");

	shmdt(shmptr);
	shmctl(shmid, IPC_RMID, 0);

	return 0;
}