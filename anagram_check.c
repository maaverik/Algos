#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void is_anagram(char* s1, char* s2){
	int flag,i,j,n1,n2,count;
	count=0;
	for(i=0;s1[i]!='\0';i++){
		if(s1[i]==' ')
			count++;
	}
	n1=i-count;
	count=0;
	for(i=0;s2[i]!='\0';i++){
		if(s2[i]==' ')
			count++;
	}
	
	n2=i-count;
	if(n1!=n2){
		printf("NO\n");
		return;
	}
	int checked[n1+1];
	for(i=0;i<n1+1;i++)
		checked[i]=0;
	for(i=0;s1[i]!='\0';i++){
		if(s1[i]==' ')
			continue;
		flag=0;
		for(j=0;s2[j]!='\0';j++){
			if(s2[j]==' ')
				continue;
			if((s1[i]==s2[j]) && (checked[j]==0)){
				flag=1;
				checked[j]=1;
				break;
			}
		}
		if(flag==0){
			printf("NO\n");
			return;
		}

	}
	printf("YES\n");
	return;
}

int main(){
	char s1[101000],s2[101000];
	printf("Enter str1: ");
	fgets(s1,101000,stdin);
	printf("Enter str2: ");
	fgets(s2,101000,stdin);
	int i,l1,l2;
	l1=strlen(s1);
	l2=strlen(s2);
	for(i=0;i<l1-1 && i<l2-1;i++){
		if(((s1[i]>122) || (s1[i]<97)) && (s1[i]!=' ')){
			printf("Invalid strings...\nExpected input consists of only lower case letters\n");
			return 0;
		}
		if (((s2[i]>122) || (s2[i]<97)) && (s2[i]!=' ')){
			printf("Invalid strings...\nExpected input consists of only lower case letters\n");
			return 0;
		}
		
	}
	is_anagram(s1,s2);
	return 0;
	
}