#include<iostream>
using namespace std;
#define inf 1234567890
#define maxn 1005
int a[maxn][maxn],n,val[maxn][maxn],q,u,v;
char s[1010];
inline void floyd()
{
    for(int k=1;k<=n;k++)
	{
        for(int i=1;i<=n;i++)
		{
            if(i==k||a[i][k]==inf)
            {
                continue;
			}
			for(int j=1;j<=n;j++)
			{
				if(a[k][j]==inf||i==j||j==k)
				continue;
				if(a[i][j]>a[i][k]+a[k][j])
				{
					val[i][j]=val[i][k]+val[k][j]-val[k][k];
					a[i][j]=a[i][k]+a[k][j];
				}
				else if(a[i][j]==a[i][k]+a[k][j])
				{
					val[i][j]=max(val[i][j],val[i][k]+val[k][j]-val[k][k]);
				}
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>val[i][i];
	}
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
		{
            a[i][j]=inf;
        }
    }
    getchar();
    for(int i=1;i<=n;i++)
    {
    	cin>>s+1;
    	for(int j=1;j<=n;j++)
    	{
    		if(s[j]=='Y')
    		{
    			a[i][j]=1;
    			val[i][j]=val[i][i]+val[j][j];
			}
		}
	}
    floyd();
    cin>>q;
    while(q--)
    {
    	cin>>u>>v;
    	if(a[u][v]==inf)
    	{
    		cout<<"Impossible"<<endl;
		}
		else
		cout<<a[u][v]<<" "<<val[u][v]<<endl;
	}
    return 0;
}