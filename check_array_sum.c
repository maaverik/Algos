#include<stdio.h>

void findpair(int a[],int n,int sum){
	int i=0,j=n-1;
	while((i<j)){
		if(a[i]+a[j]==sum){
			printf("%d %d\n",a[i],a[j]);
			return;
		}
		else if((a[i]+a[j]<sum)){
			i++;
		}
		else{
			j--;
		}
	}
	printf("No two elements sum up to %d\n",sum);
}

int main(){
	int j,n,a[2001],x;
	//printf("Enter size and then the array\n");
	if( !scanf("%d",&n) || (n<=0)){
		printf("Invalid size\n");
		return 0;
	}
	for(j=0;j<n;j++){
		if(!scanf("%d",&a[j])){
			printf("Invalid input\n");
			return 0;
		}
		if((j!=0) && (a[j]<a[j-1])){
			printf("Invalid...Not sorted\n");
			return 0;
		}		
	}
	//printf("Enter required sum\n");
	if(!scanf("%d",&x)){
		printf("Invalid input\n" );
	}
	findpair(a,n,x);
}