#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long a[n];
    for(int i_1=0; i_1<n; i_1++)
    {
        cin >> a[i_1];
        if(i_1>1)
        {
            for(int i_2=1; i_2<i_1; i_2++)
            {
                for(int i_3=0; i_3<i_2; i_3++)
                {
                    if(a[i_1]>abs(a[i_2]-a[i_3]) && a[i_1]<(a[i_2]+a[i_3]))
                    {
                        cout << "possible" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << "impossible" << endl;
    return 0;
}
