#include <stdio.h> 

double get(double x) {
	return (double)(1.0/ (1.0 + x*x)); 
}

int main() {
	double a, b; 
	printf("Enter the value of a and b"); puts(""); 
	scanf("%lf%lf", &a, &b); 
	int n; 
	printf("Enter the number of intervals"); puts("");
	scanf("%d", &n); 
	double h = (b - a) / n; 
	double s = get(a) + get(b);
	int pos = 1; 
	for (int i = a + h; i < b; i += h) {
		if (pos % 3 == 0) {
			s = s + (2 * get(i)); 
		} else {
			s = s + (3 * get(i)); 
		}
		pos += 1; 
	}
	s = (3 * h * s) / 8.0; 
	printf("The value of the integral is %lf", s); 
	return 0; 
}