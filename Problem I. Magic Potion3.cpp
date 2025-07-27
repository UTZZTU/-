#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v;
int g[510][510],match[510],st[510];
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
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&u);
    	for(int j=1;j<=u;j++)
    	{
    		scanf("%d",&v);
    		g[i][v]=1;
		}
	}
    int res1=0,res2=0;
    for(int i=1;i<=n;i++)
    {
        memset(st,0,sizeof st);
        if(find(i)) res1++;
    }
    for(int i=1;i<=n;i++)
    {
        memset(st,0,sizeof st);
        if(find(i)) res2++;
    }
	cout<<res1+min(res2,k);
    return 0;
}