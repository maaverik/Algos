	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	
	struct stud{
		char id[50];
		char name[50];
		char mark[50];
	};

	void add( char const *file){
		FILE *outfile;
		outfile=fopen(file,"ab");
		struct stud *dummy=malloc(sizeof(struct stud));
		printf("Enter name, id and mark:	\n");
		scanf("%s%s%s",dummy->name,dummy->id,dummy->mark);
		char **none = NULL;
		if((strcmp(dummy->mark,"I")!=0) && (strcmp(dummy->mark,"A")!=0) &&(strcmp(dummy->mark,"0")!=0) && (strtol(dummy->mark,none,10)!=0) && (strtol(dummy->mark,none,10) > 100)){
			printf("Invalid marks entry......\n");
			return ;
		}
		fwrite(dummy,sizeof(struct stud),1,outfile);
		fclose(outfile);
	}

	void less_marks( char const *file){
		FILE *infile;
		infile=fopen(file,"rb");
		if(!infile){
			printf("File is empty...add something\n");
			return;
		}
		struct stud *dummy=malloc(sizeof(struct stud));
		printf("Students who got less than 30: \n");
		while(!feof(infile)){
			fread(dummy,sizeof(struct stud),1,infile);
			if(feof(infile))
				break;
			if((strcmp(dummy->mark,"A")!=0) && (strcmp(dummy->mark,"I")!=0)){
				char **none = NULL;
				int a=strtol(dummy->mark,none,10);
				if(a<30)
					printf("%s\n",dummy->name);
			}
		}
		fclose(infile);
	}


	void display( char const *file){
		FILE *infile;
		infile=fopen(file,"rb");
		if(!infile){
			printf("File is empty...add something\n");
			return;
		}
		printf("+---------------+---------------+---------+\n");
		printf("|Student_ID	|Student_Name	|mark	  |\n");
		printf("+---------------+---------------+---------+\n");
		struct stud *dummy=malloc(sizeof(struct stud));
		while(!feof(infile)){
			fread(dummy,sizeof(struct stud),1,infile);
			if(feof(infile))
				break;
			printf("|%s		|%s		|%s	  |\n",dummy->id,dummy->name,dummy->mark);
					
		}
		printf("+---------------+---------------+---------+\n");
		fclose(infile);
	}

	void less_attend( char const *file){
		FILE *infile;
		infile=fopen(file,"rb");
		if(!infile){
			printf("File is empty...add something\n");
			return;
		}
		printf("Students with insufficient attendance: \n");
		struct stud *dummy=malloc(sizeof(struct stud));
		while(!feof(infile)){
			fread(dummy,sizeof(struct stud),1,infile);
			if(feof(infile))
				break;
			if(!strcmp(dummy->mark,"I")){
				printf("%s\n",dummy->name);
			}
			
		}
		fclose(infile);
	}

	int main(int argc, char const *argv[]){
		int tmp=1;
		if(argc==1){
			printf("Enter file name while executing.....\n");
			return 0;
		}
		while (tmp){
			printf("1. Add student details\n2. Display the names of students who obtained less than 30 marks\n");
			printf("3. Display the	names of students who have insufficient attendance\n");	
			printf("4. Display all the records in the file\n5. Exit\n");	
			printf("Enter your choice: ");
			int ch;
			scanf("%d",&ch);
			while(getchar()!='\n');
			switch(ch){
				case 1: add(argv[1]); break;
				case 2: less_marks(argv[1]); break;
				case 3: less_attend(argv[1]);break;
				case 4: display(argv[1]);break;
				case 5: tmp=0;break;
				default:printf("Invalid input\nTry again\n"); break;
			}
		}
		return 0;
	}