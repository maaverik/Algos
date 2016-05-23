#include<stdio.h>
#include<stdlib.h>

struct node
{
	int n;
	struct node *next;
};

struct node* push(struct node **head, int num){
	struct node *temp = malloc(sizeof(struct node));
	temp->n = num;
	temp->next = *head;
	*head = temp;
}

void printll(struct node *head){
	struct node *temp=head;
	while (temp!=NULL){
		printf("%d",temp->n);
		temp=temp->next;
	}
	printf("\n");
}

int sum_of_digits(struct node **head1, struct node *head2, int identify){
	if((*head1)->next == NULL){
		(*head1)->n += head2->n;
		int dig = ((*head1)->n)/10;
		if(dig > 0){
			(*head1)->n %= 10;
		}
		return dig;
	}
	int carry = sum_of_digits(&(*head1)->next, head2->next, 0);
	(*head1)->n += head2->n + carry;
	int dig = ((*head1)->n)/10;
	if(dig > 0){
		(*head1)->n %= 10;
	}
	if (identify == 1){
		struct node *temp = malloc(sizeof(struct node));
		temp->n = dig;
		temp->next = *head1;
		(*head1) = temp;
	}
	return dig;
}


int main(){
	int n;
	if(!scanf("%d",&n) || (n<=0) || (n>10000)){
	printf("Invalid size\n");
	return 0;
	}
	struct node *head1 = NULL, *head2 = NULL;
	int x,y;
	if(!scanf("%d%d",&x,&y) || (x<=0) || (y<=0)){
	printf("Invalid input\n");
	return 0;
	}
	int count = n;
	while (x>0 && y>0){
		int d1 = x%10;
		int d2 = y%10;
		x /= 10;
		y /= 10;
		push(&head1, d1);
		push(&head2, d2);
		count--;
	}
	if (x>0 || y>0 || count>0){
		printf("Invalid inputs\n");
		return 0;
	}
	sum_of_digits(&head1, head2, 1);
	printll(head1);
	return 0;
}