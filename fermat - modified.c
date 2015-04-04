#include <stdio.h>
#include <math.h>

#define max_value pow(2,4) //pow(double x, double y) returns x raised to the power of y

int main (){
unsigned long long int a, b, c;
unsigned int n;
	// loop the power value from 3 to 6
	for (n=3; n<=6; n++){
		
		// loop c vale from 1 to max_value
		for (c = 1; c < max_value; c++){
			
			// loop b value from 1 to max_value
			for (b = 1; b < max_value; b++){
				
				// loop a value from 1 to max_value
				for (a = 1; a < max_value; a++){
					printf("I'm now trying a=%lld, b=%lld, c=%lld and n=%d\n.", a, b, c, n);
					if (pow(a, n) + pow(b, n) == pow(c, n)){
						printf("Fermat's Conjecture is wrong!\n");
					// terminate the main function
					return (0); 
					}
					
				}
			}
		}
	}
printf("Fermat's Conjecture is right!\n");
}