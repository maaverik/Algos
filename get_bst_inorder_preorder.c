#include<stdio.h>
#include<stdlib.h>


struct node{
	struct node *left;
	struct node *right;
	int data;
};



void print_tree(struct node *x){
	if(x == NULL){
		printf("( ) ");
		return;
	}
	printf("( ");
	printf("%d ",x->data);
	print_tree(x->left);
	print_tree(x->right);
	printf(") ");
}

struct node* findtree(int preor[], int inor[], int n){
	if (n <= 0)	{
		return NULL;
	}
	int root = preor[0], n1 = 0, i = 0;
	while(inor[i++] != root){
		n1++;
		}
	//printf("n = %d n1 = %d\n",n,n1 );
	struct node *x = malloc(sizeof(struct node));
	x->data = root;
	x->left = NULL;
	x->right = NULL;
	int leftin[1000], rightin[1000], leftpre[1000], rightpre[1000];
	i = 1;
	while(i <= n1){
		leftpre[i - 1] = preor[i];
		i++;
	}
	int j = 0;
	while(i < n){
		rightpre[j] = preor[i];
		j++;
		i++;
	}
	i = 0;
	while(i < n1){
		leftin[i] = inor[i];
		i++;
	}
	j = 0;
	i++;
	while(i < n){
		rightin[j] = inor[i];
		j++;
		i++;
	}
	x->left = findtree(leftpre, leftin, n1);
	x->right = findtree(rightpre, rightin, n - n1 - 1);
	return x;
}


int main(){
	int preorder[10010], inorder[10010], n;
	if(!scanf("%d", &n) || n<=0){
		printf("Invalid size\n");
		return 0;
	}
	int i,j;
	for(i = 0; i < n; i++){
		if(!scanf("%d",&preorder[i])){
			printf("Invalid\n");
			return 0;
		}
	}
	for(i = 0; i < n; i++){
		if(!scanf("%d",&inorder[i])){
			printf("Invalid\n");
			return 0;
		}
	}
	for(i = 0;i < n;i++){
		for(j = i + 1;j < n;j++){
			if(preorder[i] == preorder[j]){
			printf("Invalid...Not unique keys\n");
			return 0;
			}
			if(inorder[i] == inorder[j]){
			printf("Invalid...Not unique keys\n");
			return 0;
			}
		}
	}
	int flag = 0;
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			if(preorder[i] == inorder[j]){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			printf("Invalid...different elements\n");
			return 0;
		}
		flag = 0;
	}
	struct node *x = findtree(preorder, inorder, n);
	print_tree(x);
	printf("\n");
	return 0;
}