#include <bits/stdc++.h>
using namespace std;
int n,w,h,cnt,u,v,dp[5010],fa[5010];
struct node
{
	int w,h;
	int pos;
}s[5010];
bool cmp(node x,node y)
{
	if(x.w!=y.w) return x.w<y.w;
	else return x.h<y.h;
}
void solve()
{
	cin>>n>>w>>h;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v;
		if(u<=w||v<=h) continue;
		s[++cnt].w=u,s[cnt].h=v;
		s[cnt].pos=i;
	}
	if(cnt==0)
	{
		cout<<0<<endl;
		return;
	}
	sort(s+1,s+1+cnt,cmp);
	for(int i=1;i<=5000;i++) fa[i]=i;
	for(int i=1;i<=5000;i++)
	{
		dp[i]=1;
	}
	for(int i=1;i<=cnt;i++)
	{
		for(int j=i+1;j<=cnt;j++)
		{
			if(s[j].w<=s[i].w||s[j].h<=s[i].h) continue;
			if(dp[i]+1>dp[j])
			{
				dp[j]=dp[i]+1;
				fa[s[j].pos]=s[i].pos;
			}
		}
	}
	int maxx=0,pos=-1;
	for(int i=1;i<=cnt;i++)
	{
		if(dp[i]>maxx)
		{
			maxx=dp[i];
			pos=s[i].pos;
		}
	}
	vector<int> vec;
	while(fa[pos]!=pos)
	{
		vec.push_back(pos);
		pos=fa[pos];
	}
	vec.push_back(pos);
	reverse(vec.begin(),vec.end());
	cout<<maxx<<endl;
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}