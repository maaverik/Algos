#include<stdio.h>
#include<stdlib.h>

struct node {
	int n;
	struct node *next;
};

void push(struct node **top,int x){
	//printf("Pushing %d\n",x );
	if(*top == NULL){
		*top = malloc(sizeof(struct node));
		(*top)->next = NULL;
		(*top)->n = x;
	}
	else{
		struct node *temp = malloc(sizeof(struct node));
		temp->n=x;
		temp->next=(*top);
		(*top)=temp;
	}
}

int pop(struct node **top){
	if(*top == NULL){
		return -1;
	}
	int x = (*top)->n;
	//printf("Popping %d\n",x );
	*top = (*top)->next;
	return x;
}

void printstk(struct node **top){
	//xprintf("Printing\n");
	struct node *temp = *top;
	while(temp != NULL){
		printf("%d ",temp->n);
		temp = temp->next;
	}	
	printf("\n");
}


int main(){
	long x;
	int tmp;
	char c;	
	struct node *top=NULL;
	while (1){
		scanf("%c",&c);
		switch (c){
			case 'a':
				if (!scanf("%ld",&x) || x<0 || x>2147483648){
					printf("Invalid\n");
					return 0;
				}
				push(&top,x);
				break;
			case 'r':
				tmp = pop(&top);
				if(tmp>=0)
					printf("%d\n",tmp);
				else
					printf("EMPTY\n");
				break;
			case 'p':
				printstk(&top);
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