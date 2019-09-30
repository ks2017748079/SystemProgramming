 #include<stdio.h> 
 #include<stdlib.h> 
 #include<unistd.h> 
 #include<fcntl.h> 
 #include<ctype.h> 
 #define BUFSIZE 512  
 
 
 int main(int argc, char *argv[]) 
 { 
    FILE * fd; 
    char str[] = {}; 
    char tx; 
    int num = 0; 
    int i = 0; 
 
 
    if(argc == 1){ 
       if((fd = fopen("file", "w+")) == NULL){ 
          perror("file"); 
          exit(1); 
       } 
       printf("file context \n"); 
       while(fgets(str, BUFSIZE, stdin) != NULL){ 
          fprintf(fd, "%s", str); 
       }    
    } 
    else if((fd = fopen(argv[1], "rw")) == NULL){ 
       perror(argv[1]); 
       exit(2); 
    } 
    fseek(fd, 0, SEEK_SET); 
    i = 0; 
    while(1){ 
       tx = fgetc(fd); 
       if(tx == ' ')num--; 
       if(tx == EOF) { 
          num--; 
          break; 
       } 
       str[i] = tx; 
       i++; 
       num++; 
    } 
    printf("file characters : %d\n", num); 
    num = 0; 
     
    i = 0; 
    while(str[i] != '\0'){ 
       while(isspace(str[i])) 
          i++; 
       if(str[i] != '\0')num++; 
       while(!isspace(str[i]) && str[i] != '\0')i++; 
    } 
    num--; 
    printf("file word : %d\n", num); 
    num = 0; 
     
    fseek(fd, 0, SEEK_SET); 
    i = 0; 
    while(1){ 
       if(str[i] == '\n') num++; 
       else if(str[i] == EOF){ 
                 break; 
       } 
       i++; 
    } 
    printf("file line : %d\n", num); 

 
    fclose(fd); 
    exit(0); 
 } 

