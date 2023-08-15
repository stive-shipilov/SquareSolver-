#include <stdio.h>
#include <math.h>

int main(void) 
{
  double a, b, c, x1, x2;
  printf("Enter the coefficients A, B, C separated by commas - %lf,%lf,%lf\n", a,b,c);
  scanf("%lf, %lf, %lf", &a,&b,&c);
  double dis = b*b - 4*a*c;
  if (dis>=0) 
  {
    x1 = (-b+sqrt(dis))/(2*a);
    x2 = (-b-sqrt(dis))/(2*a);
  }
  if(dis<0) printf("This equation has no solution");
  else if(dis == 0) printf("Solution of the equation --> X = %.2lf",x1);
  else printf("Solution of the equation --> X1 = %.2lf, X2 = %.2lf",x1,x2);
}              