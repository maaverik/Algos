#include<stdio.h>

void clkwse(long long a[][101],int m,int n){
	int r1,r2,c1,c2,i,j,k,l,check,count;
	r1=0;
	r2=m-1;
	c1=n-1;
	c2=0;
	k=n;
	l=m;
	i=0;
	check=1;
	count=0;
	while (check){
		for(j=i;j<k;j++){			//first row
			printf("%lld  ",a[r1][j]);
			count++;
			if (count== m*n){
				check=0;
				break;
			}
		}	
		if(!check)
			break;
		for(j=i+1;j<l;j++){			//last column
			printf("%lld  ",a[j][c1]);
			count++;
			if (count== m*n){
				check=0;
				break;
			}
		}	
		if(!check)
			break;
		for(j=k-2;j>=i;j--){		//last row
			printf("%lld  ",a[r2][j]);
			count++;
			if (count== m*n){
				check=0;
				break;
			}
		}
		if(!check)
			break;
		for(j=k-1;j>i;j--){			//first column
			printf("%lld  ",a[j][c2]);
			count++;
			if (count== m*n){
				check=0;
				break;
			}
		}	
		if(!check)
			break;
		r1++;
		c1--;
		r2--;
		c2++;
		k--;
		i++;
		l--;
	}
	printf("\n");
}


void anticlkwse(long long a[][101],int m,int n){
	int r1,r2,c1,c2,i,j,k,l,check,count;
	r1=0;
	r2=m-1;
	c1=n-1;
	c2=0;
	k=m;
	l=n;
	i=0;
	check=1;
	count=0;
	while (check){
		for(j=i;j<k;j++){			//first column
			printf("%lld  ",a[j][c2]);
			count++;
			if (count== m*n){
				check=0;
				break;
			}
		}	
		//printf("Loop 1\n");

		if(!check)
			break;
		for(j=i+1;j<l;j++){			//last row
			printf("%lld  ",a[r2][j]);
			count++;
			if (count== m*n){
				check=0;
				break;
			}
		}
		//	printf("Loop 2\n");	
		if(!check)
			break;
		for(j=k-2;j>=i;j--){		//last column
			printf("%lld  ",a[j][c1]);
			count++;
			if (count== m*n){
				check=0;
				break;
			}
		}
		//	printf("Loop 3\n");
		if(!check)
			break;
		for(j=l-2;j>i;j--){			//first row
			printf("%lld  ",a[r1][j]);
			count++;
			if (count== m*n){
				check=0;
				break;
			}
		}	
		//	printf("Loop 4\n");
		if(!check)
			break;
		r1++;
		c1--;
		r2--;
		c2++;
		k--;
		i++;
		l--;
	}
	printf("\n");


}


int main(){
	long long mat[101][101];
	int i,j,m,n;
	printf("Enter m and n: \n");
	if(!scanf("%d",&m) || !scanf("%d",&n) || (m<=0) || (n<=0)){
		printf("Invalid size\n");
		return 0;
	}
	printf("Enter elements\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(!scanf("%lld",&mat[i][j])){
				printf("Invalid input....\n");
				return 0;
			}
		}
	}
	while (1){
		char ch;
		printf("Menu:\na. Clockwise spiral-order traversal\nb. Anti-clockwise spiral-order traversal\nc. Exit\n");
		while(getchar()!='\n'); //To clear input buffer
		scanf("%c",&ch);
		switch(ch){
			case 'a':clkwse(mat,m,n);break;
			case 'b':anticlkwse(mat,m,n);break;
			case 'c':return 0;
			default:printf("Invalid input...Try again\n");
		}
	}
}