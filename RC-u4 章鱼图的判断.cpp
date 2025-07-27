#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt,num,vis[100010],n,m;
vector<int> vec[100010];
void dfs(int now,int len,int pre)
{
	vis[now]=1;
	cout<<now<<" "<<pre<<" "<<len<<endl;
	for(auto c:vec[now])
	{
		if(!vis[c])
		{
			dfs(c,len+1,now);
		}
		else if(c!=pre)
		{
			cout<<"wocao "<<c<<endl;
			cnt++;
			num=len;
		}
	}
}
void solve()
{
	cnt=num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		vec[i].clear();
		vis[i]=0;
		cnt=0;
	}
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i,1,-1);
		}
	}
	if(cnt!=1)
	{
		cout<<"No "<<cnt<<endl;
	}
	else
	{
		cout<<"Yes "<<num<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
