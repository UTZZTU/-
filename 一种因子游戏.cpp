#include <bits/stdc++.h>
using namespace std;
int n,m;
int g[510][510],match[510],st[510],a[510],b[510];
bool find(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(!st[i]&&g[x][i])
        {
            st[i]=1;
            if(!match[i]||find(match[i]))
            {
                match[i]=x;
                return true;
            }
        }
    }
    return false;
}
int main ()
{
    cin>>n;
    m=n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(__gcd(b[i],a[j])==1)
			{
				g[i][j]=1;
			}
		}
	}
//    for(int i=1,x,k;i<=n;i++)
//    {
//        cin>>k;
//        while(k--)
//        {
//            cin>>x;
//            g[i][x]=1;
//        }
//    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        memset(st,0,sizeof st);
        if(find(i)) res++;
    }
    if(res==n)
    {
    	puts("Bob");
	}
	else puts("Alice");
    return 0;
}