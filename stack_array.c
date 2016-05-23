#include<stdio.h>
#include<stdlib.h>

void push(long stk[],long x,int n){
	//printf("before %d ",x );
	if (stk[0] == n){
		printf("OVERFLOW\n");
		return;
	}
	stk[++stk[0]] = x;
	//printf("inserted %d \n",x );
}

long pop(long stk[],int n){
	if(stk[0] == 0)
		return -1;
	long x = stk[stk[0]];
	//printf("deleted %d \n",x );
	stk[0]--;
	return x;
}

void printstk(long stk[], int n){
	//printf("Printing:\n");
	//printf("head : %d",stk[n+1]);
	int i;
	for(i = stk[0];i > 0;i--){
		printf("%ld ",stk[i]);
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
	long stk[5010];
	char c;
	stk[0]=0;		//stk[0] is top
	while (1){
		scanf("%c",&c);
		switch(c){
			case 'a':
				if (!scanf("%ld",&x) || x<0 || x>2147483648){
				printf("Invalid\n");
				return 0;
			}
				push(stk,x,n);
				break;
			case 'r':
				tmp = pop(stk,n);
				if(tmp>=0)
					printf("%ld\n",tmp);
				else
					printf("EMPTY\n");
				break;
			case 'p':
				printstk(stk,n);
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