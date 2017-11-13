//  Created by Cao Trong Duy Nhan
//  Copyright © 2017 Duy Nhan Cao. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void swaps(double* a, double* b){
    double c;
    c = *a;
    *a = *b;
    *b = c;
}

void sort(double* x, int count){

    for(int i=0; i<count; i++){
        int min=i;
        for(int j=i; j<count; j++){
            if(x[j]<x[min])
                min=j;
        }
        swaps(&x[i], &x[min]);
    }
}

int main() {
    while(1){
        int front;
        scanf("%d", &front);
        if(front==0)
            break;
        int rear;
        scanf("%d", &rear);
        
        double* f = (double*)malloc(sizeof(double*)*front);
        double* r = (double*)malloc(sizeof(double*)*rear);
        double* d = (double*)malloc(sizeof(double*)*rear*front);
      
        int i;
        for(i=0; i<front; i++)
            scanf("%lf", &f[i]);
        for(i=0; i<rear; i++)
            scanf("%lf", &r[i]);
        
        for(i=0; i<rear; i++){
            for(int j=0; j<front; j++){
                d[i*front+j]=r[i]/f[j];
            }
        }
        
        sort(d, rear*front);
        
        double max=0;
        max=d[1]/d[0];
        for(i=2; i<rear*front; i++){
            if(d[i]/d[i-1]>max)
                max=d[i]/d[i-1];
        }
        free(r);
        free(f);
        free(d);
        
        printf("%.2f\n", max);
    }
    return 0;
}
