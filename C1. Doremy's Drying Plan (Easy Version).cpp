#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,cf[200010],f[200010],f0[200010],f1[200010],cnt0,l[200010],r[200010],maxx,cnt;
struct node
{
	int pos,w,idx;
	inline bool operator<(const node &x)const
	{
		return pos<x.pos;
	}
}s[500010];
//bool cmp(node x,node y)
//{
//	return x.pos<y.pos;
//}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		vector<node> vec;
		maxx=0;
		priority_queue<int> q;
		map<pair<int,int>,int> mp;
		set<int> st;
		scanf("%d%d%d",&n,&m,&k);
		cf[0]=0;
		for(int i=1;i<=n;i++)
		{
			cf[i]=f[i]=f0[i]=f1[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
			cf[l[i]]++;
			cf[r[i]+1]--;
			vec.push_back({l[i],1,i});
			vec.push_back({r[i]+1,-1,i});
		}
		sort(vec.begin(),vec.end());
		for(int i=1;i<=n;i++)
		{
			f[i]=f[i-1]+cf[i];
			f0[i]=f0[i-1]+(f[i]==0);
			f1[i]=f1[i-1]+(f[i]==1);
		}
		cnt0=f0[n];
		for(int i=1;i<=m;i++)
		{
			q.push(f1[r[i]]-f1[l[i]-1]);
		}
		int uu=0;
		maxx=cnt0;
		while(uu<2&&q.size())
		{
			maxx+=q.top();
			q.pop();
			uu++;
		}
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			while(cnt<vec.size()&&vec[cnt].pos==i)
			{
				if(vec[cnt].w==1)
				{
					st.insert(vec[cnt].idx);
				}
				else
				{
					st.erase(vec[cnt].idx);
				}
				cnt++;
			}
			if(st.size()==2)
			{
				int pre=*st.begin(),post=*st.rbegin();
				if(pre>post) swap(pre,post);
				mp[{pre,post}]++;
			}
		}
		for(auto &x:mp)
		{
			int xx=x.first.first,yy=x.first.second;
			maxx=max(maxx,cnt0+f1[r[xx]]+f1[r[yy]]-f1[l[xx]-1]-f1[l[yy]-1]+x.second);
		}
		printf("%d\n",maxx);
	}
	return 0;
}