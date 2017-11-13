//  Cryptographer's Conundrum
//
//  Created by Cao Trong Duy Nhan on 8/30/17.
//  Copyright © 2017 Duy Nhan Cao. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;
    int count=0;
    
    for(int i=1; i<input.length()-1; i+=3){
        if(input[i-1]=='P')
            count++;
        if(input[i]=='E')
            count++;
        if(input[i+1]=='R')
            count++;
    }
    cout << input.length()-count <<endl;
    return 0;
}
