#include <iostream>
#include <string>

using namespace std;

typedef struct{
    int x;
    int y;
} point_t;

int main() {
    string board[1000];
    int i=0;
    point_t points[150];
    while(getline(cin,board[i]))
    {
        i++;
        while(getline(cin,board[i]))
        {
            if(board[i]=="")
                break;
            i++;
        }
        int max=0;
        //count = i-count;
        for(int index=0; index<i; index++)
        {
            for(int j=0; j<board[index].size(); j++)
                if(board[index][j]!='.')
                {
                    int n=board[index][j]-'0';
                    if(n>48&&n<75)
                        n-=39;
                    else if(n>16&&n<43)
                        n+=19;
                    if(n>max)
                        max=n;
                    points[n].x=j;
                    points[n].y=index;
                }
        }
        int a,b;
        for(int k=1; k<=max; k++)
        {
            int p=k-1;
            
            if(points[k].x==points[p].x)
            {
                if(points[k].y>points[p].y)
                {
                    b=points[k].y;
                    a=points[p].y;
                } else
                {
                    a=points[k].y;
                    b=points[p].y;
                }
                int j=0;
                for(j=a+1; j<b; j++)
                {
                    if(isdigit(board[j][points[k].x])||
                       isalpha(board[j][points[k].x])||
                       board[j][points[k].x]=='+')
                        continue;
                    else if(board[j][points[k].x]=='-')
                        board[j][points[k].x]='+';
                    else
                        board[j][points[k].x]='|';
                }
            } else {
                if(points[k].x>points[p].x)
                {
                    b=points[k].x;
                    a=points[p].x;
                } else
                {
                    a=points[k].x;
                    b=points[p].x;
                }
                int j=0;
                for(j=a+1; j<b; j++)
                {
                    if(isdigit(board[points[k].y][j])||
                       isalpha(board[points[k].y][j])||
                       board[points[k].y][j]=='+')
                        continue;
                    else if(board[points[k].y][j]=='|')
                        board[points[k].y][j]='+';
                    else
                        board[points[k].y][j]='-';
                }
            }
        }
        for(int k=0; k<i; k++)
            cout << board[k] << endl;
        cout << endl;
        i=0;
    }
    return 0;
}
