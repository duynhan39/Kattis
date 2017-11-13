#include <iostream>
#include <vector>

using namespace std;

typedef struct { int f=0; vector<int> nei; } Node;

int main() {
    int n, m;
    cin>>n>>m;
    vector<Node> list(n+1);
    vector<int> been(n+1,0), thro, rest(n+1,0);
    for(int i=0; i<m; i++)
    {
        int num, neigh;
        cin>>num>>neigh;
        if(num>0)
            list[num].nei.push_back(neigh);
        else
            list[-num].f=neigh;
    }
    int k=1;
    while(1)
    {
        if(been[k]!=0)
            break;
        thro.push_back(k);
        if(list[k].f==0)
        {
            rest[k]++;
            break;
        }
        been[k]++;
        k=list[k].f;
    }
    for(int i=0; i<thro.size(); i++)
        for(int j=0; j<list[thro[i]].nei.size(); j++)
        {
            k=list[thro[i]].nei[j];
            vector<int> beenNei(n+1,0);
            while(1)
            {
                if(beenNei[k]!=0)
                    break;
                if(list[k].f==0)
                {
                    rest[k]++;
                    break;
                }
                beenNei[k]++;
                k=list[k].f;
            }
        }
    int total=0;
    for(int i=1; i<=n; i++)
        if(rest[i]!=0)
            total++;
    cout<<total<<endl;
    
    return 0;
}
