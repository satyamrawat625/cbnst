#include <stdio.h>
#include <math.h>

#define f(x) 1 / (1 + pow(x, 2))

int main()
{
    printf("\nName - Satyam Rawat , University RNo - 2017006 , Section -G , Class Rno - 16 , Course- BTECH CSE\n\n");

    double lower, upper, integration = 0.0, stepSize,x;
    int i, subInterval;

    /* Input */
    printf("Enter lower limit of integration: ");
    scanf("%lf", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%lf", &upper);
    printf("Enter number of sub intervals: ");
    scanf("%d", &subInterval);

    /* Finding step size */
    stepSize = (upper - lower) / subInterval;

    /* Finding Integration Value */
    integration = f(lower) + f(upper);
    for (i = 1; i <= subInterval - 1; i++)
    {
        x = lower + i * stepSize;
        integration = integration + 2 * f(x);
    }
    integration = integration * stepSize / 2;
    printf("\nRequired value of integration is: %.3f", integration);
    return 0;
}