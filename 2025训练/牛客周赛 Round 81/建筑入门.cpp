#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,k,sum,p[55],flag,pp[55],f[55][1000010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		sum+=i*i;
		pp[i]=i;
		p[i]=1;
	}
	for(int i=n-1;i>=1;i--)
	{
		pp[i]+=pp[i+1];
	}
	if(sum>k)
	{
		cout<<-1<<endl;
	}
	else
	{
		k-=sum;
//		cout<<k<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
			{
				f[i][j]=f[i-1][j];
				if(j>=pp[i])
				{
					f[i][j]=max(f[i][j],f[i][j-pp[i]]+pp[i]);
//					cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
				}
			}
		}
		if(f[n][k]!=k)
		{
			cout<<-1<<endl;
		}
		else
		{
			int u=n,v=k;
			while(u>0&&v>0)
			{
				if(f[u][v]==f[u][v-pp[u]]+pp[u])
				{
					v-=pp[u];
					p[u]++;
				}
				else u--;
			}
			int res=0;
			for(int i=1;i<=n;i++)
			{
				res+=p[i];
				cout<<res<<" ";
			}
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}