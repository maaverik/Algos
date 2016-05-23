#include<stdio.h>

int search(int a[][200],int m,int n,int k){
	int check=0,i,j;
	for( i=0;i<m;i++){
		for( j=0;j<n;j++){
			if(a[i][j]==k){
				printf("%d %d\n",i+1,j+1);
				check=1;
			}
		}
	}
	return check;
}

int main(){
	int m,n,k,a[200][200],i,j;
	if((!scanf("%d",&m)) || (m<=0) || (!scanf("%d",&n)) || (n<=0)){
		printf("Invalid size\n");
		return 0;
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			if(!scanf("%d",&a[i][j])){
				printf("Invalid input\n");
				return 0;
			}
	}
	if(!scanf("%d",&k)){
			printf("Invalid input\n");
			return 0;
	}
	int res=search(a,m,n,k);
	if(res==0)
		printf("NOT FOUND\n");
	return 0;
}