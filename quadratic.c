#include<stdio.h>
#include<math.h>
int main(){
    
    printf("Name - Satyam Rawat , University RNo - 2017006 , Section -G , Class Rno - 16 , Course- BTECH CSE\n");
   double a, b ,c ;
   printf("Enter the coefficients of the quadratic equation ; a, b ,c\n");
   scanf("%lf%lf%lf", &a,&b,&c) ;

    double d= b*b- 4*a*c ;
    double r1, r2 ;

    printf("Roots are : \n");
    if(d>0)
    {  r1 = (-b+ sqrt(d))/(2*a) ;
         r2=  (-b - sqrt(d))/(2*a) ;
         printf("r1 = %lf and r2 = %lf\n", r1, r2);
    }
    else if(d==0)
    {  r1 = (-b+ sqrt(d))/(2*a) ;
       r2= (-b - sqrt(d))/(2*a) ;
       
     printf("r1 = %lf and r2 = %lf\n", r1,r2);
    }
    else{
        double real1= -b/(2*a) ;
        double img1= sqrt(-d)/(2*a) ;
    printf("r1 = %lf+%lfi and r2 = %lf-%lfi\n", real1, img1, real1, img1);    }
}
