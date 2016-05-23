#include<stdio.h>
#include<stdlib.h>

struct node {
	int n;
	int pr;
};

void minheapify(struct node pq[], int i){
	//printf("In minheapify\n");
	int left = 2*i, right = 2*i+1, n = pq[0].n;
	int smallest = i;
	if((left <= n) && (pq[left].pr < pq[i].pr))
	     smallest = left;
	if((right <= n) && (pq[right].pr < pq[i].pr))
	     smallest = right;
	if(smallest != i)
	{
	    struct node temp = pq[i];
		pq[i] = pq[smallest];
		pq[smallest] = temp;
	    minheapify (pq, smallest);
	} 
}

void decrease_pr(struct node pq[],int elem,int newpr){
	//printf("In decrease_pr...elem is %d\n",elem );
	int i=1, n=pq[0].n;
	while ((i <= n) && (pq[i++].n !=elem));
	i--;
	if(i > n+1)
		printf("Element not found\n");
	else if(pq[i].pr < newpr)
		printf("Invalid new priority\n");
	else{
		pq[i].pr = newpr;
		while((i>1) && (pq[i/2].pr > pq[i].pr)){
			struct node temp = pq[i];
			pq[i] = pq[i/2];
			pq[i/2] = temp;
			i = i/2;
		}
	}

}


void insert(struct node pq[],int elem,int pr){
	//printf("Inserting %d\n",elem );
	pq[0].n++;
	int n = pq[0].n;
	pq[n].n = elem;
	pq[n].pr = pr+1;
	decrease_pr(pq,elem,pr);
}


void extract_min(struct node pq[]){
	//printf("Extracting min\n");
	int n = pq[0].n;
	if(n < 1){
		printf("EMPTY\n");
	}
	else{
		int min = pq[1].n;
		int min_pr = pq[1].pr;
		pq[1] = pq[n];
		pq[0].n--;
		minheapify(pq,1);
		printf("%d (%d)\n",min,min_pr);
	}
}

void get_min(struct node pq[]){
	//printf("In get_min\n");
	int n = pq[0].n;
	if(n < 1){
		printf("EMPTY\n");
	}
	else{
		int min = pq[1].n;
		int min_pr = pq[1].pr;
		printf("%d (%d)\n",min,min_pr);
	}
}



int main(){
	int x,pr;
	char c;	
	struct node pq[801];
	pq[0].n=0;
	pq[0].pr=0;
	while (1){
		scanf("%c",&c);
		switch (c){
			case 'a':
				if (!scanf(" %d",&x) || x<0 || x>2147483648){
					printf("Invalid\n");
					return 0;
				}
				if (!scanf(" %d",&pr) || pr<1 || pr>2147483648){
					printf("Invalid\n");
					return 0;
				}
				insert(pq,x,pr);
				break;
			case 'e':
				extract_min(pq);
				break;
			case 'g':
				get_min(pq);
				break;
			case 'd':
				if (!scanf("%d",&x) || x<0 || x>2147483648){
					printf("Invalid\n");
					return 0;
				}
				if (!scanf("%d",&pr) || pr<1 || pr>2147483648){
					printf("Invalid\n");
					return 0;
				}
				decrease_pr(pq,x,pr);
				break;
			case 's':
				printf("\n");
				return 0;
			default:
				printf("Invalid input\n");
				return 0;
		} 			
		while(getchar() != '\n');
	}
	return 0;
}