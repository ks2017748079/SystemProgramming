#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	FILE * fd1;
	FILE * fd2;
	int num = 0, fl = 1;

	if(argc != 3){
		fprintf(stderr, "instructions : %s file1, file2\n", argv[0]);
		exit(1);
	}
	if((fd1 = fopen(argv[1], "r")) == NULL){
		perror(argv[1]);
		exit(2);
	}
	if((fd2 = fopen(argv[2], "r")) == NULL){
		perror(argv[2]);
		exit(3);
	}

	while(1){
		num++;
		char one = fgetc(fd1);
		char two = fgetc(fd2);
		if(one != two){
			printf("%d location  \n", num);
			printf("file1 %d location : %c\n", num, one);
			printf("file2 %d location : %c\n", num, two);
			fl = 0;
		}
		if(one == EOF || two == EOF) break;
	}
	

	fclose(fd1);
	fclose(fd2);
	exit(0);
}


