#include <stdio.h>

int main(){
	
	int i,j,a,k;
	char c;
	
	printf("반복할 수 입력: ");
	scanf("%d",&a);
	
	for(k=1; k<=a; k++){
		printf("\n반복할 문자와 수 입력 : "); 
		scanf(" %c %d",&c,&i);
		for(j=0; j<i; j++){
			printf("%c",c);	
		}
	}
	
	return 0;
}


