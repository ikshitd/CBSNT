#include <stdio.h> 
#include <math.h> 
#include <stdbool.h> 
float find_value_at(float x) {
	return (float) (x * x * x) - (2 * x) - 5; 
}
float find(float x1, float x2) {
	return (x1 * find_value_at(x2) - x2 * find_value_at(x1)) / (find_value_at(x2) - find_value_at(x1)); 
}
int main() {
	float x1, x2, x;
	float error ; 
	printf("Enter the allowed error "); 
	puts(""); 
	scanf("%f", &error); 
	printf("Enter the initial roots of the equation: "); 
	puts(""); 
	scanf("%f%f", &x1, &x2); 
	
	x = find(x1, x2); 
	bool ok = false; 
	int iter = 1; 
	
	do {
		x1 = x2; 
		x2 = x; 
		printf("Iterations = %d, x1 = %f, x2 = %f, x = %f", iter, x1, x2, x); 
		puts(""); 
		if(ok) {
			printf("The root of the equation is : %f", x); 
			puts(""); 
			break; 
		}
		x = find(x1, x2); 
		if(fabs(x - x2) < error) {
			ok = true; 
		}
		iter++; 
	} while(true); 
	return 0; 
}
