#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *parent;
	struct node *left;
	struct node *right;
	int data;
};


struct node* findMin(struct node *x){
	if(x == NULL)
		return NULL;
	while(x->left != NULL){
		x = x->left;
	}
	return x;
}


struct node* findMax(struct node *x){
	if(x == NULL)
		return NULL;
	while(x->right != NULL){
		x = x->right;
	}
	return x;
}


void inorder(struct node *x){
	if(x == NULL)
		return;
	inorder(x->left);
	printf("%d ",x->data);
	inorder(x->right);
}


void preorder(struct node *x){
	if(x == NULL)
		return;

	printf("%d ",x->data);
	preorder(x->left);
	preorder(x->right);
}


void postorder(struct node *x){
	if(x == NULL)
		return;
	postorder(x->left);
	postorder(x->right);	
	printf("%d ",x->data);
}


struct node* search(struct node *x, int key){
	if(x == NULL || x->data == key)
		return x;
	if (key > x->data)
		return search(x->right, key);
	else
		return search(x->left,key);
}


struct node* successor(struct node *x, int elem){
	x = search(x, elem);
	if(x == NULL)
		return NULL;
	if(x->right != NULL)
		return findMin(x->right);
	while(x->parent != NULL && x==(x->parent)->right){
		x = x->parent;
	}
	return x->parent;
}


struct node* predecessor(struct node *x, int elem){
	x = search(x, elem);
	if(x == NULL)
		return NULL;
	if(x->left != NULL)
		return findMax(x->left);
	while(x->parent != NULL && x==(x->parent)->left){
		x = x->parent;
	}
	return x->parent;
}


struct node* insert(struct node *x, int elem){
	if(x == NULL){
		x = malloc(sizeof(struct node));
		x->left = x->right = NULL;
		x->data = elem;
	}
	else if(elem > x->data){
		x->right = insert(x->right, elem);
		x->right->parent = x;
	}
	else{
		x->left = insert(x->left,elem);
		x->left->parent = x;
	}
	return x;
}


struct node* delete(struct node *z, int elem){
	struct node *x = z;
	while(z!=NULL && elem != z->data){
		if(z->data > elem){
			z = z->left;
		}
		else{
			z = z->right;	
		}
	}
	if(z == NULL){;
		return x;
	}
	if(z->left == NULL  &&  z->right == NULL){
		if(z->parent == NULL){
			return NULL;
		}
		if(z->parent->left == z){
			z->parent->left = NULL;
			return x;
		}
		else{
			z->parent->right = NULL;
			return x;
		}
	}
	else if(z->left == NULL){
		struct node *temp = z->parent;
		if(temp == NULL){
		z->right->parent = NULL;
		x = x->right;
		return x;
		}
		if(z->parent->left == z){
			z->parent->left = z->right;
		}
		else{
			z->parent->right = z->right;
		}
		z->right->parent = temp;
		//z->data = z->right->data;
		// z->right = NULL;
		return x;


	}
	else if(z->right == NULL){
		struct node *temp = z->parent;
		if(temp == NULL){
		z->left->parent = NULL;
		x = x->right;
		return z;
		}
		if(z->parent->left == z){
			z->parent->left = z->left;
		}
		else{
			z->parent->right = z->left;
		}
		z->left->parent = temp;
		// z->data = z->left->data;
		// z->left = NULL;
		return x;
	}
	else{
		struct node *succ = successor(x, elem);
		int temp = succ->data;
		z->data = temp;
		delete(z->right, temp);
		return x; 
	}

}


int main(){
	char str[100];
	struct node* x = NULL;
	while(1){
		scanf("%s",str);

		if(strcmp(str,"stop") == 0){
			return 0;
		}
		else if(strcmp(str,"insr") == 0){
			int n;
			if(!scanf("%d",&n) || (n<0)){
				printf("Invalid input\n");
				return 0;
			}
			x = insert(x, n);
		}

		else if(strcmp(str,"srch") == 0){
			int n;
			if(!scanf("%d",&n) || (n<0)){
				printf("Invalid input\n");
				return 0;
			}
			struct node *temp = search(x, n);
			if(temp == NULL)
				printf("NOT FOUND\n");
			else
				printf("FOUND\n");
		}

		else if(strcmp(str,"minm") == 0){
			struct node *temp = findMin(x);
			if(temp == NULL)
				printf("NIL\n");
			else
				printf("%d\n",temp->data);
		}

		else if(strcmp(str,"maxm") == 0){
			struct node *temp = findMax(x);
			if(temp == NULL)
				printf("NIL\n");
			else
				printf("%d\n",temp->data);
		}

		else if(strcmp(str,"pred") == 0){
			int n;
			if(!scanf("%d",&n) || (n<0)){
				printf("Invalid input\n");
				return 0;
			}
			struct node *temp = search(x, n);
			if(temp == NULL){
				printf("NOT FOUND\n");
				continue;
			}

			temp = predecessor(x,n);
			if(temp == NULL)
				printf("NIL\n");
			else
				printf("%d\n",temp->data);	
		}

		else if(strcmp(str,"succ") == 0){
			int n;
			if(!scanf("%d",&n) || (n<0)){
				printf("Invalid input\n");
				return 0;
			}
			struct node *temp  = search(x, n);
			if(temp == NULL){
				printf("NOT FOUND\n");
				continue;
			}
			temp = successor(x,n);
			if(temp == NULL)
				printf("NIL\n");
			else
				printf("%d\n",temp->data);	
		}

		else if(strcmp(str,"delt") == 0){
			int n;
			if(!scanf("%d",&n) || (n<0)){
				printf("Invalid input\n");
				return 0;
			}
			x = delete(x, n);
		}

		else if(strcmp(str,"inor") == 0){
			inorder(x);
			printf("\n");
		}

		else if(strcmp(str,"prer") == 0){
			preorder(x);
			printf("\n");
		}

		else if(strcmp(str,"post") == 0){
			postorder(x);
			printf("\n");
		}
		
		else{
			printf("Invalid option\n");
			return 0;
		}
	}
	return 0;
} 
