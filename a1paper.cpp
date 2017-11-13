#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main() {
    double A = pow(2.0, -0.75);
    double B = sqrt(2);
    int n, i;
    double sum=0;
    scanf("%d", &n);
    
    double* m=(double*)malloc(n*sizeof(double*));
    for(i=0; i<n-1; i++){
        scanf("%lf", &m[i]);
        sum+=m[i]/pow(2,i+1);
        if (sum>=1)
            break;
    }
    double left=1;
    if (sum<1)
        printf("impossible\n");
    else {
        sum=0;
        for(int j=0; j<i; j++){
            sum+=m[j]/pow(B,j);
            left-=m[j]/pow(2,j+1);
        }
        sum+=left*pow(2,i+1)/pow(B,i);
        
        sum= (sum*(2+sqrt(2))-2-2*sqrt(2))*A/2;
        
        printf("%.11f\n", sum);
    }
    
    return 0;
}
