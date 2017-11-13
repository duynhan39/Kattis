#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin>>n;
    string in, guess;
    cin>>in;
    cin>>guess;
    
    int r=0, q=0;
    int check_in[50], check_guess[50];
    for(int i=0; i<50; i++)
    {
        check_in[i]=0;
        check_guess[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        if(in[i]==guess[i])
            r++;
        check_in[in[i]-'0']++;
        check_guess[guess[i]-'0']++;
    }
    for(int i=0; i<50; i++)
    {
        if(check_in[i]>check_guess[i])
            q+=check_guess[i];
        else
            q+=check_in[i];
    }
    q-=r; 
    cout<<r<<' '<<q<<endl;
    return 0;
}
