#include <stdio.h> 
#include <stdbool.h>

float get(float x, float y) {
	return (float)(x + y); 
}

int main() {
	float x0 , y0, x1, y1, h, x;
	puts("Enter the values of x0, y0, h and x");
	scanf("%f%f%f%f", &x0, &y0, &h, &x); 
	x1 = x0, y1 = y0; 
	while(true) {
		if (x1 > x) { break; }
		y1 += (h * (x1, y1)); 
		x1 += h; 
		printf("x = %lf y = %lf\n", x1, y1); 
	} 
	return 0; 
}