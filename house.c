#include<stdio.h>


int c;  					//global differentiating variable for small and big house
char s;						//global symbol variable
int a;						//small house counting variable
int b;						//big house counting variable	
int w;						//the width of the window
char answer1;
char answer2;
char answer3;


int main(){

do{
	printf("\nDo you want a big or small house? (Q:Quit B:Big S:Small)");
	scanf("%s",&answer1);
	switch (answer1){
		case 'q':
		case 'Q':			printf("Quitting the program... Bye...");
							printf("\n");
							printf("\n");
							return(0);
			break;
		case 'b':
		case 'B':
				c=60;	
			break;
		case 's':
		case 'S':
				c=30;
			break;
		default:			printf("Invalid response %c... Try again...\n",answer1);
			continue;
		}
	
	
	printf("Which character do you want to use for drawing? DASH(-), STAR(*), or DOT(.)?");
	scanf("%s",&answer2);	
	switch (answer2){
		case '-': 			s='-';
							printf("Using DASH(-) to draw the house\n");
			break;
		case '*':			s='*';
							printf("Using STAR(*) to draw the house\n");
			break;
		case '.':			s=46;
							printf("Using DOT(.) to draw the house\n");
			break;
		default:			printf("Invalid response %c... Try again...\n",answer2);
			continue;
		}	
			
							
	printf("How many windows do you want? (0-2 for small house, and 0-4 for big house)");
	scanf("%s",&answer3);
	
	switch (answer3){
		case 45:
							printf("Number of windows cannot be negative... Try again...\n");	
			break;
	
		case 48:			//no window case
							if(c==30){
							printf("\n");  
																			//small house roof 1
							printf("     	 ");
							for(b=1; b<=12; b++){
							printf("%c",s); 
							}
							printf("         ");
							printf("\n");
				
																			//small house roof 2
							printf("      ");
							for(b=1; b<=18; b++){
							printf("%c",s); 
							}
							printf("      ");
							printf("\n");
			
																			//small house roof 3
							printf("   ");
							for(b=1; b<=24; b++){
							printf("%c",s); 
							}
							printf("   ");
							printf("\n");
				
																			//small house roof 4
							for(b=1; b<=30; b++){
							printf("%c",s); 
							}
							printf("\n");
							};	
					
							if(c==60){
							printf("\n");  
																			//big house roof 1
							printf("     	 ");
							for(b=1; b<=60-18; b++){
							printf("%c",s); 
							}
							printf("         ");
							printf("\n");
				
																			//big house roof 2
							printf("      ");
							for(b=1; b<=60-12; b++){
							printf("%c",s); 
							}
							printf("      ");
							printf("\n");
					
																			//big house roof 3
							printf("   ");
							for(b=1; b<=60-6; b++){
							printf("%c",s); 
							}
							printf("   ");
							printf("\n");
						
																			//big house roof 4
							for(b=1; b<=60; b++){
							printf("%c",s); 
									}
							printf("\n");
							};	
							w = 0;
							for(a=0; a<9; a++){        						// outer loop
																			// on this row, first write the numbers
							for(b=1; b<=(c-w)/2; b++){
							printf("%c",s); 
							}
							for(b=1; b<=w; b++){
							printf(" ");       								// leave some space between 
							}
							for(b=1; b<=(c-w)/2; b++){
							printf("%c",s); 
							}
							printf("\n");         							// one row is done	
							}
							
							for(b=1; b<=c; b++){							// ending with two rows
							printf("%c",s); 
							}
							printf("\n");         							// second last line
							for(b=1; b<=c; b++){
							printf("%c",s); 
							}
							printf("\n");         							// last line	
							
							if(c==30) printf("\nSMALL HOUSE WITH NO WINDOW\n");
							if(c==60) printf("\nBIG HOUSE WITH NO WINDOW\n");			
			break;
					
		case 49:			//one window case
							if(c==30){
							printf("\n");  
																			//small house roof 1
							printf("     	 ");
							for(b=1; b<=12; b++){
							printf("%c",s); 
							}
							printf("         ");
							printf("\n");
			
																			//small house roof 2
							printf("      ");
							for(b=1; b<=18; b++){
							printf("%c",s); 
							}
							printf("      ");
							printf("\n");
			
																			//small house roof 3
							printf("   ");
							for(b=1; b<=24; b++){
							printf("%c",s); 
							}
							printf("   ");
							printf("\n");
			
																			//small house roof 4
							for(b=1; b<=30; b++){
							printf("%c",s); 
							}
							printf("\n");
							};	
				
							if(c==60){
							printf("\n");  
																			//big house roof 1
							printf("     	 ");
							for(b=1; b<=60-18; b++){
							printf("%c",s); 
							}
							printf("         ");
							printf("\n");
			
																			//big house roof 2
							printf("      ");
							for(b=1; b<=60-12; b++){
							printf("%c",s); 
							}
							printf("      ");
							printf("\n");
			
																			//big house roof 3
							printf("   ");
							for(b=1; b<=60-6; b++){
							printf("%c",s); 
							}
							printf("   ");
							printf("\n");
				
																			//big house roof 4
							for(b=1; b<=60; b++){
							printf("%c",s); 
							}
							printf("\n");
							};	
				
							w = 6;
							for(a=0; a<9; a++){         					// outer loop
																			// on this row, first write the numbers
							for(b=1; b<=(c-w)/2; b++){
							printf("%c",s); 
							}
							
							for(b=1; b<=w; b++){
							printf(" ");       								// leave some space between 
							}
							
							for(b=1; b<=(c-w)/2; b++){
							printf("%c",s); 
							}
							printf("\n");         							// one row is done	
							}
							
							for(b=1; b<=c; b++){							// ending with two rows
							printf("%c",s); 
							}
							printf("\n");         							// second last line
							for(b=1; b<=c; b++){
							printf("%c",s); 
							}
							printf("\n");         							// last line
							if(c==30) printf("\nSMALL HOUSE WITH ONE WINDOW\n");
							if(c==60) printf("\nBIG HOUSE WITH ONE WINDOW\n");						
			break;
		
		case 50:			//two windows case
							if(c==30){
							printf("\n");  
																			//small house roof 1
							printf("     	 ");
							for(b=1; b<=12; b++){
							printf("%c",s); 
							}
							printf("         ");
							printf("\n");
			
																			//small house roof 2
							printf("      ");
							for(b=1; b<=18; b++){
							printf("%c",s); 
							}
							printf("      ");
							printf("\n");
				
																			//small house roof 3
							printf("   ");
							for(b=1; b<=24; b++){
							printf("%c",s); 
							}
							printf("   ");
							printf("\n");
			
																			//small house roof 4
							for(b=1; b<=30; b++){
							printf("%c",s); 
							}
							printf("\n");
							};	
						
							if(c==60){
							printf("\n");  
																			//big house roof 1
							printf("     	 ");
							for(b=1; b<=60-18; b++){
							printf("%c",s); 
							}
							printf("         ");
							printf("\n");
					
																			//big house roof 2
							printf("      ");
							for(b=1; b<=60-12; b++){
							printf("%c",s); 
							}
							printf("      ");
							printf("\n");
				
																			//big house roof 3
							printf("   ");
							for(b=1; b<=60-6; b++){
							printf("%c",s); 
							}
							printf("   ");
							printf("\n");
						
																			//big house roof 4
							for(b=1; b<=60; b++){
							printf("%c",s); 
							}
							printf("\n");
							};	
					
							w = 6;
							for(a=0; a<9; a++){         					// outer loop
																			// on this row, first write the numbers
							for(b=1; b<=(c-2*w-(2-1)*w)/2; b++){
							printf("%c",s); 
							}
							
							for(b=1; b<=w; b++){
							printf(" ");       								// leave some space between 
							}
							for(b=1; b<=(2-1)*w; b++){
							printf("%c",s); 
							}
							for(b=1; b<=w; b++){
							printf(" ");       								// leave some space between 
							}
							for(b=1; b<=(c-2*w-(2-1)*w)/2; b++){
							printf("%c",s); 
							}
							printf("\n");         							// one row is done	
							}
							
							for(b=1; b<=c; b++){							// ending with two rows
							printf("%c",s); 
							}
							printf("\n");         							// second last line
							for(b=1; b<=c; b++){
							printf("%c",s); 
							}
							printf("\n");         							// last line
							if(c==30) printf("\nSMALL HOUSE WITH TWO WINDOWS\n");
							if(c==60) printf("\nBIG HOUSE WITH TWO WINDOWS\n");				
			break;
		
		case 51:			//three windows case
							if(c==30){printf("Small house cannot have more than 2 windows... Try again...\n");
			break;
							};
							
							if(c==60){
							printf("\n");  
																			//big house roof 1
							printf("     	 ");
							for(b=1; b<=60-18; b++){
							printf("%c",s); 
							}
							printf("         ");
							printf("\n");
			
																			//big house roof 2
							printf("      ");
							for(b=1; b<=60-12; b++){
							printf("%c",s); 
							}
							printf("      ");
							printf("\n");
			
																			//big house roof 3
							printf("   ");
							for(b=1; b<=60-6; b++){
							printf("%c",s); 
							}
							printf("   ");
							printf("\n");
				
																			//big house roof 4
							for(b=1; b<=60; b++){
							printf("%c",s); 
							}
							printf("\n");
							};	
							
							w = 6;
							for(a=0; a<9; a++){       						// outer loop
																			// on this row, first write the numbers
							for(b=1; b<=(60-3*w-(3-1)*w)/2; b++){
							printf("%c",s); 
							}
							for(b=1; b<=w; b++){
							printf(" ");       								// leave some space between 
							}
							for(b=1; b<=(3-2)*w; b++){
							printf("%c",s); 
							}	
							for(b=1; b<=w; b++){
							printf(" ");       								// leave some space between 
							}
							for(b=1; b<=(3-2)*w; b++){
							printf("%c",s); 
							}
							for(b=1; b<=w; b++){
							printf(" ");       								// leave some space between 
							}
							for(b=1; b<=(60-3*w-(3-1)*w)/2; b++){
							printf("%c",s); 
							}
							printf("\n");         							// one row is done	
							}
							
							for(b=1; b<=c; b++){							// ending with two rows
							printf("%c",s); 
							}
							printf("\n");         							// second last line
							for(b=1; b<=c; b++){
							printf("%c",s); 
							}
							printf("\n");         							// last line	
							printf("\nBIG HOUSE WITH THREE WINDOWS\n");						
			break;
		
		case 52:			//four windows case
							if(c==30){printf("Small house cannot have more than 2 windows... Try again...\n");
			break;
							};

							if(c==60){
							printf("\n");  
																			//big house roof 1
							printf("     	 ");
							for(b=1; b<=60-18; b++){
							printf("%c",s); 
							}
							printf("         ");
							printf("\n");
																			//big house roof 2
							printf("      ");
							for(b=1; b<=60-12; b++){
							printf("%c",s); 
							}
							printf("      ");
							printf("\n");
						
																			//big house roof 3
							printf("   ");
							for(b=1; b<=60-6; b++){
							printf("%c",s); 
							}
							printf("   ");
							printf("\n");					
																			//big house roof 4
							for(b=1; b<=60; b++){
							printf("%c",s); 
							}
							printf("\n");
							};	
							
							w = 6;
							for(a=0; a<9; a++){         					// outer loop
																			// on this row, first write the numbers
							for(b=1; b<=(60-4*w-(4-1)*w)/2; b++){
							printf("%c",s); 
							}	
							for(b=1; b<=w; b++){
							printf(" ");       								// leave some space between 
							}
							for(b=1; b<=(4-(4-1))*w; b++){
							printf("%c",s); 
							}
							for(b=1; b<=w; b++){
							printf(" ");     							  	// leave some space between 
							}
							for(b=1; b<=(4-(4-1))*w; b++){
							printf("%c",s); 
							}
							for(b=1; b<=w; b++){
							printf(" ");       								// leave some space between 
							}
							for(b=1; b<=(4-(4-1))*w; b++){	
							printf("%c",s); 
							}
							for(b=1; b<=w; b++){
							printf(" ");  continue;    						// leave some space between 
							}
							for(b=1; b<=(60-4*w-(4-1)*w)/2; b++){
							printf("%c",s); 
							}
							printf("\n");         							// one row is done	
							}
							
							for(b=1; b<=c; b++){							// ending with two rows
							printf("%c",s); 
							}
							printf("\n");         							// second last line
							for(b=1; b<=c; b++){
							printf("%c",s); 
							}
							printf("\n");         							// last line	
							printf("\nBIG HOUSE WITH FOUR WINDOWS\n");		
			break;
		 
		case 53:
							if(c==60){printf("Big house cannot have more than 4 windows... Try again...\n");}
							if(c==30){printf("Small house cannot have more than 2 windows... Try again...\n");}
		 	break;
		case 54:
							if(c==60){printf("Big house cannot have more than 4 windows... Try again...\n");}
							if(c==30){printf("Small house cannot have more than 2 windows... Try again...\n");}
		 	break;
		case 55:
							if(c==60){printf("Big house cannot have more than 4 windows... Try again...\n");}
							if(c==30){printf("Small house cannot have more than 2 windows... Try again...\n");}
		 	break;
		case 56:
							if(c==60){printf("Big house cannot have more than 4 windows... Try again...\n");}
							if(c==30){printf("Small house cannot have more than 2 windows... Try again...\n");}
		 	break;
		case 57:
							if(c==60){printf("Big house cannot have more than 4 windows... Try again...\n");}
							if(c==30){printf("Small house cannot have more than 2 windows... Try again...\n");}
		 	break;
		 	
		}	
	
	
	}while(answer1!='q'||answer1!='Q');										//do-while function's ending loop
	
	
}

