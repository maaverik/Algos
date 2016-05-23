#include<stdio.h>
#include<stdlib.h>

struct node{
	char data;
	struct node *left;
	struct node *right;
	struct node *parent;
};


int top_index = 0;

struct node* rightmost(struct node *x, struct node *curr){
	if(x == NULL)
		return NULL;
	while(x->right != NULL  && x->right != curr){
		x = x->right;
	}
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


void inorder(struct node *x){
	char coming_from = 't';
	while(x != NULL){
		if(coming_from == 't'){
			if(isoperator(x->data))
				printf("(");
			if(x->left == NULL){
				printf("%c",x->data);
				if(x->right == NULL){					
					if(x->parent == NULL)
						break;
					if(x == x->parent->left)
						coming_from = 'l';
					else
						coming_from = 'r';
					x = x->parent;
				}
				else
					x = x->right;		
			}
			else
				x = x->left;
		}
		else if(coming_from == 'l'){
			//printf("2\n");
			printf("%c",x->data);
			if(x->right == NULL){
				if(x->parent == NULL)
					break;
				if(x == x->parent->left)
					coming_from = 'l';
				else
					coming_from = 'r';
				x = x->parent;
			}
			else{
				coming_from = 't';
				x = x->right;
			}			
		}
		else if(coming_from == 'r'){
			//printf("3\n");
			printf(")");
			if(x->parent == NULL)
				break;
			if(x == x->parent->left)
				coming_from = 'l';
			else
				coming_from = 'r';
			x = x->parent;
		}
	}
}


void preorder(struct node *x){
	struct node *temp = NULL;
	while(x != NULL){
		if(x->left == NULL){
			printf("%c",x->data);
			x = x->right;
		}
		else{
			temp = rightmost(x->left, x);
			if(temp->right ==  x){
				temp->right = NULL;
				x = x->right;
			}
			else{
				printf("%c",x->data);
				temp->right = x;
				x = x->left;
			}
		}
	}
}



void postorder(struct node *x){
	char coming_from = 't';
	while(x != NULL){
		if(coming_from == 't'){
			//printf("1\n");
			if(x->left == NULL){
				if(x->right == NULL){
					printf("%c",x->data);
					if(x->parent == NULL)
						break;
					if(x == x->parent->left)
						coming_from = 'l';
					else
						coming_from = 'r';
					x = x->parent;
				}
				else
					x = x->right;		
			}
			else
				x = x->left;
		}
		else if(coming_from == 'l'){
			//printf("2\n");
			if(x->right == NULL){
				printf("%c",x->data);
				if(x->parent == NULL)
					break;
				if(x == x->parent->left)
					coming_from = 'l';
				else
					coming_from = 'r';
				x = x->parent;
			}
			else{
				coming_from = 't';
				x = x->right;
			}
		}
		else if(coming_from == 'r'){
			//printf("3\n");
			printf("%c",x->data);
			if(x->parent == NULL)
				break;
			if(x == x->parent->left)
				coming_from = 'l';
			else
				coming_from = 'r';
			x = x->parent;
		}
	}
}




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


int validcheck(struct node *x){
	if(x == NULL)
		return 0;
	if(isoperator(x->data) && ((x->left == NULL) || (x->right == NULL))){
		return 0;
	}
	else if(!isoperator(x->data) && ((x->left != NULL) || (x->right != NULL))){
		return 0;
	}
	return validcheck(x->left) + validcheck(x->right);
}


struct node* insert(char elem[]){
	int i =0;
	//printf("elem[i]: %c i: %d\n",elem[i],i );
	struct node *stk[1000];
	while(elem[i] != '\0'){
		if(isoperator(elem[i])){
			struct node *x = malloc(sizeof(struct node));
			struct node *y = malloc(sizeof(struct node));
			struct node *temp = malloc(sizeof(struct node));
			x = pop(stk);
			y = pop(stk);
			temp->data = elem[i];
			temp->right = x;
			if(temp->right != NULL)
				temp->right->parent = temp;
			temp->left = y;
			if(temp->left != NULL)
				temp->left->parent = temp;
			push(stk, temp);
		}
		else{
			struct node *x = malloc(sizeof(struct node));
			x->data = elem[i];
			x->left = NULL;
			x->right = NULL;
			x->parent = NULL;
			push(stk, x);
		}
		i++;
	}
	struct node *x = malloc(sizeof(struct node));
	x = pop(stk);
	return x;
}


int main(){
	char str[10010];
	scanf("%s", str);
	int i;
	while(str[i]!='\0'){
		if(((str[i] < 'a') || (str[i] > 'z')) && !isoperator(str[i])){
			printf("Invalid input\n");
			return 0;
		}
		i++;
	}
	struct node * x = insert(str);
	if(validcheck(x) > 0 || top_index>0){
		printf("Invalid expression\n");
		return 0;
	}
	printf("Inorder: ");
	inorder(x);
	printf("\nPreorder: ");
	preorder(x);
	printf("\nPostorder: ");
	postorder(x);
	printf("\n");
	return 0;
} 
