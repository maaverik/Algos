#include<stdio.h>
#include<stdlib.h>


struct node{
	int elem;
	int rank;
	struct node *parent;
};


struct node *ptr_array[10001] = {NULL};
int count = 0;


void makeset(int x){
	struct node *temp = malloc(sizeof(struct node));
	temp->parent = temp;
	temp->rank = 0;
	temp->elem = x;
	ptr_array[x] = temp;
}

struct node* findset(struct node *x){
	count++;
	if(x != x->parent){
		x->parent = findset(x->parent);
	}
	return x->parent;
}

struct node* unionset(struct node *x, struct node *y){
	if (x->rank > y->rank){
		y->parent = x;
		return x;
	}
	else if(x->rank == y->rank){
		y->parent = x;
		(x->rank)++;
		return x;
	}
	else{
		x->parent = y;
		return y;
	}
}


int main(){
	char ch;
	int x, y;
	int i = 0;
	struct node *temp1, *temp2;
	while(1){

		scanf(" %c",&ch);
		switch(ch){

			case 'm':
					if(!scanf("%d",&x) || (x<0) || (x>10000)){
						printf("Invalid\n");
						return 0;
					}
					if(ptr_array[x] == NULL){
						makeset(x);
						printf("%d\n",x);
					}
					else{
						printf("PRESENT\n");	
					}
					break;
			case 'f':
					if(!scanf("%d",&x) || (x<0) || (x>10000)){
						printf("Invalid\n");
						return 0;
					}
					if(ptr_array[x] == NULL){
						printf("NOT FOUND\n");
					}
					else{
						printf("%d\n",findset(ptr_array[x])->elem);
					}
					break;
			case 'u':
					if(!scanf("%d",&x) || (x<0) || (x>10000)){
						printf("Invalid\n");
						return 0;
					}
					if(!scanf("%d",&y) || (y<0) || (y>10000)){
						printf("Invalid\n");
						return 0;
					}
					if(ptr_array[x] == NULL  ||  ptr_array[y] == NULL){
						printf("ERROR\n");
					}
					temp1 = findset(ptr_array[x]);
					temp2 = findset(ptr_array[y]);
					if(temp1 == temp2){
						printf("%d\n",temp1->elem);
					}
					else{
						printf("%d\n", unionset(temp1,temp2)->elem);			//passing representatives
					}
					break;
			case 's':
					printf("%d\n",count);
					return 0;
			default:
					printf("Invalid input\n");
					return 0;
		}
	}
	return 0;
}