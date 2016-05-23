#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct stud{
	char rollno[80];
	char name[100];
	int mark;
};

int partition(int s[],int p,int r){
	//printf("In partition, p : %d, r :%d\n",p,r);
	int piv=s[r];
	//printf("Pivot : %d\n",piv);
	int i=p-1,j;
	for(j=p;j<r;j++){
		if(s[j]>=piv){
			i++;
			int temp=s[j];
			s[j]=s[i];
			s[i]=temp;
		}		
	}
	temp=s[i+1];
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

int main(){
	int n;
	if(!scanf("%d",&n) || (n<=0)){
		printf("Invalid size...\n");
		return 0;
	}
	int i,j;
	struct stud s[250];
	for(i=0;i<n;i++){
		if((!scanf("%s",s[i].rollno)) || (strlen(s[i].rollno)!=9) || (!scanf("%s",s[i].name)) || (!scanf("%d",&(s[i].mark)))){
			printf("Invalid input....\n");
			return 0;
		}
		if((s[i].mark<0) || (s[i].mark>100)){
			printf("Invalid marks....\n");
			return 0;
		}
		if(!isalpha((s[i].rollno)[0]) || (!isalpha((s[i].rollno)[7])) || (!isalpha((s[i].rollno)[8]))){
			printf("Invalid rollno\n");
			return 0;
		} 
		for(j=1;j<7;j++){
			if(!isdigit((s[i].rollno)[j])){
				printf("Invalid rollno\n");
				return 0;
			}
		}
	}
	printf("\n");
	quicksrt(s,0,n-1);
	for(i=0;i<n;i++){
		printf("%s %s %d\n",s[i].rollno,s[i].name,s[i].mark);
	}
	return 0;

}