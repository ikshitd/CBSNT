#include <stdio.h> 
int main() {
	int n; 
	printf("Enter the number of terms"); 
	puts(""); 
	scanf("%d", &n); 
	double x[n], y[n]; 
	printf("Enter the x terms"); puts(""); 
	for (int i = 0; i < n; i++) {
		scanf("%lf", &x[i]); 
	}
	printf("Enter the y terms"); puts(""); 
	for (int i = 0; i < n; i++) {
		scanf("%lf", &y[i]); 
	}
	double a; 
	printf("Enter the value of x for which you want to find the value of y"); 
	puts(""); 
	scanf("%lf", &a);
	double s = 0; 
	for (int i = 0; i < n; i++) {
		double term = 1; 
		for (int j = 0; j < n; j++) {
			if (i != j) {
				term = term * ((a - x[j]) / (x[i] - x[j])); 
			}
		}
		s = s + term * y[i]; 
	}
	printf("The value of y at x = %lf is %lf", a, s); 
	return 0; 
}