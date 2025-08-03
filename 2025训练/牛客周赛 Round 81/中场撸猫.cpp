#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,b[1010][1010],f[1010],g[1010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
		}
		sort(b[i]+1,b[i]+1+n);
	}
	int level=1,cnt,sum,ne=2;
	f[1]=b[1][1];
	while(1)
	{
		cnt=1,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt==1)
			{
				if(b[ne][i]>=f[cnt])
				{
					g[cnt]=b[ne][i];
					sum++;
					cnt++;
				}
			}
			else
			{
				if(cnt>ne)
				{
					break;
				}
				else if(cnt<ne)
				{
					if(b[ne][i]>=f[cnt-1]&&b[ne][i]>=f[cnt])
					{
						g[cnt]=b[ne][i];
						sum++;
						cnt++;
					}
				}
				else if(cnt==ne)
				{
					if(b[ne][i]>=f[cnt-1])
					{
						g[cnt]=b[ne][i];
						sum++;
						cnt++;
					}
				}
			}
		}
		if(sum==ne)
		{
			level++,ne++;
			for(int i=1;i<=ne-1;i++)
			{
				f[i]=g[i];
			}
		}
		else break;
	}
	cout<<level<<endl;
	
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}