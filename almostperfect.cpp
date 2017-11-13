#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int cal(const int x)
{
    int sum=1;
    int i;
    for(i=2; i< sqrt(x); i++)
        if(x%i==0)
        {
            sum+=i;
            sum+=x/i;
        }
    if(i==sqrt(x))
        sum+=i;
    return sum;
}
int main() {
    int x;
    while(cin>>x)
    {
        int k=cal(x);
        if(k==x)
        {
            cout<< x << " perfect\n";
            continue;
        }
        if(abs(x-k)<3)
        {
            cout<< x << " almost perfect\n";
        }
        else
            cout<< x << " not perfect\n";
    }
    return 0;
}
