#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *left;
	struct node *right;
	char data;
};


int top_index = 0;


void push(struct node *stk[],struct node *x){
	stk[++(top_index)] = x;
}


struct node *pop(struct node *stk[]){
	if(top_index == 0)
		return NULL;
	struct node *x = stk[top_index];
	top_index--;
	return x;
}


int isoperator(char a){
	switch(a){
		case '+':
		case '-':
		case '/':
		case '*':
		case '^':
				return 1;
		default: 
				return 0;
	}
}


void inorder(struct node *x, struct node *stk[]){
	top_index = 0;
	if(x == NULL)
		return;
	push(stk, x);
	while(top_index > 0){
		x = pop(stk);
		if(x->right == NULL && x->left == NULL){
			printf("%c",x->data);
		}
		else{
			struct node *temp1 = malloc(sizeof(struct node));
			temp1->data = ')';
			temp1->left = NULL;
			temp1->right = NULL;
			push(stk, temp1);
			if(x->right != NULL){
				push(stk, x->right);
				//x = x->right;
			}
			struct node *temp2 = malloc(sizeof(struct node));
			temp2->data = x->data;
			temp2->right = NULL;
			temp2->left = NULL;
			push(stk, temp2);
			if(x->left != NULL){
				push(stk, x->left);
				//x = x->left;
				struct node *temp1 = malloc(sizeof(struct node));
				temp1->data = '(';
				temp1->left = NULL;
				temp1->right = NULL;
				push(stk, temp1);
			}
		}
	}
}


void preorder(struct node *x, struct node *stk[]){
	top_index = 0;
	while(top_index > 0 || x != NULL){
		if(x != NULL){
			printf("%c",x->data);
			if(x->right != NULL){
				push(stk, x->right);
			}
			x = x->left;
		}
		else{
			x = pop(stk);
		}	
	}
}


void postorder(struct node *x, struct node *stk[]	){
	top_index = 0;
	struct node *y = NULL;
	struct node *prev = NULL;
	while(top_index > 0 || x != NULL){
		if(x != NULL){
				push(stk, x);	//push root
				x = x->left;	//move left first
		}
		else{
			y = pop(stk);		//leaf reached
			push(stk, y);		//so peeking
			if(y->right != NULL && prev != y->right){
				x = y->right;
			}
			else{
				printf("%c",y->data);
				prev = pop(stk);
			}
		}
	}
}


struct node* insert(char elem[]){
	static int i =0;
	//printf("elem[i]: %c i: %d\n",elem[i],i );
	if(elem[i] == '\0'){
		return NULL;
	}
	else if(isoperator(elem[i])){
		struct node *x = malloc(sizeof(struct node));
		x->data = elem[i];
		i++;
		x->left = insert(elem);
		i++;
		x->right = insert(elem);
		return x;
	}
	else{
		struct node *x = malloc(sizeof(struct node));
		x->data = elem[i];
		x->left = NULL;
		x->right = NULL;
		return x;
	}
}



int main(){
	char str[10010];
	struct node *stk[1000];
	scanf("%s", str);
	int i;
	while(str[i]!='\0'){
		if((str[i] <= 'a') && (str[i] >= 'z') && !isoperator(str[i])){
			printf("Invalid input\n");
			return 0;
		}
		i++;
	}
	struct node * x = insert(str);
	printf("Inorder: ");
	inorder(x, stk);
	printf("\nPreorder: ");
	preorder(x, stk);
	printf("\nPostorder: ");
	postorder(x, stk);
	printf("\n");
	return 0;
} 
