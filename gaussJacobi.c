#include <stdio.h> 
#include <stdbool.h> 
#include <stdlib.h> 
#include <math.h> 

const int N = 21; 
int n; 
double a[N][N]; 
double values[N]; 
double error; 

double find_sum(int i) {
	double current = 0; 
	for(int j = 0; j < n; j++) {
		if(i == j) continue; 
		current += fabs(a[i][j]); 
	}
	return current; 
}

void find_values() {
	double new_values[N];
	for(int i = 0; i < n; i++) {
		new_values[i] = 0; 
	}
	int iterations = 1; 
	bool fine = false;
	do {
		double sum = 0; 
		printf("Iteration = %d ", iterations); 
		for(int i = 0; i < n ;i++) {
			printf("%lf ", new_values[i]); 
		}
		puts(""); 
		if(fine) {
			printf("The roots of the equation are : ") ;
			for(int k = 0; k < n; k++) {
				printf("%lf ", values[k]);
			}
			puts(""); 
			break; 
		}
		for(int i = 0; i < n; i++) {
			sum = 0; 
			for(int j = 0; j < n; j++) {
				if(i != j) {
					sum = sum + a[i][j] * values[j]; 
				}
			}
			new_values[i] = (a[i][n] - sum) / a[i][i]; 
		}
		bool ok = true;
		for(int k = 0; k < n; k++) {
			ok = ok & (fabs(values[k] - new_values[k]) < error); 
		}
		if(ok){ 
			fine = true; 
		}
		for(int k = 0; k < n; k++) {
			values[k] = new_values[k]; 
		}
		iterations++;
	} while(true); 
} 

bool isOk() {
	bool ok = true; 
	for(int i = 0; i < n; i++) {
		ok = ok & (fabs(a[i][i]) >= fabs(find_sum(i))); 
	}
	return ok; 
}

signed main() {
	printf("Enter the number of unknowns"); 
	puts(""); 
	scanf("%d", &n); 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n + 1; j++) {
			scanf("%lf", &a[i][j]); 
		}
	}

	if(!isOk()) {
		printf("Gauss Jacobi is not applicable to the input matrix"); 
		puts(""); 
		return 0; 
	}
	printf("Enter the allowed error !!"); 
	puts("");
	scanf("%lf", &error); 
	find_values(); 
	return 0; 
}
