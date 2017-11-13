//  Created by Cao Trong Duy Nhan on 8/30/17.
//  Copyright © 2017 Duy Nhan Cao. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int r, n;
    cin >> r >> n;
    
    int rooms[r];
    
    for(int i=0; i<r; i++)
        rooms[i]=0;
    
    for(int i=0; i<n; i++)
    {
        int k;
        cin >> k;
        rooms[k-1]=1;
        
    }
    
    for(int i=0; i<r; i++)
        if(rooms[i]==0){
            cout << i+1 << endl;
            return 0;
        }
    
    cout << "too late" << endl;
    
    
    return 0;
}
