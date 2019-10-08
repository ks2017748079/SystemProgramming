  #include <stdio.h>
   #include <stdlib.h>
   #include <unistd.h>
   #include <fcntl.h>
   #include "student.h"
   	

   int main(int argc, char *argv[])
 {
     int fd, id;
     struct student record;
	
     if (argc < 2) {
	 fprintf(stderr, "instruction : %s file\n", argv[0]);
	 exit(1);
     }
 if ((fd = open(argv[1], O_RDWR)) == -1) {
	 perror(argv[1]);
	 exit(2);
     }
	
     printf("\n update students id :");
     while (scanf("%d", &id) == 1) {
	 lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
	 if (lockf(fd, F_LOCK, sizeof(record)) == -1) { 
	     perror(argv[1]);
	     exit(3);
	 }
	
	 if ((read(fd, (char *) &record, sizeof(record)) > 0) &&  (record.id != 0)) 
	 printf("\n name :%s\n id:%d\n score:%d\n",  
                    record.name, record.id, record.score);
	 else printf("record %d none\n", id);

 printf("new score: ");
	 scanf("%d", &record.score);
	 lseek(fd, (long) -sizeof(record), SEEK_CUR);
	 write(fd, (char *) &record, sizeof(record));
	
	 lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
	 lockf(fd, F_ULOCK, sizeof(record)); 
	 printf("\n update student id:");
     }
	
     close(fd);
     exit(0);
 }

