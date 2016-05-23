#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct adj_node{
	int label;
	int weight;
	struct adj_node *next;
};

struct adj_list{
	int vertex;
	struct adj_node *head;
};

struct q_node{
	struct q_node *next;
	struct adj_node *n;
};


char explored[10010] ;
struct q_node *head = NULL, *tail = NULL;
int dfs_flag = 0;


void enq(struct adj_node *x){
	if(head == tail ){
		head = malloc(sizeof(struct q_node));
		head->n = x;
		tail = malloc(sizeof(struct q_node));
		head->next = tail;
	}
	else{
		tail->n=x;
		tail->next = malloc(sizeof(struct q_node));
		tail = tail->next;
	}
}

struct adj_node* deq(){
	if(head == tail){
		return NULL;
	}
	struct adj_node *x = head->n;
	head = head->next;
	return x;
}


struct adj_node* insert(struct adj_node *head, int v){
	struct adj_node *temp = head;
	if(head == NULL){
		temp = malloc(sizeof(struct adj_node));
		temp->label = v;
		temp->weight = 0;
		temp->next = NULL;
		return temp;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = malloc(sizeof(struct adj_node));
	temp->next->label = v;
	temp->next->weight = 0;
	temp->next->next = NULL;
	return head;
}


void set_unexplored(int n){
	int i;
	for(i=0;i<n;i++){
		explored[i] = 'n';
	}
}



void bfs(struct adj_list graph[], int start, int key){
	printf("%d ",start);
	enq(graph[start].head);
	explored[start] = 'y';
	struct adj_node *temp = graph[start].head;
	while(head != tail ){
		temp = deq();
		while(temp != NULL){
			if(explored[temp->label] == 'n'){
				printf("%d ",temp->label);
				if(temp->label == key){
					return;
				}
				enq(graph[temp->label].head);
				explored[temp->label] = 'y';
			}
			temp = temp->next;
		}
	}
}


void dfs(struct adj_list graph[], int start, int key){
	if(dfs_flag == 1){
		return;
	}
	printf("%d ",start);
	explored[start] = 'y';
	if(start == key){
		dfs_flag = 1;
		return;
	}
	struct adj_node *temp = graph[start].head;
	while(temp != NULL){
		if(explored[temp->label] == 'n'){
			dfs(graph, temp->label, key);
		}
		temp = temp->next;
	}
}



int main(){
	char ch, c, str[20];
	int n, i, num = 0, start, key, read_flag;
	struct adj_list graph[10010];
	if(!scanf("%d",&n) || (n<=0) || (n>10000)){
		printf("Invalid input\n");
		return 0;
	}
	for(i=0;i<n;i++){
		graph[i].vertex = i;
		graph[i].head = NULL;
	}
	getchar();		//clearing newline
	set_unexplored(n);

	for(i=0;i<n;i++){
		read_flag = 0;
		while(1){
			c = getchar();
			if(read_flag == 0 && c == '\n'){
				break;
			}
			read_flag = 1;
			if(c == ' ' || c == '\n'){
				if(num < 0 || num >= n){
					printf("Invalid\n");
					return 0;
				}
				graph[i].head = insert(graph[i].head, num);
				num = 0;
			}
			else{
				num = num*10 +(c - '0');
			}
			if(c == '\n'){
				break;
			}
		}
	}

	while(1){
		scanf("%s",str);
		if(strcmp(str,"bfs") == 0){
			if(!scanf("%d%d",&start,&key)){
				printf("Invalid\n");
				return 0;
			}
			if(start<0 || start>n-1){
				printf("Invalid\n");
				return 0;
			}
			if(key<0 || key>n-1){
				printf("Invalid\n");
				return 0;
			}
			bfs(graph, start, key);
			printf("\n");
			set_unexplored(n);
		}
		else if(strcmp(str,"dfs") == 0){
			if(!scanf("%d%d",&start,&key)){
				printf("Invalid\n");
				return 0;
			}
			if(start<0 || start>n-1){
				printf("Invalid\n");
				return 0;
			}
			if(key<0 || key>n-1){
				printf("Invalid\n");
				return 0;
			}
			dfs_flag = 0;
			dfs(graph, start, key);
			printf("\n");
			set_unexplored(n);
		}
		else if(strcmp(str,"stp") == 0){
			return 0;
		}
		else{
			printf("Invalid input\n");
			return 0;
		}
	}

	return 0;
}
