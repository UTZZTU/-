#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;
int main ()
{
    map<string,int> mp;
    int n,m,i,q1=1,q2,pd=0;
    string k1,k2,k3;
    scanf("%d%d",&n,&m);
    q2=n;
    for(i=0;i<m;i++)
    {
        cin>>k1;
        cin>>k2;
        k1+=k2;
        mp[k1]=1;
    }
    for(i=2;i<n;i++)
    {
        k1=to_string(q1);
        k2=to_string(i);
        k1+=k2;
        k3=to_string(q2);
        k2+=k3;
        if(mp[k1]==1&&mp[k2]==1)
        {
            pd=1;
            break;
        }
    }
    if(pd==0)
    printf("IMPOSSIBLE");
    else
    printf("POSSIBLE");
    return 0;
}