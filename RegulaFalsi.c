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
	float x1, x2, x3, x;
	float error ; 
	printf("Enter the allowed error "); 
	puts(""); 
	scanf("%f", &error); 
	do {
		printf("Enter the initial roots of the equation: "); 
		puts(""); 
		scanf("%f%f", &x1, &x2); 
		if(find_value_at(x1) * find_value_at(x2) >= 0) {
			printf("Invalid Roots");
			puts(""); 
			continue; 
		} else {
			printf("The root of the equation lie between %lf and %lf", x1, x2); 
			puts(""); 
			break;
		}
	} while(true); 
	x = find(x1, x2); 
	bool ok = false; 
	int iter = 1; 
	do {
		printf("Iterations = %d, x1 = %f, x2 = %f, x = %f", iter, x1, x2, x); 
		puts(""); 
		if(ok) {
			printf("The root of the equation is : %f", x); 
			puts(""); 
			break; 
		}
		if(find_value_at(x) * find_value_at(x1) < 0) {
			x2 = x; 
		} else {
			x1 = x; 
		}
		x3 = find(x1, x2); 
		if(fabs(x3 - x) < error) {
			ok = true; 
		}
		x = x3; 
		iter++; 
	} while(true); 
	return 0; 
}
