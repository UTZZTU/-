#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v;
int g1[510][510],match1[510],st1[510],f[510][510],t[510],g2[510][510],match2[510],st2[510];
bool find1(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(!st1[i]&&g1[x][i])
        {
            st1[i]=1;
            if(!match1[i]||find1(match1[i]))
            {
                match1[i]=x;
//                g[x][i]=0;
                return true;
            }
        }
    }
    return false;
}
bool find2(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(!st2[i]&&g2[x][i])
        {
            st2[i]=1;
            if(!match2[i]||find2(match2[i]))
            {
                match2[i]=x;
//                g[x][i]=0;
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
    	t[i]=u;
    	for(int j=1;j<=u;j++)
    	{
    		scanf("%d",&v);
    		g1[i][v]=1;
    		f[i][j]=v;
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
    int res1=0,res2=0;
    for(int i=1;i<=n;i++)
    {
        memset(st1,0,sizeof st1);
        if(find1(i)) res1++;
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=t[i];j++)
    	{
    		if(!match1[f[i][j]])
    		{
    			g2[i][f[i][j]]=1;
			}
		}
	}
    for(int i=1;i<=n;i++)
    {
    	memset(st2,0,sizeof st2);
    	if(find2(i)) res2++;
	}
	cout<<res1+min(res2,k)<<endl;
    return 0;
}