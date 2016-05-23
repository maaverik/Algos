#include<stdio.h>

long long ones_in(long long n){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return ((n%2)+ones_in(n/2));
}

int main(){
	
	long long n;
	printf("Enter a positive decimal number: ");
	if(!scanf("%lld",&n)){
		printf("Invalid input\n");
		return 0;
	}
	
	if(n>=0 )
		printf("The binary representation of %lld contains %lld 1s\n",n,ones_in(n));
	else
		printf("Invalid input\n");
	return 0;

}
