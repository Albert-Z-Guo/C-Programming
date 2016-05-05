#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

//define a grid globally
int grid[30][30];

void MakeGrid(){
int e;
int f;
for (e = 0; e < 30; e++) {
	for (f = 0; f < 30; f++) {
        grid [e][f] = rand() % 9 + 1;
	};
}
//random seed
	srand(time(NULL));

int i;
int j;
int length = 30;
for(i=0; i<length; i++){
	for(j=0; j<length; j++){
		printf("%d",grid[i][j]);
	}
	printf("\n");
}
printf("\nA 30X30 Puzzle is made.\n");
}

void PrintGrid(){
int i;
int j;
int length = 30;
for(i=0; i<length; i++){
	for(j=0; j<length; j++){
		printf("%d ",grid[i][j]);
	}
	printf("\n");
}
printf("\nA Aesthetically-pleasing 30X30 Puzzle is made.\n");
}

void Reverse(){
int i;
int j;
for(j=0; j<30; j++){
	for(i=0; i < 15; i++){
	int a;
	a = grid[j][i];
	grid[j][i] = grid[j][29-i];
	grid[j][29-i] = a;
	}
	/*//printing one row
	for(i=0; i<30; i++){
		printf("%d ",grid[j][i]);
	}
	printf("\n");*/
}
printf("\nPuzzle reversal has been completed.\nYou can issue (D) Display command to see it.");
}

void Find(){
int target;
int thousand;
int hundred;
int ten;
int digit;
	printf("Find which number (10-9999)?\n");
	while(1){
		scanf("%d",&target);
		if(target>=1000 && target <10000){
int thousand = target/1000;
int hundred = (target- 1000*(int) thousand)/100;
int ten = (target - 1000*(int) thousand - 100*(int) hundred)/10;
int digit = (target - 1000*(int) thousand - 100*(int) hundred - 10*(int) ten);
	int j;
	int i;
	int x;
	int y;
	int n;
	int m;
	int flag;
	int times=0;
	int columnnumber_pre;
	int columnnumber_post;
	int counter_pre[15];
	int counter_post[15];
	for(j=0; j<30; j++){
	//resetting flag to 0
	flag = 0;
		for(i=0; i < 27; i++){
			if((grid[j][i]==thousand) && (grid[j][i+1]==hundred) && (grid[j][i+2]==ten) && (grid[j][i+3]==digit)){
				
				// storing the address of the first digit of the found result into counter_pre[n]
				counter_pre[0] = i;
				
				// storing the address of the last digit of the found result into counter_post[n]
				counter_post[0] = i+3;
		
				//replacing the elements before the first digit of the first result to '*'
				for(n=i-1; n > -1; n--){
					grid[j][n]= 0;
				}
				flag=1;
			}else{grid[j][i]=0;}
			if(flag==1) break;
		}
		
		if(flag==0){
			grid[j][29]=0;
			grid[j][28]=0;
			grid[j][27]=0;
		}
		
		if(flag==1){
			//searching the next result after the first one
			m=0;
			for (x = (counter_post[m]+1); x < 27; x++){
				if ((grid[j][x]==thousand) && (grid[j][x+1]==hundred) && (grid[j][x+2]==ten) && (grid[j][x+3]==digit)){
					m++;//counter update
					counter_pre[m] = x;
					counter_post[m] = x+3;
					if((counter_pre[m]-1)>counter_post[m-1]){
						//replacing all the elements before the next result to '*' until the last digit(counter_post) of the previous result
						for (columnnumber_pre = counter_pre[m]-1; columnnumber_pre > counter_post[m-1]; columnnumber_pre--){
								grid[j][columnnumber_pre]= 0;
						}
					}
				}
			}
			if(counter_post[m]!= 29){	
				for(y = counter_post[m]+1; y<30; y++){
					grid[j][y]=0;
				}
			}
		}	
		
		if(flag==1)
			times += (m+1);
			
	}
	//printing the grid	
	//char charactergrid[30][30];
	int length = 30;
	for(j=0; j<length; j++){
		for(i=0; i<length; i++){
			if(grid[j][i]==0)
				printf("* ");
			else
				printf("%d ",grid[j][i]);
		}
		printf("\n");
	}
	printf("%d%d%d%d occurs %d times.\n", (int) thousand, (int) hundred, (int) ten, (int) digit, times);
	break;
}
		if(target>=100 && target<1000){
int hundred = (target)/100;
int ten = (target - 100 * (int) hundred)/10;
int digit = (target - 100 * ((int) hundred) - 10 * ((int) ten));
	int j;
	int i;
	int x;
	int y;
	int n;
	int m;
	int flag;
	int times=0;
	int columnnumber_pre;
	int columnnumber_post;
	int counter_pre[15];
	int counter_post[15];
	for(j=0; j<30; j++){
	//resetting flag to 0
	flag = 0;
		for(i=0; i < 28; i++){
			if((grid[j][i]==hundred) && (grid[j][i+1]==ten) && (grid[j][i+2]==digit)){
				
				// storing the address of the first digit of the found result into counter_pre[n]
				counter_pre[0] = i;
				
				// storing the address of the last digit of the found result into counter_post[n]
				counter_post[0] = i+2;
		
				//replacing the elements before the first digit of the first result to '*'
				for(n=i-1; n > -1; n--){
					grid[j][n]= 0;
				}
				flag=1;
			}else{grid[j][i]=0;} // if there is no result in the entire row, replacing every element in one row to 0
			if(flag==1) break;
		}
		
		if(flag==0){
			grid[j][29]=0;
			grid[j][28]=0;
		}
	
		if(flag==1){
			//searching the next result after the first one
			m=0;
			for (x = (counter_post[m]+1); x < 28; x++){
				if ((grid[j][x]==hundred) && (grid[j][x+1]==ten) && (grid[j][x+2]==digit)){
					m++;//counter update
					counter_pre[m] = x;
					counter_post[m] = x+2;
					if((counter_pre[m]-1)>counter_post[m-1]){
						//replacing all the elements before the next result to '*' until the last digit(counter_post) of the previous result
						for (columnnumber_pre = counter_pre[m]-1; columnnumber_pre > counter_post[m-1]; columnnumber_pre--){
								grid[j][columnnumber_pre]= 0;
						}
					}
				}
			}
			//if there is no further result, replacing all the elements after the last digit of the first result to 0
			if(counter_post[m]!= 29){	
				for(y = counter_post[m]+1; y<30; y++){
					grid[j][y]=0;
				}
			}
		}		
		if(flag==1)
			times += (m+1);
			
	}
	//printing the grid	
	//char charactergrid[30][30];
	int length = 30;
	for(j=0; j<length; j++){
		for(i=0; i<length; i++){
			if(grid[j][i]==0)
				printf("* ");
			else
				printf("%d ",grid[j][i]);
		}
		printf("\n");
	}
	printf("%d%d%d occurs %d times.\n", (int) hundred, (int) ten, (int) digit, times);
	break;
}
		if(target>=10 && target<100){
int ten = (target)/10;
int digit = (target - 10* (int) ten);
	int j;
	int i;
	int x;
	int y;
	int n;
	int m;
	int flag;
	int times=0;
	int columnnumber_pre;
	int columnnumber_post;
	int counter_pre[15];
	int counter_post[15];
	for(j=0; j<30; j++){
	//resetting flag to 0
	flag = 0;
		for(i=0; i < 29; i++){
			if((grid[j][i]==ten) && (grid[j][i+1]==digit)){
				
				// storing the address of the first digit of the found result into counter_pre[n]
				counter_pre[0] = i;
				
				// storing the address of the last digit of the found result into counter_post[n]
				counter_post[0] = i+1;
		
				//replacing the elements before the first digit of the first result to '*'
				for(n=i-1; n > -1; n--){
					grid[j][n]= 0;
				}
				flag=1;
			}else{grid[j][i]=0;}
			if(flag==1) break;
		}
		
		if(flag==0)
			grid[j][29]=0;
		
		
		if(flag==1){
			//searching the next result after the first one
			m=0;
			for (x = (counter_post[m]+1); x < 29; x++){
				if ((grid[j][x] == (int) ten) && (grid[j][x+1] == (int) digit)){
					m++;//counter update
					counter_pre[m] = x;
					counter_post[m] = x+1;
					if((counter_pre[m]-1)>counter_post[m-1]){
						//replacing all the elements before the next result to '*' until the last digit(counter_post) of the previous result
						for (columnnumber_pre = counter_pre[m]-1; columnnumber_pre > counter_post[m-1]; columnnumber_pre--){
								grid[j][columnnumber_pre]= 0;
						}
					}
				}
			}
			if(counter_post[m]!= 29){	
				for(y = counter_post[m]+1; y<30; y++){
					grid[j][y]=0;
				}
			}
		}	
		
		if(flag==1)
			times += (m+1);
			
	}
	//printing the grid	
	//char charactergrid[30][30];
	int length = 30;
	for(j=0; j<length; j++){
		for(i=0; i<length; i++){
			if(grid[j][i]==0)
				printf("* ");
			else
				printf("%d ",grid[j][i]);
		}
		printf("\n");
	}
	printf("%d%d occurs %d times.\n", (int) ten, (int) digit, times);
	break;
}
		if(target<10 || target>10000)printf("Invalid number! Please enter another number that is within the range.\n");
	}
}

void SumMatch(){
int target;
int j;
int i;
int x;
int y;
int n=0;
int m;
int s;
int a=0;
int b=0;
int c=0;
int d=0;
int e;
int two[200];
int three[200];
int four[200];
int five [200];
printf("Match which sum(1-20)?");

while(1){
	scanf("%d", &target);
	if (target>0 && target<21){ 
		for(j=0; j<30; j++){
			for(i=0;i<30;i++){
				x=0;
				s=0;
					//SumMatching for each i on the same row
					while((s < target) && (i+x<30)){s = s + grid[j][i+x];x++;}
					
					//conditioning
					if (s == target){
						if(x==2){	//storing the two-sequence numbers
						two[a] = grid[j][i+x-2];
						two[a+1]= grid[j][i+x-1];
						a=a+2;
						n++; //counter update
						}
						if(x==3){	//storing the three-sequence numbers
						three[b] = grid[j][i+x-3];
						three[b+1] = grid[j][i+x-2];
						three[b+2] = grid[j][i+x-1];
						b=b+3;
						n++; //counter update 
						}
						if(x==4){	//storing the four-sequence numbers
						four[c] = grid[j][i+x-4];
						four[c+1] = grid[j][i+x-3];
						four[c+2] = grid[j][i+x-2];
						four[c+3] = grid[j][i+x-1];
						c=c+4;
						n++; //counter update 
						}
						if(x==5){	//storing the five-sequence numbers
						five[d] = grid[j][i+x-5];
						five[d+1] = grid[j][i+x-4];
						five[d+2] = grid[j][i+x-3];
						five[d+3] = grid[j][i+x-2];
						five[d+4] = grid[j][i+x-1];
						d=d+5;
						n++; //counter update 
						}
						//adjusting the value of i to i+x+1 since one SumMatch is found
						i=i+x;
					} 
			}
		}
		
	}else{
		printf("Invalid number! Please enter another number that is within the range.\n");
		}

	if(target>0 && target<21){
		if(a/2>0){	
			printf("\n%d entries with size-2 sequences: ", a/2); 
			for(m=0; 2*m<(a); m++){printf("(%d %d) ", two[2*m], two[2*m+1]);}
		}
		if(b/3>0){
			printf("\n%d entries with size-3 sequences: ", b/3); 
			for(m=0; 3*m<(b); m++){printf("(%d %d %d) ", three[3*m], three[3*m+1], three[3*m+2]);}
		}
		if(c/4>0){
			printf("\n%d entries with size-4 sequences: ", c/4);
			for(m=0; 4*m<(c); m++){printf("(%d %d %d %d) ", four[4*m], four[4*m+1], four[4*m+2], four[4*m+3]);}
		}
		if(d/5){
			printf("\n%d entries with size-5 sequences: ", d/5);
			for(m=0; 5*m<(d); m++){printf("(%d %d %d %d %d)", five[5*m], five[5*m+1], five[5*m+2], five[5*m+3], five[5*m+4]);}
		}
		printf("\nTotal %d sequences found.\n", n);
		break;
	}
}
}


int main (){
//fill the grid with random numbers
int e;
int f;
for (e = 0; e < 30; e++) {
	for (f = 0; f < 30; f++) {
        grid [e][f] = rand() % 9 + 1;
	};
}
//random seed
	srand(time(NULL));

//user options
char choice;
printf("(M) Make   (D) Display   (R) Reverse   (F) Find   (S) Sum-Match   (Q) Quit");

while(1){
scanf("%s",&choice);
switch(choice){
	case 'm':
	case 'M':	MakeGrid();
				printf("Please issue another command to continue or issue (Q) 'Quit' command to quit the function.\n");
				break;
	case 'd':
	case 'D':	PrintGrid();
				printf("\nNote: In the first attempt, the command (D) 'Display' displays a 30x30 puzzle aesthetically by default.\
				\nIn the following attempts, it will display the previous 30x30 puzzle only. It will not create another new 30x30 puzzle.\
				\nIf you want to display another new 30x30 puzzle, please make a new one first by issuing (M) 'Make' first and then display it by issuing (D) 'Display'\n");	
				printf("Please issue another command to continue or issue (Q) 'Quit' command to quit the function.\n");
				break;
	case 'r':
	case 'R':	Reverse();
				break;
	case 'f':
	case 'F':	Find();
				printf("\nIf you want to find another number, issue (M) to make a new grid.");
				printf("\nIssue another command to continue or issue (Q) 'Quit' command to quit the function.\n");
				break;
	case 's':
	case 'S':	SumMatch();
				break;
	case 'q':
	case 'Q':	printf("Quitting the program. Bye...\n");
				return(0);
	default:	printf("Invalid command! Please issue a valid command.\n");
				break;
}
}

}
