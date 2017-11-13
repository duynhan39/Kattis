#include <iostream>
#include <math.h>

using namespace std;

double dist(double a[], double b[]);

int main() {
    double l, w, r;
    int n;
    cin >> l >> w >> n >> r;
    
    double arr[n][2];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    int list[5][n+1];
    double A[2]={-l/2, 0},
           B[2]={l/2, 0},
           C[2]={0, -w/2},
           D[2]={0, w/2};
    //Fill the chart
    for(int i=0; i<n+1; i++)
        for(int j=0; j<5; j++)
            list[j][i]=0;
    //Find intersections
    int max=0;
    for(int i=0; i<n; i++)
    {
        if(dist(A, arr[i])<=r)
        {
            list[0][i]=1;
            list[4][i]++;
            list[0][n]++;
        }
        if(dist(B, arr[i])<=r)
        {
            list[1][i]=1;
            list[4][i]++;
            list[1][n]++;
        }
        if(dist(C, arr[i])<=r)
        {
            list[2][i]=1;
            list[4][i]++;
            list[2][n]++;
        }
        if(dist(D, arr[i])<=r)
        {
            list[3][i]=1;
            list[4][i]++;
            list[3][n]++;
        }
        if(list[4][i]>max)
            max=list[4][i];
    }
    for(int i=0; i<4; i++)
        if(list[i][n]==0)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    if(max==4||max==3||max==1)
    {
        cout << 5-max << endl;
        return 0;
    }
    else
    {
        for(int i=0; i<n; i++)
            if(list[4][i]==2)
                for(int j=i+1; j<n; j++)
                {
                    if(list[0][i]+list[0][j]!=0 &&
                       list[1][i]+list[1][j]!=0 &&
                       list[2][i]+list[2][j]!=0 &&
                       list[3][i]+list[3][j]!=0)
                    {
                        cout << "2" << endl;
                        return 0;
                    }
                } 
    }
    cout << "3" << endl;
    return 0;
}

double dist(double a[], double b[])
{
    return sqrt(pow((a[0]-b[0]), 2)+pow((a[1]-b[1]), 2));
}
