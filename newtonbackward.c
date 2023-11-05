#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <math.h> 

signed main() {
	int n; 
	printf("Enter the number of terms"); 
	puts("");
	scanf("%d", &n); 
	double a[n][n + 1];  		
	printf("Enter the values of x"); 
	puts(""); 
	for(int i = 0; i < n; i++) {
		scanf("%lf", &a[i][0]); 
	}
	printf("Enter the values of y"); 
	puts(""); 
	for(int i = 0; i < n; i++) {
		scanf("%lf", &a[i][1]); 
	}
	for(int j = 2; j < n + 1; j++) {
		for(int i = 0; i < n + 1 - j; i++) {
			a[i][j] = a[i + 1][j - 1] - a[i][j - 1]; 
		}
	}
	printf("The difference table is as follows"); 
	puts(""); 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n + 1 - i ;j++) {
			printf("%lf ", a[i][j]); 
		}
		puts("");
	}
	printf("Enter the value of x for which you want to find the value of y"); 
	puts("");
	double x; 
	scanf("%lf", &x); 
	double u = ((x - a[n - 1][0])) / ((a[1][0] - a[0][0])); 
	double y = a[n - 1][1];  
	double u1 = u; 
	double fact = 1; 
	for(int i = n - 2, j = 2; i >= 0; i--, j += 1) {
		y = y + (u1 * a[i][j]) / fact;
		u1 = u1 * (u - (double)(i - 1));
		fact = fact * i; 
	}
	printf("The value at x = %lf is %lf", x, y); 
	puts(""); 
	return 0; 
}