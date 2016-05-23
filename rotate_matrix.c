#include<stdio.h>

void rotate(long long m[][101],int n){
	int j,c1,c2,i;
	long long temp;
	c1=0;
	c2=n-1;
	while(c1<c2){
		for(j=0;j<n;j++){
			temp=m[j][c1];
			m[j][c1]=m[j][c2];
			m[j][c2]=temp;
		}
		c1++;
		c2--;
	}
}

int main(){
	long long mat[101][101];
	int i,j,n;
	printf("Enter n: ");
	scanf("%d",&n);
	if(n<=0){
		printf("Invalid size\n");
		return 0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(!scanf("%lld",&mat[i][j])){
				printf("Invalid input...\n");
				return 0;
			}
		}
	}
	long long temp;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			temp=mat[i][j];
			mat[i][j]=mat[j][i];
			mat[j][i]=temp;

		}
	}
	rotate(mat,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%lld  ",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}