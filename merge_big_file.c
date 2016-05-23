#include<stdio.h>
#include<string.h>
#include<time.h>

#define max 1024*1024

int partition(int s[],int p,int r){
	//printf("In partition, p : %d, r :%d\n",p,r);
	int piv=s[r];
	//printf("Pivot : %d\n",piv);
	int i=p-1,j;
	for(j=p;j<r;j++){
		if(s[j]<=piv){
			i++;
			int temp=s[j];
			s[j]=s[i];
			s[i]=temp;
		}		
	}
	int temp=s[i+1];
	s[i+1]=s[r];
	s[r]=temp;
	return i+1;
}

void quicksrt(int s[],int p,int r){
	//printf("In quicksrt, p : %d, r :%d\n",p,r);
	if (p>=r){
		return ;
	}
	else{
		int q=partition(s,p,r);
		quicksrt(s,p,q-1);
		quicksrt(s,q+1,r);
	}
}

merge2(char outfile[],char file1[],char file2[],int factor){
	//printf("In merge 2, factor is:%d\n",factor );
	FILE *fp1=fopen(outfile,"w");
	FILE *fp2=fopen(file1,"r");
	FILE *fp3=fopen(file2,"r");	
	int a,b,i=0,j=0;
	fscanf(fp2,"%d",&a);
	fscanf(fp3,"%d",&b);
	while(i<max*factor && j<max*factor){
		if(a<b){
			fprintf(fp1,"%d\n",a);
			i++;
			fscanf(fp2,"%d",&a);
		}
		else {
			fprintf(fp1,"%d\n",b);
			j++;
			fscanf(fp3,"%d",&b);
		}
	}
	while(i<max*factor){
		fprintf(fp1,"%d\n",a);
		i++;
		fscanf(fp2,"%d",&a);
	}
	while (j<max*factor){
		fprintf(fp1,"%d\n",b);
		j++;
		fscanf(fp3,"%d",&b);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	//printf("Leaving merge 2, factor is:%d\n",factor );
}

merge4(char outfile[],char file1[],char file2[],char file3[],char file4[],int factor){
	//printf("In merge 4, factor is:%d\n",factor );
	merge2("4Temp1",file1,file2,factor);
	merge2("4Temp2",file3,file4,factor);
	merge2(outfile,"4Temp1","4Temp2",2*factor);
	remove("4Temp1");
	remove("4Temp2");
	//printf("Leaving merge 4, factor is:%d\n",factor );
}

merge8(char outfile[],char filenames[][10],int factor){
	//printf("In merge 8, factor is:%d\n",factor );
	merge4("8Temp1",filenames[0],filenames[1],filenames[2],filenames[3],factor);
	merge4("8Temp2",filenames[4],filenames[5],filenames[6],filenames[7],factor);
	merge2(outfile,"8Temp1","8Temp2",4*factor);
	//printf("Leaving merge 8,factor is:%d\n",factor );
	remove("8Temp1");
	remove("8Temp2");
}

int main(){
	char ipfile[]="Bigfile",opfile[]="SORTED BIGFILE",file64[]="64fileXX",file8[]="8fileX";
	FILE *fp;
	int i,x,j;
	fp=fopen(ipfile,"w");
	srand(time(NULL));
	for(i=0;i<64*max;i++){			//make random file
		x=rand()%1000;
		fprintf(fp,"%d\n",x);
	}
	fclose(fp);
	int a[max+10];
	fp=fopen(ipfile,"r");
	//printf("Beginning sort\n");
	for(i=0;i<64;i++){		
		//printf("Making file:%d\n",i+1 );

		for(j=0;j<max;j++){		//make 64 sorted files
			fscanf(fp,"%d",&a[j]);
		}
		quicksrt(a,0,max-1);
		file64[6]='0'+i/10;
		file64[7]='0'+i%10;
		FILE *fp64=fopen(file64,"w");
		for(j=0;j<max;j++){
			fprintf(fp64,"%d\n",a[j]);
		}
		fclose(fp64);
	}
	int k=0;
	//printf("Starting 8 way merge\n");
	for(i=0;i<8;i++){					//8 way merge
		char filenames[10][10];
		file8[5]='0'+i;
		for(j=0;j<8;j++){
			file64[6]='0'+k/10;
			file64[7]='0'+k%10;
			k++;
			strcpy(filenames[j],file64);
		}
		merge8(file8,filenames,1);
	}
	//printf("Starting 4 way merge\n");
	merge4("4file0","8file0","8file1","8file2","8file3",8);		//4 way merge
	merge4("4file1","8file4","8file5","8file6","8file7",8);
	//printf("Starting 2 way merge\n");	
	merge2(opfile,"4file0","4file1",32);						//2 way merge
	return 0;
}