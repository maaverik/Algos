#include<stdio.h>
#include<string.h>
#include<ctype.h>

void select(char a[][20],int n){
	int i,j,min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
				if(strcmp(a[j],a[min])<0){
					min=j;
					//printf("a[min]:%s\n",a[min]);
				}
		}
		char temp[20];
		strcpy(temp,a[min]);
		strcpy(a[min],a[i]);
		strcpy(a[i],temp);
	}
}

int main(){
	int n,k,i,j;
	char a[200][20];
	if((!scanf("%d",&n)) || (n<=0)){
		printf("Invalid input\n");
		return 0;
	}
	for(i=0;i<n;i++){
		if(!scanf("%s",a[i]) || (strlen(a[i])>10)){
			printf("Invalid input....\n");
			return 0;
		}
		else{
			for(j=0;a[i][j]!='\0';j++){
				if(!islower(a[i][j])){
					printf("Invalid input....\n");
					return 0;
				}
			}
		}
	}
	select(a,n);
	for(i=0;i<n;i++){
		printf("%s ",a[i]);
	}
	printf("\n");
	return 0;
}