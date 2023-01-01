#include <stdio.h>

double f(double x, double y) {
    double m;
    m=(x-y)/(x + y);
    return m;
}

int main() {
    printf("\nName - Satyam Rawat , University RNo - 2017006 , Section -G , Class Rno - 16 , Course- BTECH CSE\n\n");

    double  k1, k2, k3, k4, k, y, x, h, xn;

    printf("y' = f(x,y) = (x-y)/(x+y)   given.\n");

    printf("Enter initial value for x (x_0): ");
    scanf("%lf", &x);
    printf("Enter initial value for y (y_0): ");
    scanf("%lf", &y);
    printf("Enter the spacing value for x (h): ");
    scanf("%lf", &h);
    printf("Enter the value of x at which y is required: (x_n): ");
    scanf("%lf", &xn);

    printf("x\t\ty\n");
    printf("%lf\t%lf\n", x, y);

    while (x <xn) {
        k1 = h * f(x, y);
        k2 = h * f((x + h / 2.0), (y + k1 / 2.0));
        k3 = h * f((x + h / 2.0), (y + k2 / 2.0));
        k4 = h * f((x + h), (y + k3));
        k = ((k1 + 2 * k2 + 2 * k3 + k4) / 6.0);
        y = y + k;
        x = x + h;
        printf("%lf\t%lf\n", x, y);
    }
    printf("f(%lf) = %lf", xn, y);
}