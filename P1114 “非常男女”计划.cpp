#include<bits/stdc++.h>
using namespace std;
int n,x,s[101000];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x); 
        if(x==1) s[i]=s[i-1]+1; else s[i]=s[i-1]-1;
    }
    int ma=0;
    for(int i=1; i<=n-1; i++)
      for(int j=i+ma; j<=n; j++) if(s[j]-s[i-1]==0) ma=j-i+1;
    cout<<ma;
    return 0;
 }