#include<stdio.h>


void merge(int a[],int p,int r){
	int q=(p+r)/2;
	//printf("p :%d q :%d r :%d\n",p,q,r);
	int n1=q-p+1;
	int n2=r-q;
	int i,j,k,c[250],b[250];
	for(i=0;i<n1;i++){
		b[i]=a[p+i];
		//printf("b[%d]:%d\n",i,b[i]);
	}
	for(j=0;j<n2;j++){
		c[j]=a[q+j+1];
		//printf("c[%d]:%d\n",j,b[j]);
	}
	i=j=0;
	k=p;
	while ((i<n1) && (j<n2)){
        if (b[i]<=c[j]){
            a[k]=b[i];
            i++;
        }
        else{
            a[k]=c[j];
            j++;
        }
        k++;
    }
    //printf("i:%d j:%d",i,j);
    while ((i<n1)){
        a[k]=b[i];
        i++;
        k++;
    }
    while ((j<n2)){
        a[k]=c[j];
        j++;
        k++;
    }
}


void mergesort(int a[],int beg,int end){
	if(beg>=end){
		return;
	}
	mergesort(a,beg,(beg+end)/2);
	mergesort(a,(beg+end)/2+1,end);
	merge(a,beg,end);
	
}



int main(){
	FILE *fp;
	int i=0,a[10010];
	if(!(fp=fopen("NUMBERS","r"))){
		printf("File doesn't exist\n");
		return 0;
	}
	while((!feof(fp))){
		if((i>=10000)){
			printf("Invalid....Integer limit exceeded\n");
			return 0;
		}
		if (!fscanf(fp,"%d",&a[i])){
			printf("Invalid input\n");
			return 0;
		}		
		//printf("i:%d a[i]:%d\n",i,a[i] );
		i++;
		
	}
	if(i==1){
		printf("File is empty\n");
		return 0;
	}
	int j;
	fclose(fp);
	if(i!=0){
		mergesort(a,0,i-2);
	}
	else{
		printf("Invalid\n");
		return 0;
	}
	fp=fopen("OUTPUT","w");
	for(j=0;j<i-1;j++){
		fprintf(fp,"%d\n",a[j]);
	}
	return 0;
}