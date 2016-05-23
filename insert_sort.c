#include<stdio.h>

void insert(int *a,int n){
	int i,j,k;
	for(i=1;i<n;i++){
		j=i-1;
		//printf("j:%d\n",j);
		k=a[i];
		while((k<a[j]) && (j>=0)){
			a[j+1]=a[j];
			//printf("a[j+1]:d\n",a[j+1]);
			j--;
		}
		//printf("k:%d\n",k);
		a[j+1]=k;
	}
}

int main(){
	int n,k,i;
	int a[2001];
	if((!scanf("%d",&n)) || (n<=0)){
		printf("Invalid input....\n");
		return 0;
	}
	for(i=0;i<n;i++){
		if(!scanf("%d",&a[i]) || (a[i]<0)){
			printf("Invalid input....\n");
			return 0;
		}
	}
	insert(a,n);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}