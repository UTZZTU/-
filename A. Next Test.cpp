#include <bits/stdc++.h>
using namespace std;
int n,f[3010],p[3010];
set<int> st;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		p[f[i]]++;
	}
	for(int i=1;i<=3005;i++)
	{
		if(!p[i])
		{
			cout<<i<<endl;
			return;
		}
	}
//	cout<<st.size()<<endl;
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