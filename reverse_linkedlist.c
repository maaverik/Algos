#include<stdio.h>
#include<stdlib.h>

struct node{
	int n;
	struct node *next;
};


void printll(struct node *head){
	struct node *temp=head;
	while (temp!=NULL){
		printf("%d ",temp->n);
		temp=temp->next;
	}
	printf("\n");
}


struct node* reverse(struct node **head){
	struct node *temp = *head;
	struct node *prev = NULL;
	struct node *next;
	while (temp != NULL && temp->next != NULL){
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	temp->next = prev;
	*head = temp;
	return *head;
}


struct node* insertll(int num){
	int i=num,x;
	//printf("Enter elements\n");
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
	int n,x,y;
	if (!scanf("%d",&n) || (n<=0)){
		printf("Invalid size\n");
		return 0;
	}
	struct node *head = insertll(n);
	head = reverse(&head);
	printll(head);
	return 0;
}