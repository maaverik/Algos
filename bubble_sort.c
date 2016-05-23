#include<stdio.h>

void bubble(float a[],int n){
	int i;
	int j;
	float temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				//printf("a[j]:%f a[j+1]:%f\n",a[j],a[j+1]);
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				//printf("a[j]:%f a[j+1]:%f\n",a[j],a[j+1]);
			}
		}
	}
}

int main(){
	int n,k,i;
	float a[2001];
	if((!scanf("%d",&n)) || (n<=0)){
		printf("Invalid input\n");
		return 0;
	}
	for(i=0;i<n;i++){
		if(!scanf("%f",&a[i])){
			printf("Invalid input\n");
			return 0;
		}
	}
	bubble(a,n);
	for(i=0;i<n;i++){
		printf("%g ",a[i]);
	}
	printf("\n");
	return 0;
}