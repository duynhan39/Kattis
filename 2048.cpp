//  Created by Cao Trong Duy Nhan on 9/7/17.
//  Copyright © 2017 Duy Nhan Cao. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int inDis[4][4];
    int outDis[4][4];
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            cin >> inDis[i][j];
            outDis[i][j]=0;
        }
    int dir;
    cin >> dir;
    int tem, x;
    switch(dir){
        case 0:
            for(int i=0; i<4; i++)
            {
                tem=-1;
                x=0;
                for(int j=0; j<4; j++)
                {
                    if(inDis[i][j]!=0)
                    {
                        if(inDis[i][j]==tem)
                        {
                            outDis[i][x]=2*tem;
                            x++;
                            tem=-1;
                        }
                        else
                        {
                            if(tem!=-1)
                            {
                                outDis[i][x]=tem;
                                x++;
                            }
                            tem=inDis[i][j];
                        }
                    }
                }
                if(tem!=-1)
                    outDis[i][x]=tem;
            }
            break;
        case 1:
            for(int i=0; i<4; i++)
            {
                tem=-1;
                x=0;
                for(int j=0; j<4; j++)
                {
                    if(inDis[j][i]!=0)
                    {
                        if(inDis[j][i]==tem)
                        {
                            outDis[x][i]=2*tem;
                            x++;
                            tem=-1;
                        }
                        else
                        {
                            if(tem!=-1)
                            {
                                outDis[x][i]=tem;
                                x++;
                            }
                            tem=inDis[j][i];
                        }
                    }
                }
                if(tem!=-1)
                    outDis[x][i]=tem;
            }
            break;
        case 2:
            for(int i=0; i<4; i++)
            {
                tem=-1;
                x=3;
                for(int j=3; j>=0; j--)
                {
                    if(inDis[i][j]!=0)
                    {
                        if(inDis[i][j]==tem)
                        {
                            outDis[i][x]=2*tem;
                            x--;
                            tem=-1;
                        }
                        else
                        {
                            if(tem!=-1)
                            {
                                outDis[i][x]=tem;
                                x--;
                            }
                            tem=inDis[i][j];
                        }
                    }
                }
                if(tem!=-1)
                    outDis[i][x]=tem;
            }
            break;
        case 3:
            for(int i=0; i<4; i++)
            {
                tem=-1;
                x=3;
                for(int j=3; j>=0; j--)
                {
                    if(inDis[j][i]!=0)
                    {
                        if(inDis[j][i]==tem)
                        {
                            outDis[x][i]=2*tem;
                            x--;
                            tem=-1;
                        }
                        else
                        {
                            if(tem!=-1)
                            {
                                outDis[x][i]=tem;
                                x--;
                            }
                            tem=inDis[j][i];
                        }
                    }
                }
                if(tem!=-1)
                    outDis[x][i]=tem;
            }
            break;  
    }
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << outDis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
