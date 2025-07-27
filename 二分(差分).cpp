#include<bits/stdc++.h>
using namespace std;
const int inf=INT_MAX;//int型数据最大值，因为是对每个数进行统计
int n,a[1000000],max1=0,sum[10000000];
map<int,int> M;//数据过大，数组存不下，并且数据还可为负
char s[1000000];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i]>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='.') {M[a[i]]++,M[a[i]+1]--;}
        if(s[i]=='+'){M[a[i]]--,M[-inf]++;}
        if(s[i]=='-'){M[inf]--,M[a[i]+1]++;}
    }
    int ans=-inf,h=0;
    for(auto x:M)
    {
        h+=x.second;
        ans=max(h,ans);
    }
    cout<<ans;
}