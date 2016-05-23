#include<stdio.h>


void avg(long long a[101][101],int n){
	int count=0,sum=0;
	int newi,newj;
	int i,j,k,l;
	long long b[101][101];
	for( i=0;i<n;i++){
		for( j=0;j<n;j++){
			count=sum=0;
			newi=i-1;
			for( k=0;k<3;k++){
				newj=j-1;
				for( l=0;l<3;l++){
					//cout<<"newi and newj are "<<newi<<"  "<<newj<<endl;
					if((newi>=0)&&(newi<n)&&(newj>=0)&&(newj<n)){
						count++;
						sum+=a[newi][newj];
						
					}
					//cout<<"Count is "<<count<<endl;
					newj++;
				}
				newi++;
			}
			float temp=(float)sum/count - sum/count;
			if(count!=0)
				b[i][j]=(temp>=.5)?sum/count+1:sum/count;
			else
				b[i][j]=-1;
		}
	}
	for( i=0;i<n;i++){
		for( j=0;j<n;j++){
			a[i][j]=b[i][j];
		}
	}
}

int main(){
	long long a[101][101];
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	if((n<=0) || (n>101)){
		printf("Invalid...\n");
		return 0;
	}
	int i,j;
	printf("Enter matrix: ");
	for(i=0;i<n;i++){
		for (j=0;j<n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]<0){
				printf("Enter a valid input next time\n");
				return 0;
			}
		}
	}
	avg(a,n);
	//output matrix
	for(i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf("%lld  ",a[i][j]);
		}
		printf("\n");
	}
}
