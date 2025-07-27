#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int maxx,minn,n,f[5010],l,tt;
int main ()
{
	cin>>l;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>f[i];
	for(int i=1;i<=n;i++)
	{
		tt=min(f[i],l+1-f[i]);
		maxx=max(maxx,tt);
	}
	for(int i=1;i<=n;i++)
	{
		tt=max(f[i],l+1-f[i]);
		minn=max(minn,tt);
	}
	cout<<maxx<<" "<<minn;
	return 0;
}