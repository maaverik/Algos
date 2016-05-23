#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INF 99999


struct adj_node{
	int label;
	int weight;
	struct adj_node *next;
};

struct adj_list{
	int vertex;
	struct adj_node *head;
};


struct minheap_node{		//holds unproocessed vertices
	int v;			//label
	float dist;			//weight
};


struct adj_node* insert_edge(struct adj_node *head, int v){
	struct adj_node *temp = head;
	if(head == NULL){
		temp = malloc(sizeof(struct adj_node));
		temp->label = v;
		temp->weight = -1;
		temp->next = NULL;
		return temp;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = malloc(sizeof(struct adj_node));
	temp->next->label = v;
	temp->next->weight = -1;
	temp->next->next = NULL;
	return head;
}


struct adj_node* insert_weight(struct adj_node *edge, float w){
	struct adj_node *temp = edge;
	while(temp->weight > 0 && temp != NULL){		//initialised to -1
		temp = temp->next;
	}
	temp->weight = w;
	return edge;
}


void minheapify(struct minheap_node mh[], int i){
	//printf("In minheapify\n");
	int left = 2*i, right = 2*i+1, n = mh[0].v;
	int smallest = i;
	if((left <= n) && (mh[left].dist < mh[i].dist))
	     smallest = left;
	if((right <= n) && (mh[right].dist < mh[i].dist))
	     smallest = right;
	if(smallest != i)	{
	   struct minheap_node temp = mh[i];
		mh[i] = mh[smallest];
		mh[smallest] = temp;
	   minheapify (mh, smallest);
	}
}

void decrease_dist(struct minheap_node mh[],int elem,float newdist){
	//printf("In decrease_dist...elem is %d\n",elem );
	int i=1, n=mh[0].v;
	while ((i <= n) && (mh[i++].v !=elem));
	i--;
	mh[i].dist = newdist;
	while((i>1) && (mh[i/2].dist > mh[i].dist)){
		struct minheap_node temp = mh[i];
		mh[i] = mh[i/2];
		mh[i/2] = temp;
		i = i/2;
	}
}


struct minheap_node extract_min(struct minheap_node mh[]){
	int n = mh[0].v;
	if(n < 1){
		printf("EMPTY\n");
	}
	else{
		int min = mh[1].v;
		int min_dist = mh[1].dist;
		mh[1] = mh[n];
		mh[0].v--;
		minheapify(mh,1);
		struct minheap_node temp;
		temp.v = min;
		temp.dist = min_dist;
		return temp;
	}
}


void dijkstra(struct adj_list graph[], int src, int v, float dist[]){
	char in_mh[v+2];
	struct minheap_node mh[v+2];
	int i;
	mh[0].dist = -1;	//never used
	mh[0].v = v;		//global size of minheap
	for(i = 1 ;i <= v; i++){
		mh[i].v = i - 1;
		mh[i].dist = INF;
		dist[i - 1] = INF;
		in_mh[i-1] = 'y';
	}
	mh[src+1].dist = 0;
	dist[src] = 0;
	for(i=mh[0].v/2;i>=1;i--){ 	//To build the heap
		maxheapify(mh,i);
	}
	while(mh[0].v > 0){
		// for(i=1;i<mh[0].v;i++){
		// 	printf("dist[%d] : %g ",mh[i].v,mh[i].dist );
		// }
		//printf("\n" );
		struct minheap_node min = extract_min(mh);
		int curr_min = min.v;
		//printf("Curr_min: %d\n",curr_min );
		in_mh[curr_min] = 'n';
		struct adj_node *edge = graph[curr_min].head;
		while(edge != NULL){
			float alt_dist = edge->weight + dist[curr_min];
			if(in_mh[edge->label] == 'y'  && (dist[edge->label] > alt_dist)){
				decrease_dist(mh, edge->label  ,alt_dist);
				dist[edge->label] = alt_dist;
			}
			edge = edge->next;
		}
	}
}



int main(){
	char ch, c, str[20];
	int n, i, num = 0, x, y, read_flag;
	float dist[10010];
	struct adj_list graph[1010];
	int count_edges[10010];
	if(!scanf("%d",&n) || (n<=0) || (n>1000)){
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
				if(num<0 || num>n-1){
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
			if(!scanf("%f",&num_) || num_<0 || num_>10000){
				printf("Invalid\n");
				return 0;
			}
			graph[i].head = insert_weight(graph[i].head, num_);
			count_edges[i]--;
		}
	}
	while(1){
		scanf("%s",str);
		if(strcmp(str,"apsp") == 0){
			if(!scanf("%d",&x ) || (x<0) || (x>=n)){
				printf("Invalid\n");
				return 0;
			}
			dijkstra(graph, x, n, dist);
			for(i = 0; i < n; i++){
				if(dist[i] != INF)
					printf("%g ",dist[i]);
				else
					printf("INF " );
			}
			printf("\n" );
		}
		else if(strcmp(str,"sssp") == 0){
			if(!scanf("%d",&x ) || (x<0) || (x>=n)){
				printf("Invalid\n");
				return 0;
			}
			if(!scanf("%d",&y ) || (y<0) || (y>=n)){
				printf("Invalid\n");
				return 0;
			}
			dijkstra(graph, x, n, dist);
			if(dist[y] != INF)
				printf("%g ",dist[y]);
			else
				printf("UNREACHABLE" );
			printf("\n" );
		}

		else if(strcmp(str,"stop") == 0){
			return 0;
		}
		else{
			printf("Invalid input\n");
			return 0;
		}
	}
	return 0;
}
