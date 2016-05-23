#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct stud{
	char rollno[80];
	char name[100];
	int mark;
};

void countsrt(struct stud s[],int d,int n){
	//printf("in countsrt, d :%d , n :%d\n",d,n);
	int count[10]={0};
	int i,j,index;
	//printf("Entering 1st loop\n");
	for(i=0;i<n;i++){
		index=(s[i].rollno)[d]-'0';
		count[index]++;
	}
	//printf("Entering 2nd loop\n");
	for(i=0;i<9;i++){
		count[i+1]+=count[i];
	}
	//printf("count:\n");
	// for(i=0;i<=9;i++){
	// 	printf("%d ",count[i]);
	// }
	//printf("\n");
	struct stud temp[200];
	for(i=n-1;i>=0;i--){
		index=(s[i].rollno)[d]-'0';
		temp[count[index]-1]=s[i];
		count[index]--;
	}
	// printf("new count:\n");
	// for(i=0;i<=9;i++){
	// 	printf("%d ",count[i]);
	// }
	// printf("Entering third loop\n");
	for(i=0;i<n;i++){
		s[i]=temp[i];
	}
	//printf("Entering 4th loop\n");
	// for(i=0;i<n;i++){
	// 	printf("%s %s %d\n",s[i].rollno,s[i].name,s[i].mark);
	// }
}

void radixsrt(struct stud s[],int n){
	int i,d;
	for(i=6;i>=1;i--){
		countsrt(s,i,n);
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
	radixsrt(s,n);
	for(i=0;i<n;i++){
		printf("%s %s %d\n",s[i].rollno,s[i].name,s[i].mark);
	}
	return 0;

}