#include<stdio.h>
#include<stdlib.h>

struct node{
	int n;
	struct node *next;
};


int k_last(struct node *head, int k){
	struct node *temp=head;
	int i=0,n=0;
	while (temp!= NULL){
		n++;
		temp=temp->next;
	}
	temp=head;
	while (temp!=NULL && (i++ != n-k)){
		temp=temp->next;
	}
	return temp->n;
}



struct node* insertll(int num){
	int i=num,x;
	printf("Enter elements\n");
	if(!scanf("%d",&x) || (x>1073741824) || (x<-1073741824)){
			printf("Invalid input\n");
			return NULL;
	}
	i--;
	struct node *head=malloc(sizeof(struct node));
	head->n=x;
	head->next=NULL;
	struct node *last=head;
	while(i--){
		if(!scanf("%d",&x) || (x>1073741824) || (x<-1073741824)){
			printf("Invalid input\n");
			return NULL;
		}
		last->next=malloc(sizeof(struct node));
		last=last->next;
		last->next=NULL;
		last->n=x;		
	}
	return head;
}

int main(){
	int n;
	if (!scanf("%d",&n) || (n<=0)){
		printf("Invalid size\n");
		return 0;
	}
	struct node *head = insertll(n);
	if(head == NULL)
		return 0;
	int k;
	printf("Enter k\n");
	if (!scanf("%d",&k)){
		printf("Invalid input \n");
		return 0;
	}
	if(k<=0){
		printf("Invalid input : %d < 0\n",k);
		return 0;
	}
	if(k>n){
		printf("Invalid input : %d > %d\n",k,n);
		return 0;
	}
	printf("%d\n",k_last(head,k));
	return 0;
}