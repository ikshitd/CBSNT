#include <stdio.h> 

double get(double x) {
	return (double)(1.0/(1.0+x*x)); 
}

int main() {
	double a, b; 
	printf("Enter the value of a and b"); puts("");
	scanf("%lf%lf", &a, &b); 
	printf("Enter the number of intervals"); puts("");
	int n;
	scanf("%d", &n); 
	double h = (b - a) / n;
	double s = get(a) + get(b); 
	for (int i = a + h; i < b; i += h) {
		s = s +  (2 * get(i)); 
	}
	s = (h * s) / 2; 
	printf("The value of the integral is %lf", s); 
	return 0; 
}