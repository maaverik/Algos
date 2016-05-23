#include<stdio.h>

int bin_search(int *a,int k,int beg,int end){
	while(beg<end){
		int mid;
		mid=(beg+end)/2;
		if(a[mid]==k){
			printf("%d\n",mid+1);
			return 1;
		}
		else if(a[mid]>k){
			end=mid;
		}
		else
			beg=mid+1;
	}
	return 0;
}

int main(){
	int n,k,a[2001],i;
	if(!scanf("%d",&n) || (n<=0)){
		printf("Invalid input\n");
		return 0;
	}
	for(i=0;i<n;i++){
		if(!scanf("%d",&a[i])){
			printf("Invalid input\n");
			return 0;
		}
		if((i!=0)&&(a[i]<=a[i-1])){
			printf("Invalid input or input not sorted in strictly increasing order...\n");
			return 0;
		}
	}
	if(!scanf("%d",&k)){
			printf("Invalid input\n");
			return 0;
	}
	int res=bin_search(a,k,0,n);
	if(res==0)
		printf("NOT FOUND\n");
	return 0;
}