#include <stdio.h> 
int main() {
    int n; 
    printf("Enter the number of observations"); puts("");
    scanf("%d", &n); 
    double x[n], y[n], mat[2][3];
    printf("Enter the x terms"); puts(""); 
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]); 
    }
    printf("Enter the y terms"); puts(""); 
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i]); 
    }
    double s1 = 0, s2 = 0, s3 = 0, s4 = 0; 
    for (int i = 0; i < n; i++) {
        s1 += (x[i]); 
        s2 += (y[i]); 
        s3 += (x[i] * y[i]); 
        s4 += (x[i] * x[i]); 
    }
    mat[0][0] = n;
    mat[0][1] = s1; 
    mat[0][2] = s2; 
    mat[1][0] = s1; 
    mat[1][1] = s4;
    mat[1][2] = s3; 
    double r = mat[1][0] / mat[0][0]; 
    for (int i = 0; i < 3; i++) {
        mat[1][i] = mat[1][i] - (r * mat[0][i]);  
    } 
    printf("The upper triangular matrix is"); puts(""); 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%0.3lf ", mat[i][j]); 
        }
        printf("\n"); 
    }
    double b = mat[1][2] / mat[1][1]; 
    double a = (mat[0][2] - mat[0][1] * b) / (mat[0][0]); 
    printf("Intercept: %lf and Slope = %lf", a, b); 
    printf("Equation of the line is: y = %lf + %lfx", a, b); 
    return 0;  
}