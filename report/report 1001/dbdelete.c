#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "student.h"

int main(int argc, char *argv[])
{
	int fd, id;
	char c;
	struct student record;
	if(argc < 2){
		fprintf(stderr, "instructions : %s filn",argv[0]);
		exit(1);
	}
	if((fd = open(argv[1], O_RDWR)) == -1){
		perror(argv[1]);
		exit(2);
	}
	do{
		printf("delete student number: ");
		if(scanf("%d",&id) == 1){
			lseek(fd,(long)(id - START_ID*sizeof(record)),SEEK_SET);
			if((read(fd,(char *)&record, sizeof(record)) > 0) && (record.id != 0)){
				record.id = '\0';
				record.score = '\0';
				*record.name = '\0';
				lseek(fd,(long)-sizeof(record),SEEK_CUR);
				write(fd,(char *)&record,sizeof(record));
			}else printf("record %d none \n",id);
		}else printf("error\n");
		printf("continue(Y/N)");
		scanf("%c", &c);
	}while(c == 'Y');
	close(fd);
	exit(0);
}

