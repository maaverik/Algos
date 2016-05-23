#include <stdio.h>

void maxheapify(int a[],int i){
	//printf("Entered maxheapify\n");
	int left=2*i;
	int right=2*i+1;
	int large=i;
	if (left<=a[0] && a[left]>a[large]){
		large=left;
	}
	if( right<=a[0] && a[right]>a[large] ){
		large=right;
	}
	if(large==i){
		return;
	}
	else{
		int temp=a[i];
		a[i]=a[large];
		a[large]=temp;
		maxheapify(a,large);
	}
}


void heapsrt(int a[],int n){
	int i;
	//printf("Entered heapsrt\n");
	for(i=n/2;i>=1;i--){ 	//To build the heap
		maxheapify(a,i);
	}
	//printf("Built heap\n");
	for(i=n;i>=2;i--){
		int temp=a[i];
		a[i]=a[1];
		a[1]=temp;
		a[0]--;
		maxheapify(a,1);
	}
}

int main(){
	int n,k,i;
	int a[2001];
	if((!scanf("%d",&n)) || (n<=0)){
		printf("Invalid size\n");
		return 0;
	}
	a[0]=n;		//To store heapsize
	for(i=1;i<=n;i++){
		if(!scanf("%d",&a[i])){
			printf("Invalid input...\n");
			return 0;
		}
	}
	heapsrt(a,n);
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
