#include <stdio.h> 
#include <math.h> 
#include <stdbool.h> 
double find_value_at(double x) {
	return (double) (x * x * x) - (2 * x) - 5; 
}
double bisect(double x1, double x2) {
	return (double)(x1 + x2) / 2.0; 
}
int main() {
	double x1, x2, x3, x;
	double error ; 
	printf("Enter the allowed error "); 
	puts(""); 
	scanf("%lf", &error); 
	do {
		printf("Enter the initial roots of the equation: "); 
		puts(""); 
		scanf("%lf%lf", &x1, &x2); 
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
	// find the intermediate point
	x = bisect(x1, x2); 
	int iter = 1; 
	do {
		printf("Iterations = %d, x1 = %lf, x2 = %lf, x = %lf", iter, x1, x2, x); 
		puts(""); 
		if(find_value_at(x) * find_value_at(x1) < 0) {
			x2 = x; 
		} else {
			x1 = x; 
		}
		x3 = bisect(x1, x2); 
		if(fabs(x3 - x) < error) {
			printf("The root of the equation is : %lf", x); 
			puts(""); 
			break; 
		}
		x = x3; 
		iter++; 
	} while(true); 
	return 0; 
}
