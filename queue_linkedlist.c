#include<stdio.h>
#include<stdlib.h>

struct node {
	int n;
	struct node *next;
};

void enq(struct node **head,struct node **tail,int x){
	printf("enqing %d\n",x );
	if(*head == *tail ){
		*head = malloc(sizeof(struct node));
		(*head)->n = x;
		*tail = malloc(sizeof(struct node));
		(*head)->next = *tail;		
	}
	else{
		(*tail)->n=x;
		(*tail)->next = malloc(sizeof(struct node));
		(*tail) = (*tail)->next;
	}
}

int deq(struct node **head,struct node **tail){
	if(*head == *tail){
		return -1;
	}
	int x = (*head)->n;
	printf("deqing %d\n",x );
	*head = (*head)->next;
	return x;
}

void printq(struct node *head,struct node *tail){
	printf("Printing\n");
	while(head!= tail){
		printf("%d ",head->n);
		head = head->next;
	}	
	printf("\n");
}


int main(){
	long x;
	int tmp;
	char c;	
	struct node *head = NULL, *tail = NULL;
	while (1){
		scanf("%c",&c);
		switch (c){
			case 'e':
				if (!scanf("%ld",&x) || x<0 || x>2147483648){
					printf("Invalid\n");
					return 0;
				}
				enq(&head,&tail,x);
				break;
			case 'd':
				tmp = deq(&head,&tail);
				if(tmp>=0)
					printf("%d\n",tmp);
				else
					printf("EMPTY\n");
				break;
			case 'p':
				printq(head,tail);
				break;
			case 's':
				return 0;
			default:
				printf("Invalid input\n");
				return 0;
		}
		while(getchar() != '\n');
	}
	return 0;
}