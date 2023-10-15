#include <stdio.h> 
#include <math.h>
#include <stdbool.h> 
#include <stdlib.h> 

double f(double x) {
	return (double) (x * x) - (2.0 * x) - 5.0; 
}

double phi(double x) {
	return (double) (sqrt((2.0 * x) + 5)); 
}

double phid(double x) {
	return (double) (1.0 / phi(x)); 
}

signed main() {
	double x0, x1, x, x3;
	do {
		printf("Enter the initial root of the equation : "); 
		puts(""); 
		scanf("%lf%lf", &x0, &x1); 
		if(f(x0) * f(x1) < 0) {
			printf("The initial roots of the equation are: %lf and %lf", x0, x1); 
			puts(""); 
			break; 
		} else {
			printf("Invalid roots"); 
			puts(""); 
		}
	} while(true);
	if(fabs(phid(x0)) >= 1) {
		printf("Rewrite the phi equation"); 
		puts(""); 
		return 0;
	} 
	x0 = (x0 + x1) / 2.0; 
	printf("Enter the allowed error: "); 
	double error;
	puts(""); 
	scanf("%lf", &error);
	bool ok = false;
	int iteration = 1; 
	x = phi(x0);
	do {
		printf("Iteration = %d, x0 = %lf, x = %lf", iteration, x0, x);
		puts(""); 
		if(ok) {
			printf("The equation of the root is : %lf", x); 
			puts(""); 
			break; 
		}	
		x3 = phi(x);
		if(fabs(x3 - x) < error) {
			ok = true;
		}
		x0 = x; 
		x = x3; 
		iteration++;  
	} while(true); 
	return 0;
}
