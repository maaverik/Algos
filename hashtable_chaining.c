#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};


int hash(int x, int c){
	if(x < 0)
		return (c - (-x % c)) % c;
	return x % c;
}


void push(struct node **top, int x){
	if(*top == NULL){
		*top = malloc(sizeof(struct node));
		(*top)->next = NULL;
		(*top)->data = x;
	}
	else{
		struct node *temp = malloc(sizeof(struct node));
		temp->data=x;
		temp->next=(*top);
		(*top)=temp;
	}
}


void insert(struct node *table[], int n, int c){
	int k = hash(n, c);
	push(&table[k], n);
	printf("%d\n",k);
}

void search(struct node *table[], int n, int c){
	int k = hash(n, c);
	struct node *temp = table[k];
	while(temp != NULL && temp->data != n){
		temp = temp->next;
	}
	if(temp == NULL)
		printf("%d NOT FOUND\n",k);
	else
		printf("%d FOUND\n",k);
}


int main(){
	int c;
	//struct node *table[100000];
	if(!scanf("%d",&c) || c<=0 || c>2147483648){
		printf("Invalid\n");
		return 0;
	}
	struct node **table = malloc(c * sizeof(struct node));
	int i;
	for(i = 0; i < c; i++){
		table[i] = malloc(sizeof(struct node));
	}
	while(1){
		char ch;
		while(getchar() != '\n');
		if(!scanf("%c",&ch)){
			printf("Invalid\n");
			return 0;
		}
		int n;
		switch(ch){
			case 's':
				return 0;
			case 'i':
				if(!scanf("%d",&n)){
					printf("Invalid\n");
					return 0;
				}
				insert(table, n, c);
				break;
			case 'f':
				if(!scanf("%d",&n)){
					printf("Invalid\n");
					return 0;
				}
				search(table, n, c);
				break;
			default:
				printf("Invalid\n");
				return 0;
		}
	}
}


