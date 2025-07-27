#include <bits/stdc++.h>
using namespace std;

int xx[] = {-1,-1,-1, 1,1,1,0, 0};
int yy[] = {-1, 0, 1,-1,0,1,1,-1};
char mmp[10][10];
int fff[2][10][10];
void move(int x, int y, int p)
{
    char ch;
    if(p == 0)
        ch = 'W';
    else
        ch = 'B';
    mmp[x][y] = ch;
    for(int i=0; i<8; i++)
    {
        if(fff[p][x][y] & 1<<i)
        {
            int tx = x-xx[i];
            int ty = y-yy[i];
            while(tx>=0 && ty>=0
                    && tx<8 && ty<8
                    && mmp[tx][ty] != ch)
            {
                mmp[tx][ty] = ch;
                tx -= xx[i];
                ty -= yy[i];
            }
        }
    }
}
int Print(bool isp, int p)
{
    bool flag = false;
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            if(fff[p][i][j])
            {
                if(flag && isp)
                    cout<<" ";
                flag = true;
                if(isp)
                    cout<<'('<<i+1<<','<<j+1<<")";
                else
                    return flag;
            }
    if(isp)
    {
        if(flag)
            cout<<endl;
        else
            cout<<"No legal move."<<endl;
    }
    return flag;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        memset(mmp, 0, sizeof(mmp));
        for(int i=0; i<8; i++)
            cin>>mmp[i];
        char ch[5];
        int p;
        cin>>ch;
        if(ch[0] == 'W')
            p = 0;
        else
            p = 1;
        while(ch[0] != 'Q')
        {
            memset(fff, 0, sizeof(fff));
            for(int i=0; i<8; i++)
            {
                for(int j=0; j<8; j++)
                    if(mmp[i][j] == 'W')
                    {
                        for(int k=0; k<8; k++)
                        {
                            int tx = i+xx[k];
                            int ty = j+yy[k];
                            int num = 0;
                            while(tx>=0 && ty>=0
                                    && tx<8 && ty<8
                                    && mmp[tx][ty] == 'B')
                            {
                                tx += xx[k];
                                ty += yy[k];
                                ++num;
                            }
                            if(num>=1 && mmp[tx][ty] == '-')
                                fff[0][tx][ty] |= 1<<k;
                        }
                    }
                    else if(mmp[i][j] == 'B')
                    {
                        for(int k=0; k<8; k++)
                        {
                            int tx = i+xx[k];
                            int ty = j+yy[k];
                            int num = 0;
                            while(tx>=0 && ty>=0
                                    && tx<8 && ty<8
                                    && mmp[tx][ty] == 'W')
                            {
                                tx += xx[k];
                                ty += yy[k];
                                ++num;
                            }
                            if(num>=1 && mmp[tx][ty] == '-')
                                fff[1][tx][ty] |= 1<<k;
                        }
                    }
            }
            cin>>ch;
            if(ch[0] == 'L')
                Print(true, p);
            else if(ch[0] == 'M')
            {
                if(!Print(false, p))
                    p ^= 1;
                move(ch[1]-'0'-1, ch[2]-'0'-1, p);
                p ^= 1;
                int wnum = 0;
                int bnum = 0;
                for(int i=0; i<8; i++)
                    for(int j=0; j<8; j++)
                    {
                        if(mmp[i][j] == 'W')
                            ++wnum;
                        if(mmp[i][j] == 'B')
                            ++bnum;
                    }
                printf("Black - %2d White - %2d\n", bnum, wnum);
            }
        }
        for(int i=0; i<8; i++)
            cout<<mmp[i]<<endl;
        if(n != 0)
            cout<<endl;
    }
    return 0;
}