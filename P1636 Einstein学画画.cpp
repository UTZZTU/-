#include <bits/stdc++.h>
using namespace std;
int ans,cnt[1010],n,m;
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		cnt[x]++;
		cnt[y]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]&1)
		ans++;
	}
	ans/=2;
	if(ans)
	cout<<ans;
	else
	cout<<1;
	return 0;
}