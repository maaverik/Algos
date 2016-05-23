#include<stdio.h>
#include<stdlib.h>

struct node{
	int n;
	struct node *next;
};

struct node* find(struct node *head,int x){
	while (head!=NULL){
		if (head->n == x)
			return head;
		head = head->next;
	}
	return NULL;
}

struct node* findprev(struct node *head,int x){
	while (head!=NULL && head->next != NULL){
		if (head->next->n == x)
			return head;
		head = head->next;
	}
	return NULL;	
}


void printll(struct node *head){
	struct node *temp=head;
	while (temp!=NULL){
		printf("%d ",temp->n);
		temp=temp->next;
	}
	printf("\n");
}



void swap (struct node **head,int x,int y){
	if (x!=y){
		struct node *elex=find(*head,x), *eley=find(*head,y);
		if((elex==NULL)){
			printf("%d not found\n",x);
			return ;
		}
		if((eley==NULL)){
			printf("%d not found\n",y);
			return ;
		}
		struct node *prevx=findprev(*head,x), *prevy=findprev(*head,y);
		
		if (prevx==NULL){
			prevy->next = elex; 
			struct node *temp = eley->next;
			eley->next = elex->next;
			elex->next = temp;
			(*head) = eley;
			return ;
		}
		if (prevy==NULL){
			prevx->next = eley;
			struct node *temp = elex->next;
			elex->next = eley->next;
			eley->next = temp;
			(*head) = elex;
			return ;
		}

		prevx->next = eley;
		prevy->next = elex;

		struct node *temp = elex->next;
		elex->next = eley->next;
		eley->next = temp;
		
		}
		printll(*head);
	return ;
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
	if(head == NULL)
		return 0;
	
	if(!scanf("%d%d",&x,&y) || (x>1073741824) || (x <-1073741824) || (y>1073741824) || (y <- 1073741824)){
		printf("Invalid input\n");
		return 0;
	}
	
	swap(&head, x, y);
	return 0;
}