#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp1;
	char ch;
	int count = 0;
	int n = 10;
	FILE *fp2;
	fp1 = fopen("text.txt", "r");
	fp2 = fopen("text.txt", "r");
	if(!fp1){
		printf("NO");
		exit(101);
	}
	while((fscanf(fp1, "%c", &ch)) == 1){
		if(ch == '\n')
			count++;
	}
	fclose(fp1);
	int diff = count-n;
	if(diff > 0){
		count = 0;
		while((fscanf(fp2, "%c", &ch)) == 1){
			if(ch == '\n'){
				count++;
			}
			if(count >=diff){
				if(count == diff && ch == '\n')
					fscanf(fp2, "%c", &ch);
				printf("%c", ch);
			}
		}
	}
	else{
		while((fscanf(fp2, "%c", &ch)) == 1)
			printf("%c", ch);
	}
	fclose(fp2);		
	return 0;	
}
