#include<stdio.h>

float add(float a,float b){
		return a+b;
}

float sub(float a,float b){
	return a-b;
}	

float mul(float a,float b){
	return a*b;
}

float div(float a,float b){
	return a/b;
}

int main(){
	printf("Enter the numbers :");
	float a,b;
	//scanf("%f%f",&a,&b);
	if(!scanf("%f",&a) || !scanf("%f",&b)){
		printf("Invalid input\n");
		return 0;
	}
	while(1){
				printf("Menu\n");
				printf("1. Add\n2. Subtract\n3. Multiply\n4.Divide\n5. Exit\nEnter the choice: ");
				int ch;
				while(getchar()!='\n');
				scanf("%d",&ch);
				float (*fnptr)(float a,float b);
				switch(ch){
					case 1:fnptr=&add;printf("%g\n",fnptr(a,b));break;
					case 2:fnptr=&sub;printf("%g\n",fnptr(a,b));break;
					case 3:fnptr=&mul;printf("%g\n",fnptr(a,b));break;
					case 4:if(b!=0)
							{fnptr=&div;printf("%g\n",fnptr(a,b));break;}
						   else
						   	{printf("Invalid operation.....Exiting.....\n");return 0;}
					case 5:return 0;
					default:printf("Invalid choice\n");
				}
				
			}
	return 0;

}