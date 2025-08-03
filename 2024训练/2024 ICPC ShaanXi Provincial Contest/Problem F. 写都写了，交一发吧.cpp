#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,g[200010],maxx;
void solve()
{
//	maxx=0;
//	cin>>n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
//		cin>>g[i];
		scanf("%d",&g[i]);
//		maxx=max(maxx,g[i]);
	}
	sort(g+1,g+1+n);
//	cout<<maxx<<endl;
	printf("%d\n",g[n]);
}
int main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int _=1;
//	cin>>_;
	scanf("%d",&_);
	while(_--)
	{
		solve();
	}	
	return 0;
}