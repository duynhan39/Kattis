//  backspace
//
//  Created by Cao Trong Duy Nhan on 9/7/17.
//  Copyright © 2017 Duy Nhan Cao. All rights reserved.
//

#include <iostream>

using namespace std;
int main()
{
    string input, output_rev, output;
    cin >> input;
    int n=0;
    for(int i=input.size()-1; i>=0; i--)
    {
        if(input[i]=='<')
            n++;
        else
        {
            if(n>0)
            {
                n--;
                continue;
            }
            else
                output_rev += input[i];
        }
    }
    for(int i=output_rev.size()-1; i>=0; i--)
    {
        output += output_rev[i];
    }
    cout << output << endl;
    return 0;
}
