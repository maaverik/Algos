#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};


int invalid_flag = 0;
int top_index1 = 0, top_index2 = 0;


void push(struct node *stk[], struct node *x, int identity){
	if(identity == 1)
		stk[++(top_index1)] = x;
	else
		stk[++(top_index2)] = x;
}


struct node *pop(struct node *stk[], int identity){
	if(identity == 1){
		if(top_index1 == 0)
			return NULL;
		struct node *x = stk[top_index1];
		top_index1--;
		return x;
	}
	else{
		if(top_index2 == 0)
			return NULL;
		struct node *x = stk[top_index2];
		top_index2--;
		return x;
	}
}


void zigzag(struct node *x){
	struct node *stk1[1000], *stk2[1000], *temp;
	if(x != NULL){
		push(stk1, x, 1);
		while(top_index1 > 0 || top_index2 > 0){
			while(top_index1 > 0){
				temp = pop(stk1, 1);
				printf("%d ",temp->data);
				if(temp->left != NULL)
					push(stk2, temp->left, 2);
				if(temp->right != NULL)
					push(stk2, temp->right, 2);
			}
			while(top_index2 > 0){
				temp = pop(stk2, 2);
				printf("%d ",temp->data);
				if(temp->right != NULL)
					push(stk1, temp->right, 1);
				if(temp->left != NULL)
					push(stk1, temp->left, 1);
			}
		}
	}
}


struct node* create_tree(){
	char a[20], b[20], c[20];
	int i = 0;
	scanf("%s",a);
	if(strcmp(a,"(") != 0){
		printf("Invalid\n");
		invalid_flag = 1;
		return NULL;
	}
	scanf("%s",b);
	if(strcmp(b,")") == 0){
		return NULL;
	}
	char *none = NULL;
	int num = strtol(b, &none, 10);
	if(b[0] != '0' && num == 0){
		printf("Invalid\n");
		invalid_flag = 1;
		return NULL;
	}
	struct node *x = malloc(sizeof(struct node));
	x->data = num;
	x->left = create_tree();
	x->right = create_tree();
	scanf("%s",c);
	return x;
}


int main(){
	struct node *x = create_tree();
	if(invalid_flag == 0)
		zigzag(x);
	printf("\n");
	return 0;
}