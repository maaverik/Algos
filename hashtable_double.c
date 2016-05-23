#include<stdio.h>
#include<stdlib.h>

int check[10010] = {0};
int c = 0;

int aux_hash1(int x){
	if(x < 0)
		return (c - (-x % c)) % c;
	return x % c;
}


int aux_hash2(int x){
	float a = 0.6180339887;
	float prod = x * a;
	float frac = prod - (int)prod;
	return (int)((c * prod));
}


int hash(int x, int i){
	int res = (aux_hash1(x) + i*aux_hash2(x));
	if(res < 0)
		return (c - (-res % c)) % c;
	return res % c;
}


void insert(int table[], int n){
	int i = 0, k;
	while(i != c){
		k = hash(n, i);
		if(check[k] == 0){
			table[k] = n;
			check[k] = 1;
			printf("%d\n",k);
			return;
		}
		else{
			printf("%d ",k);
			i++;
		}
	}
	printf("CANNOT INSERT\n");
}


void search(int table[], int n){
	int i = 0, k = hash(n, i);
	while(i != c && check[k] != 0){
		k = hash(n, i);
		if(table[k] == n){
			printf("%d FOUND\n",k);
			return;
		}
		printf("%d ",k);
		i++;
	}
	if(i>0)
		printf("NOT FOUND\n");
	else
		printf("%d NOT FOUND\n",k);
}


int main(){
	if(!scanf("%d",&c) || c<=0 || c>2147483648){
		printf("Invalid\n");
		return 0;
	}
	int table[10010];
	int i;
	while(1){
		char ch;
		while(getchar() != '\n');
		if(!scanf("%c",&ch)){
			printf("Invalid\n");
			return 0;
		}
		int n;
		switch(ch){
			case 's':
				return 0;
			case 'i':
				if(!scanf("%d",&n)){
					printf("Invalid\n");
					return 0;
				}
				insert(table, n);
				break;
			case 'f':
				if(!scanf("%d",&n)){
					printf("Invalid\n");
					return 0;
				}
				search(table, n);
				break;
			default:
				printf("Invalid\n");
				return 0;
		}
	}
}


