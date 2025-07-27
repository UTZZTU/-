#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[1010][1010],u;
ll n,l,r,res,x,y,vis[1010];
vector<int> vec[1010];
void dfs(int level,ll num,ll fa)
{
//	vis[level]=1;
	num=num*2+(u[level-1]-'0');
	if(fa!=-1&&num>=l&&num<=r) res++;
	if(num>r) return;
	for(int i=0;i<vec[level].size();i++)
	{
		int j=vec[level][i];
		if(j==fa) continue;
		dfs(j,num,level);
	}
}
int main ()
{
	scanf("%d%lld%lld",&n,&l,&r);
	getchar();
	cin>>u;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,(ll)0,(ll)-1);
//		memset(vis,0,sizeof(vis));
	}
	cout<<res;
	return 0;
}