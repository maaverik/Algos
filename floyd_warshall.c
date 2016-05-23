#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define INF 99999


struct adj_node{
	int label;
	float weight;
	struct adj_node *next;
};

struct adj_list{
	int vertex;
	struct adj_node *head;
};

struct adj_node* insert_edge(struct adj_node *head, int v){
	struct adj_node *temp = head;
	if(head == NULL){
		temp = malloc(sizeof(struct adj_node));
		temp->label = v;
		temp->weight = -10001;
		temp->next = NULL;
		return temp;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = malloc(sizeof(struct adj_node));
	temp->next->label = v;
	temp->next->weight = -10001;
	temp->next->next = NULL;
	return head;
}


struct adj_node* insert_weight(struct adj_node *edge, float w){
	struct adj_node *temp = edge;
	while( temp->weight > -10000  && temp != NULL ){		//initialised to -10010
		temp = temp->next;
	}
	temp->weight = w;
	return edge;
}

void floyd_war(struct adj_list graph[], int v){
	int i, j ,k;
	float dist[v][v];
	for(i = 0; i < v; i++){
		for(j = 0; j < v; j++){
			if(i != j)
				dist[i][j] = INF;
			else
				dist[i][j] = 0;
		}
	}

	struct adj_node *temp;
	for(i = 0; i < v; i++){
		temp = graph[i].head;
		while(temp != NULL){
			dist[i][temp->label] = temp->weight;
			temp = temp->next;
		}
	}

	for(k = 0; k < v; k++){
		for(i = 0; i < v; i++){
			for(j = 0; j < v; j++){
				if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	for(k = 0; k < v; k++){
		if(dist[k][k] < 0){
			printf("Invalid...negative cycle found\n" );
			return ;
		}
	}
	for(k = 0; k < v; k++){
		for(i = 0; i < v; i++){
			if(dist[k][i] == INF){
				printf("INF " );
			}
			else
				printf("%g ",dist[k][i]);
		}
		printf("\n");
	}
}

int main(){
	char ch, c, str[20];
	int n, i, num = 0, x, y, read_flag, dist[10010];
	struct adj_list graph[10010];
	int count_edges[10010];
	if(!scanf("%d",&n) || (n<=0) || (n>10000)){
		printf("Invalid input\n");
		return 0;
	}
	for(i=0;i<n;i++){
		graph[i].vertex = i;
		graph[i].head = NULL;
		count_edges[i] = 0;
	}
	getchar();		//clearing newline

	for(i=0;i<n;i++){			//read adj. nodes
		read_flag = 0;
		while(1){
			c = getchar();
			if(read_flag == 0 && c == '\n'){
				break;
			}
			read_flag = 1;
			if(c == ' ' || c == '\n'){
				if(num < 0 || num>n-1){
					printf("Invalid\n" );
					return 0;
				}
				graph[i].head = insert_edge(graph[i].head, num);
				num = 0;
				count_edges[i]++;
			}
			else{
				num = num*10 +(c - '0');
			}
			if(c == '\n'){
				break;
			}
		}
	}
	float num_;
	for(i=0;i<n;i++){			//read edge weights
		while(count_edges[i] > 0){
			if(!scanf("%f",&num_) || (num_<-10000) || (num_>10000)){
				printf("Invalid\n");
				return 0;
			}
			graph[i].head = insert_weight(graph[i].head, num_);
			count_edges[i]--;
		}
	}
	floyd_war(graph, n);
	return 0;
}
