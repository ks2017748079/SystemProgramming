#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[]){

	printf("Hello\n");
	sleep(atoi(argv[1]));
	printf("Bye\n");
}

