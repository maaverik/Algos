#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *left;
	struct node *right;
	char data;
};



void inorder(struct node *x){
	if(x == NULL)
		return;
	if(x->right != NULL && x->left != NULL){
			printf("(");
		}
	inorder(x->left);
	printf("%c",x->data);
	inorder(x->right);
	if(x->right != NULL && x->left != NULL)
		printf(")");
}


void preorder(struct node *x){
	if(x == NULL)
		return;

	printf("%c",x->data);
	preorder(x->left);
	preorder(x->right);

}


void postorder(struct node *x){
	if(x == NULL)
		return;
	postorder(x->left);
	postorder(x->right);	
	printf("%c",x->data);
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
	inorder(x);
	printf("\nPreorder: ");
	preorder(x);
	printf("\nPostorder: ");
	postorder(x);
	printf("\n");
	return 0;
} 
