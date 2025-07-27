#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,m,res,cnt,dirx[4]={0,0,-1,1},diry[4]={-1,1,0,0},vis[1010][1010],sum;
string s[1010];
//bool check(int x,int y)
//{
//	for(int i=0;i<4;i++)
//	{
//		int dx=x+dirx[i],dy=y+diry[i];
//		if(dx>=0&&dx<n&&dy>=0&&dy<m&&s[dx][dy]=='#')
//		{
//			return true;
//		}
//	}
//	return false;
//}
int qmi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res%mod;
}
void bfs(int x,int y)
{
	queue<pair<int,int> >q;
	q.push({x,y});
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		int u=p.first,v=p.second;
		if(vis[u][v]) continue;
		vis[u][v]=cnt;
		for(int i=0;i<4;i++)
		{
			int dx=u+dirx[i],dy=v+diry[i];
			if(dx>=0&&dx<n&&dy>=0&&dy<m&&!vis[dx][dy]&&s[dx][dy]=='#')
			{
				q.push({dx,dy});
			}
		}
	}
}
int solve(int x,int y)
{
	set<int> st;
	for(int i=0;i<4;i++)
	{
		int dx=x+dirx[i],dy=y+diry[i];
		if(dx>=0&&dx<n&&dy>=0&&dy<m&&s[dx][dy]=='#')
		{
			st.insert(vis[dx][dy]);
		}
	}
	if(st.size()==0) return cnt+1;
	else if(st.size()==1) return cnt;
	else if(st.size()==2) return cnt-1;
	else if(st.size()==3) return cnt-2;
	else return cnt-3;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!vis[i][j]&&s[i][j]=='#')
			{
				cnt++;
				bfs(i,j);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='.')
			{
				res++;
				sum+=solve(i,j);
				sum%=mod;
			}
		}
	}
	cout<<(sum%mod*(qmi(res,mod-2)%mod)%mod)%mod;
	return 0;
}