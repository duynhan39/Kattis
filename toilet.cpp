//  Created by Cao Trong Duy Nhan
//  Copyright © 2017 Duy Nhan Cao. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    char string[1001];
    int encode[1001];
    
    scanf("%s", string);
    
    for(int i=0; i< strlen(string); i++){
        if(string[i]=='U')
            encode[i]=1;
        else encode[i]=-1;
    }
    
    int u=0;
    if(encode[0]*encode[1]<0)
        u++;
    if(encode[1]<0)
        u++;
    for(int i=2; i<strlen(string); i++){
        if (encode[i]<0)
            u+=2;
    }
    printf("%d\n", u);
    
    int d=0;
    if(encode[1]>0)
        d++;
    if(encode[0]*encode[1]<0)
        d++;
    for(int i=2; i<strlen(string); i++){
        if (encode[i]>0)
            d+=2;
    }
    printf("%d\n", d);
    
    int l=0;
    
    for(int i=1; i<strlen(string); i++){
        if (encode[i]*encode[i-1]<0)
            l+=1;
    }
    printf("%d\n", l);
    
    
    return 0;
}
