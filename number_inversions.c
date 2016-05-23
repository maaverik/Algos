#include<stdio.h>

int merge_count(int a[],int beg,int end){
	int b[1500],c[1500],i,j,k,cnt;
	int mid=(beg+end)/2;
	int n1=mid-beg+1;
	int n2=end-mid;
	for(i=0;i<n1;i++){
		b[i]=a[beg+i];
	}
	for(j=0;j<n2;j++){
		c[j]=a[mid+j+1];
	}
	i=j=cnt=0;
	k=beg;
	while(i<n1 && j<n2){
		if(b[i]<=c[j]){
			a[k]=b[i];
			i++;
			k++;
		}
		else {
			a[k]=c[j];
			j++;
			k++;
			cnt+=n1-i;
		}
	}
	while(i<n1){
		a[k]=b[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=c[j];
		j++;
		k++;
	}
	return cnt;
}

int count(int a[],int beg,int end){
	printf("Beg :%d, End:%d\n",beg,end);
	if(beg>=end)
		return 0;
	int mid=(beg+end)/2;
	int x=count(a,beg,mid);
	int y=count(a,mid+1,end);
	int z=merge_count(a,beg,end);
	return x+y+z;
}

int main(){
	int n,k,i;
	int a[2001];
	if((!scanf("%d",&n)) || (n<=0)){
		printf("Invalid input\n");
		return 0;
	}
	for(i=0;i<n;i++){
		if(!scanf("%d",&a[i])){
			printf("Invalid input...\n");
			return 0;
		}
	}
	printf("%d\n",count(a,0,n-1));
	return 0;
}