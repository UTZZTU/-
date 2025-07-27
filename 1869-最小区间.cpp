#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
unordered_map<int,int> mp;
set<int> st;
pair<int,int> p[50010];
int n;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].fi,&p[i].se);
		st.insert(p[i].se);
	}
	sort(p+1,p+1+n);
	int l=1,r=1,res=1e9,now=0;
	while(l<=n)
	{
		while(r<=n&&now!=st.size())
		{
			if(mp[p[r++].se]++ == 0)
			{
				now++;
			}
		}
		if(now==st.size()) res=min(res,p[r-1].fi-p[l].fi);
		if(--mp[p[l++].se]==0) now--;
	}
	cout<<res;
	return 0;
}