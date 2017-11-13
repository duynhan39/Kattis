//  completingthesquare
//
//  Created by Cao Trong Duy Nhan on 9/6/17.
//  Copyright © 2017 Duy Nhan Cao. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

typedef struct{
    int p1;
    int p2;
} point_t;

int main()
{
    point_t A, B, C;
    point_t X_1, X_2, X_3, X_4;
    cin >> A.p1 >> A.p2 >> B.p1 >> B.p2 >> C.p1 >> C.p2;
    
    //Comparing AC and AB
    int ac_s = pow(A.p1-C.p1, 2) + pow(A.p2-C.p2, 2);
    int ab_s = pow(A.p1-B.p1, 2) + pow(A.p2-B.p2, 2);
    
    if(ac_s>ab_s)
    {
        X_2=B;
        X_1=C;
        X_3=A;
    }
    if(ab_s>ac_s)
    {
        X_1=B;
        X_2=C;
        X_3=A;
    }
    if(ab_s==ac_s)
    {
        X_2=A;
        X_1=B;
        X_3=C;
    }
    X_4.p1=X_3.p1-X_2.p1+X_1.p1;
    X_4.p2=X_3.p2-X_2.p2+X_1.p2;
    
    cout << X_4.p1 << " " << X_4.p2 << endl;
    
    return 0;
}
