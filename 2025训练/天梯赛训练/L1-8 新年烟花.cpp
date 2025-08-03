#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,m,h,f[101][101],px,py,maxx,num;
void solve()
{
	cin>>n>>m>>h;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>f[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(f[i][j]==0)
			{
				int cnt=0;
				for(int k=j;k>=1;k--)
				{
					if(f[i][k]>=h) break;
					else if(f[i][k]<0) cnt++;
				}
				for(int k=j;k<=m;k++)
				{
					if(f[i][k]>=h) break;
					else if(f[i][k]<0) cnt++;
				}
				for(int k=i;k>=1;k--)
				{
					if(f[k][j]>=h) break;
					else if(f[k][j]<0) cnt++;
				}
				for(int k=i;k<=n;k++)
				{
					if(f[k][j]>=h) break;
					else if(f[k][j]<0) cnt++;
				}
				if(cnt>maxx)
				{
					maxx=cnt;
					px=i;
					py=j;
				}
				if(cnt>=3) num++;
			}
		}
	}
	cout<<num<<endl;
	cout<<px-1<<" "<<py-1;
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