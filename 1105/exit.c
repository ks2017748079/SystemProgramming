#include <stdio.h>
  static void my_exit1(void), my_exit2(void);
  
  int main(void) {
  if (atexit(exit_handler1) != 0)	
     perror("exit_handler1 register none");
  if (atexit(exit_handler2) != 0) 	
     perror("exit_handler2 register none");
   printf("main end \n");
 exit(0);
}
static void exit_handler1(void) {
    printf("first exit \n");
 }

 static void exit_handler2(void) {
    printf("second exit \n");
 }
