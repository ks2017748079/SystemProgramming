#include <stdio.h>

int main(){
	
	int i,j,a,k;
	char c;
	
	printf("�ݺ��� �� �Է�: ");
	scanf("%d",&a);
	
	for(k=1; k<=a; k++){
		printf("\n�ݺ��� ���ڿ� �� �Է� : "); 
		scanf(" %c %d",&c,&i);
		for(j=0; j<i; j++){
			printf("%c",c);	
		}
	}
	
	return 0;
}


