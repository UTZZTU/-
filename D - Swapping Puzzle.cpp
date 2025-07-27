#include <bits/stdc++.h>
using namespace std;
int n,m,f1[10][10],f2[10][10],p[10],q[10],minn;
void solve()
{
	cin>>n>>m;
	minn=0x3f3f3f3f;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++) q[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>f1[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>f2[i][j];
		}
	}
	do{
		do{
			int flag=1;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(f1[p[i]][q[j]]!=f2[i][j])
					{
						flag=0;
						break;
					}
				}
				if(!flag) break;
			}
			if(!flag) continue;
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(p[i]>p[j]) cnt++;
				}
			}
			for(int i=1;i<=m;i++)
			{
				for(int j=i+1;j<=m;j++)
				{
					if(q[i]>q[j]) cnt++;
				}
			}
			minn=min(minn,cnt);
		}while(next_permutation(q+1,q+1+m));
	}while(next_permutation(p+1,p+1+n));
	if(minn==0x3f3f3f3f) cout<<-1<<endl;
	else cout<<minn<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}