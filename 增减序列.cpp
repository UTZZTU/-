#include <bits/stdc++.h>
using namespace std;
int n,f[100010],cf[100010],ans1,ans2,ans,maxx;
map<int,int> mp;
int main ()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i];
        mp[f[i]]++;
        cf[i]=f[i]-f[i-1];
        if(cf[i]>0&&i!=1)
        ans1++;
        else if(cf[i]<0&&i!=1)
        ans2++;
    }
    cout<<min(ans1,ans2)<<endl;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->second==maxx)
        {
            ans++;
        }
        else
        {
            ans=1;
            maxx=it->second;
        }
    }
    cout<<ans<<endl;
    return 0;
}