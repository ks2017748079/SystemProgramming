#include <stdio.h>
#include "student.h"

int main(int argc, char *argv[])
{
   struct student rec;
   int id;
   char c;
   FILE *fp;
   if (argc != 2) {
      fprintf(stderr, "instructions: %s file name\n", argv[0]);
      exit(1);
   }

   if ((fp = fopen(argv[1], "rb+")) == NULL) {
      fprintf(stderr, "file open error\n");
      exit(2);
   }
   
   do {
   printf("update students id: ");
   if (scanf("%d", &id) == 1) {
      fseek(fp, (id - START_ID) * sizeof(rec), SEEK_SET);
      if ((fread(&rec, sizeof(rec), 1, fp) > 0)&&(rec.id != 0)) {
         printf("id: %8d name: %4s score: %4d\n", rec.id, rec.name, rec.score);
         printf("new score: ");
         scanf("%d", &rec.score);
         fseek(fp, -sizeof(rec), SEEK_CUR);
         fwrite(&rec, sizeof(rec), 1, fp);
      } else printf("record %d none\n", id);
   } else printf("error\n");

   printf("continue?(Y/N)");
   scanf(" %c",&c);
} while (c == 'Y');
fclose(fp);
exit(0);
}

