#include<stdio.h>
#include<stdlib.h>

void enq(long q[],long x,int n){
	
	if((q[n+1] - q[0] == n-1) || (q[0] - q[n+1] == 1) )
	{
		printf("OVERFLOW\n");
		return;
	}
	//printf("before %d ",x );
	q[q[n+1]] = x;
	//printf("inserted %d \n",q[q[n+1]] );
	if (q[n+1] == n){
		q[n+1]=1;
	}
	else
		q[n+1]++;
}

long deq(long q[],int n){
	if(q[0] == q[n+1])
		return -1;
	long x = q[q[0]];
	//printf("deleted %d \n",q[q[0]] );
	if (q[0] == n)
		q[0] = 1;
	else
		q[0]++;
	return x;
}

void printq(long q[], int n){
	//printf("Printing:\n");
	//printf("head : %d tail is %d\n",q[0],q[n+1]);
	if (q[0] == q[n+1]){
		printf("EMPTY\n");
		return;
	}
	if(q[n+1] > q[0]){
		int i;
		for(i = q[0];i < q[n+1];i++){
			printf("%ld ",q[i]);
		}
	}
	else{
		int i;
		for(i = q[0]; i<=n ; i++){
			printf("%ld ",q[i]);
		}
		for(i = 1; i < q[n+1]; i++){
			printf("%ld ",q[i]);
		}
	}
	printf("\n");
}

int main(){
	int n;
	long x,tmp;
	if(!scanf("%d",&n) || (n<=0)){
		printf("Invalid size\n");
		return 0;
	}
	while(getchar() != '\n');
	long q[5010];
	q[0]=q[n+1]=1;	//q[0] is head and q[n+1] is tail
	char c;	
	while (1){
		//printf("In while\n");
		scanf("%c",&c);
		switch(c){
			case 'e':
				if (!scanf("%ld",&x) || x<0 || x>2147483648){
				printf("Invalid\n");
				return 0;
				}
				enq(q,x,n);
				break;
			case 'd':
				tmp = deq(q,n);
				if(tmp>=0)
					printf("%ld\n",tmp);
				else
					printf("EMPTY\n");
				break;
			case 'p':
				printq(q,n);
				break;
			case 's':
				printf("\n");
				return 0;
			default :
				printf("Invalid input\n");
				return 0;
		}
		while(getchar() != '\n');
	}
	return 0;
}