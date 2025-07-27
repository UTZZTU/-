#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
pair<int,int> P[N];
int f[N*2],t,n,m,cnt;
//struct node
//{
//	int l,r;
//	int cnt,maxx;
//}tr[N * 4];
//int t,n,m,cnt,f[N*2];
//void push_up(int x)
//{
//	tr[x].maxx=max(tr[x<<1].maxx,tr[x<<1|1].maxx);
//}
//void push_down()
//{
//	
//}
//void build()
//{
//	
//}
//void modify()
//{
//	
//}
//int query()
//{
//	
//}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		cnt=1;
		map<int,int> mp;
		set<int> st;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&P[i].first,&P[i].second);
			st.insert(P[i].first);
			st.insert(P[i].second);
		}
		if(m==1) puts("0");
		else
		{
			for(auto &x:st)
			{
				f[cnt]=0;
				mp[x]=cnt++;
			}
//			build()
			for(int i=1;i<=n;i++)
			{
				int u=P[i].first,v=P[i].second;
				f[mp[u]]++;
				f[mp[v]+1]--;
			}
			int res=0,maxx=0;
			for(int i=1;i<cnt;i++)
			{
				res+=f[i];
				maxx=max(maxx,res);
			}
			printf("%d\n",maxx);
		}
	}
	return 0;
}
