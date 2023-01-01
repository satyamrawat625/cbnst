#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

int main() {
    printf("\nName - Satyam Rawat , University RNo - 2017006 , Section -G , Class Rno - 16 , Course- BTECH CSE\n");

    int n;
    printf("Enter the no of linear equations : ");
    scanf("%d", &n);
    double a[n][n + 1];

    // Input
    printf("Enter the equations in the form of ax+by+c =d   \n");
    char s[n][100];
    for (int i = 0; i < n; i++) {
        printf("Enter the %dth equation:  ",i);
        scanf("%s",&s[i]);
    }

    // for(int i=0 ;i<n;i++)printf(s[i]);

    for (int i = 0; i < n; i++) {
         int c= 0;
            int j=0;
        // while (s[i][c]!='\0' && isdigit(s[i][c])){ c++ ;}

        while (1){
            int sign =1 ;
            if(!c&&s[i][c]=='-'){c++;sign=-1 ;}
            else if(c && s[i][c-1]=='-'){
                sign=-1 ;}
            
            int val =0;
            while (isdigit(s[i][c]))
            {  val= val*10;
                val += s[i][c]-'0' ;
                c++ ;
            }
            a[i][j++]=val*sign;
            if(s[i][c]=='\0')break ;
                
            while (s[i][c]!='\0' && !isdigit(s[i][c]))
            { c++ ;
            }

            if(s[i][c]=='\0')break ;
        }
    }

    // Printing input matrix
    printf("\nArgument Matrix:: \n");
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (j == n) printf(" | ");
            printf("%.2lf ", a[i][j]);
        }
        printf("\n\n");
    }
    // converting lower triangular matrix
    for (int i = 0; i < n; i++) {
        if (a[i][i] == 0) {
            for (int j = i + 1; j < n; j++) {
                if (a[j][i] != 0) {
                    for (int k = 0; k < n + 1; k++) {
                        double temp = a[i][k];
                        a[i][k] = a[j][k];
                        a[j][k] = temp;
                    }
                }
            }
        }
        if (a[i][i] == 0) {
            fprintf(stderr, "Given system of eq do not have a Unique Solution.");
            return 1;
        }
        // make the first element 1
        double temp = a[i][i];
        for (int j = i; j < n + 1; j++) {
            a[i][j] = a[i][j] / temp;
        }
        for (int j = i + 1; j < n; j++) {
            if (a[j][i] != 0) {
                double div = a[j][i] / a[i][i];
                for (int k = i; k < n + 1; k++) {
                    a[j][k] = a[j][k] - a[i][k] * div;
                }
            }
        }
    }
    printf("Final Matrix : \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (j == n) printf(" | ");
            printf("%.2lf ", a[i][j]);
        }
        printf("\n\n");
    }
    // Backward Substitution
    double x[n]; // array to store solutions
    for (int i = n - 1; i >= 0; i--) {
        if (a[i][i] == 0) {
            continue;
        }
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
    printf("The Solutions are : \n");
    for (int i = 0; i < n; i++) {
        printf("x_%d = %lf\n\n", i, x[i]);
    }
    return 0;
}