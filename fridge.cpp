#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int arr[10];
    for(int i=0; i<10; i++)
        arr[i]=0;
    for(int i=0; i<input.size(); i++)
        arr[input[i]-'0']++;
    arr[0]++;
    
    int smallest=arr[0], num=0;
    for(int i=0; i<10; i++)
        if(arr[i]<smallest)
        {
            smallest=arr[i];
            num=i;
        }
    if(num==0)
    {
        cout << "1";
        for(int i=0; i<smallest; i++)
            cout << "0";
    }
    else
    for(int i=0; i<smallest+1; i++)
        cout << num;
    
    cout << endl;
    return 0;
}
