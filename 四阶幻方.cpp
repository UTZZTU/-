#include<bits/stdc++.h>
using namespace std;
int a[17] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int ans;
bool check()
{
    if(34 != a[13]+a[14]+a[15]+a[16]) return false;
    
    for(int i=0;i<4;i++)
    {
        if(a[1+i]+a[5+i]+a[i+9]+a[i+13] !=34) return false;
    }
    if(a[1]+a[6]+a[11]+a[16]!=34 || 34!=a[4]+a[7]+a[10]+a[13]) return false;
    return true;
}
void dfs(int s, int t)
{
    if(s==t&&check())
    {
        ans++;
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                cout<<a[i+4*(j-1)]<<' ';
            }
            cout<<endl; 
        }
        cout<<endl;
        return;
    }
    if(s==5 && a[1]+a[2]+a[3]+a[4]!=34) return;
    if(s==9 && 34 != a[5]+a[6]+a[7]+a[8]) return;
    if(s==13 && a[9]+a[10]+a[11]+a[12] != 34) return;
    for(int i=s;i<=t;i++)
    {
        swap(a[s], a[i]);
        dfs(s+1,t);
        swap(a[s],a[i]);
    }
}
int main(int argc, char *argv[])
{
    dfs(2,16);
    cout<<ans;
    return 0;
}
