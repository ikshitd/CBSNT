#include <stdio.h> 
#include <math.h> 
#include <stdbool.h>

const int N = 21; 
float a[N][N]; 
float x[N]; 
int n;

void convert_to_upper_triangular() { 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(j > i) {
				float ratio = a[j][i] / a[i][i]; 
				for(int k = 0; k < n + 1; k++) {
					a[j][k] = a[j][k] - (ratio * a[i][k]); 
				}
			}
		}
	}
	return; 
}

void apply_backward_substitution() {
	float sum = 0; 
	x[n - 1] = a[n - 1][n] / (a[n - 1][n - 1]); 
	for(int i = n - 2; i >= 0; i--) {
		sum = 0; 
		for(int j = i + 1; j < n; j++) {
			sum = sum + a[i][j] * x[j]; 
		}
		x[i] = (a[i][n] - sum) / a[i][i]; 
	}
}
	
int main() {
	printf("Enter the number of unknowns: "); 
	puts(""); 
	scanf("%d", &n); 
	printf("Enter the elements: "); 
	puts(""); 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n + 1; j++) {
			scanf("%f", &a[i][j]); 
		}
	}
	convert_to_upper_triangular();
	printf("Upper Triangular Matrix:"); 
	puts(""); 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n + 1; j++) {
			printf("%f ", a[i][j]); 
		}
		puts("");
	}
	apply_backward_substitution();
	printf("The solution is: "); 
	puts(""); 
	for(int i = 0 ; i < n; i++) {
		printf("%f ", x[i]); 
	}
	puts("");
	return 0; 
}
