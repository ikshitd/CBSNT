#include <stdio.h> 
#include <math.h> 
#include <stdbool.h> 
float f(float x) {
	return (float) (x * x * x) - (3 * x) - 5; 
}
float df(float x) {
	return (float) (3 * x * x) - (3); 
}
int main() {
	float x0, x;
	float error ; 
	printf("Enter the allowed error "); 
	puts(""); 
	scanf("%f", &error); 
	printf("Enter the initial root of the equation: "); 
	puts(""); 
	scanf("%f", &x0); 
	
	bool ok = false; 
	int iter = 1; 
	
	do {
		if(df(x0) == 0) {
			printf("Mathematical Error !!"); 
			puts(""); 
			return 0; 
		}
		printf("Iterations = %d, x0 = %f", iter, x0); 
		x = x0 - (f(x0) / df(x0)); 
		puts(""); 
		if(ok) {
			printf("The root of the equation is : %f", x); 
			puts(""); 
			break; 
		}
		if(fabs(x - x0) < error) {
			ok = true; 
		}
		x0 = x; 
		iter++; 
	} while(true); 
	return 0; 
}
