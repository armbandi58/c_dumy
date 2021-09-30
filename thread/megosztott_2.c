#include "includes.h"

int main()
{
	char c;
	char buff[1024];
	int shmid;
	char *shmptr;

	shmid = shmget(1234, 1024, 0666);
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
		scanf("%s", buff);
		if(!strcmp("quit",buff)){
			shmptr[1023] = 'q';
			break;
		}
		while(shmptr[1023] != 0)
			usleep(100);

		strcpy(shmptr, buff);
		shmptr[1023] = 1;
	}
	usleep(10);
	shmdt(shmptr);
	
	return 0;
}