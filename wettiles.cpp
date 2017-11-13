#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

typedef struct {int x; int y;} Point;
int mark(vector<string> &grid, Point p, vector<Point> &list, int x_0, int y_0);

int main()
{
    int x_0, y_0, t,l,w;
    while(1)
    {
        cin>>x_0;
        if(x_0==-1)
            break;
        cin>>y_0>>t>>l>>w;
        string oneLine(x_0, '0');
        vector<string> grid(y_0, oneLine);
        
        vector<Point> leak(l);
        for(int i=0; i<l; i++)
        {
            cin>>leak[i].x>>leak[i].y;
            grid[leak[i].y-1][leak[i].x-1]++;
        }
        vector<Point> wall(w*2);
        for(int i=0; i<w*2; i++)
        {
            cin>>wall[i].x>>wall[i].y;
            if(i%2!=0)
            {
                if(wall[i].x==wall[i-1].x)
                    for(auto j=min(wall[i].y,wall[i-1].y); j<=max(wall[i].y,wall[i-1].y); j++)
                        grid[j-1][wall[i].x-1]='w';
                else if(wall[i].y==wall[i-1].y)
                    for(auto j=min(wall[i].x,wall[i-1].x); j<=max(wall[i].x,wall[i-1].x); j++)
                    {
                        grid[wall[i].y-1][j-1]='w';
                    }
                else
                {
                    if((wall[i].x-wall[i-1].x)*(wall[i].y-wall[i-1].y)>0)
                        for(int j=0; j<=abs(wall[i].x-wall[i-1].x); j++)
                            grid[min(wall[i].y,wall[i-1].y)-1+j][min(wall[i].x,wall[i-1].x)+j-1]='w';
                    else
                        for(int j=0; j<=abs(wall[i].x-wall[i-1].x); j++)
                        {
                            grid[min(wall[i].y,wall[i-1].y)-1+j][max(wall[i].x,wall[i-1].x)-j-1]='w';
                        }
                }
            }
        }
        int total=0;
        vector<Point> list(leak);
        for(int i=0; i<t-1; i++)
        {
            
            vector<Point> list_2;
            for(auto j=0; j<list.size(); j++)
            {
                total+=mark(grid, list[j], list_2, x_0, y_0);
            }
            if(list_2.empty())
                break;
            list=list_2;
            list_2.clear();
        }
        total+=l;
        cout<<total<<endl;
    }
    return 0;
}
int mark(vector<string> &grid, Point p, vector<Point> &list, int x_0, int y_0)
{
    int count=0;
    Point em;
    if((p.x+1<=x_0) && grid[p.y-1][p.x]=='0')
    {
        grid[p.y-1][p.x]++;
        count++;
        em.x=p.x+1;
        em.y=p.y;
        list.insert(list.end(), em);
    }
    if((p.x-1>=1)&&grid[p.y-1][p.x-2]=='0')
    {
        grid[p.y-1][p.x-2]++;
        count++;
        em.x=p.x-1;
        em.y=p.y;
        list.insert(list.end(), em);
    }
    if((p.y+1<=y_0)&&grid[p.y][p.x-1]=='0')
    {
        grid[p.y][p.x-1]++;
        count++;
        em.x=p.x;
        em.y=p.y+1;
        list.insert(list.end(), em);
    }
    if((p.y-1>=1)&&grid[p.y-2][p.x-1]=='0')
    {
        grid[p.y-2][p.x-1]++;
        count++;
        em.x=p.x;
        em.y=p.y-1;
        list.insert(list.end(), em);
    }
    return count;
}
