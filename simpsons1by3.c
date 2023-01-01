#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f(x) 1/(1+x*x)

int main()
{
    printf("\nName - Satyam Rawat , University RNo - 2017006 , Section -G , Class Rno - 16 , Course- BTECH CSE\n\n");
    
 double lower, upper, integration=0.0, stepSize, x;
 int i, subInterval;
 
 /* Input */
 printf("Enter lower limit of integration: ");
 scanf("%lf", &lower);
 printf("Enter upper limit of integration: ");
 scanf("%lf", &upper);
 printf("Enter number of sub intervals: ");
 scanf("%d", &subInterval);

 /* Calculation of step size */
 stepSize = (upper - lower)/subInterval;

 /* Finding Integration Value */
 integration = f(lower) + f(upper);
 for(i=1; i<= subInterval-1; i++)
 {
  x= lower + i*stepSize;
  if(i%2==0)
  {
   integration = integration + 2 * f(x);
  }
  else
  {
   integration = integration + 4 * f(x);
  }
 }
 integration = integration * stepSize/3;
 printf("\nRequired value of integration is: %lf", integration);
 return 0;
}