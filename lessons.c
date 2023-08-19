#include <stdio.h>
#include <math.h>
#include <stdbool.h>
 
const double EPS = 1e-9;

bool comp_eq(double a, double b) {
  return fabs(a-b) < EPS;
}

bool comp_more(double a, double b) {
  return a-b > EPS;
}

int main(void) {
  double a = 0.0, b=0.0, c=0.0;
  printf("Enter the coefficients A, B, C separated by commas\n");
  if(scanf("%lf, %lf, %lf", &a,&b,&c) == 3) {
    double dis = b*b - 4*a*c;
    if (comp_more(dis,0.0) == true) {
      double x1 = (-b+sqrt(dis))/(2*a);
      double x2 = (-b-sqrt(dis))/(2*a);
      printf("Solution of the equation --> X1 = %.2lf, X2 = %.2lf",x1,x2);
      return 0;       
    }
    else if(comp_eq(dis,0.0) == true) {
      double x = (-b)/(2*a);
      printf("Solution of the equation --> X = %.2lf",x);
      return 0;
    }
    else {
      printf("This equation has no solution");
      return 0;
    }
  }
  else {
    printf("Inpur error");
    return 0;
  }
} 
