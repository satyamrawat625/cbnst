#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
int main()
{
    int n,i,j,k,flag=0,count=0;
  printf("\nEnter the no. of equations\n") ;
    scanf("%d",&n)  ;         //Input no. of equations
    double a[n][n+1];            //declare a 2d array for storing the elements of the augmented matrix
    double x[n];                //declare an array to store the values of variables
    double eps,y;
    printf("Enter the elements of the augmented matrix row-wise:\n");
    for (i=0;i<n;i++)
        for (j=0;j<=n;j++)
           scanf("%lf",&a[i][j]);
    printf("\nEnter the initial values of the variables:\n");
    for (i=0;i<n;i++) scanf("%lf",&x[i]);
     printf("\nEnter the accuracy upto which you want the solution:\n");
    scanf("%lf",&eps);

    for (i=0;i<n;i++)                    //Pivotisation(partial) to make the equations diagonally dominant
        for (k=i+1;k<n;k++)
            if (abs(a[i][i])<abs(a[k][i]))
                for (j=0;j<=n;j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
    printf("Iteration :\n\n"); 
    
    do                            //Perform iterations to calculate x1,x2,...xn
    {
        printf("\n  %d\t",count+1);
        for (i=0;i<n;i++)                //Loop that calculates x1,x2,...xn
        {
            y=x[i];
            x[i]=a[i][n];
            for (j=0;j<n;j++)
            {
                if (j!=i)
                x[i]=x[i]-a[i][j]*x[j];
            }
            x[i]=x[i]/a[i][i];
            if (abs(x[i]-y)<=eps)            //Compare the ne value with the last value
                flag++;
            printf("%lf\t",x[i]);
        }
        cout<<"\n";
        count++;   
    }while(flag<n);                        //If the values of all the variables don't differ from their previious values with error more than eps then flag must be n and hence stop the loop
    
    cout<<"\n The solution is as follows:\n";
    for (i=0;i<n;i++)
        cout<<"x"<<i<<" = "<<x[i]<<endl;        //Print the contents of x[]
    return 0;
}