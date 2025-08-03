#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,f[200010];
void solve()
{
	cin>>l>>r;
	cout<<f[r]-f[l-1]+f[l]-f[l-1]<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=200000;i++)
	{
		int cnt=0,j=i;
		while(j)
		{
			j/=3;
			cnt++;
		}
		f[i]=cnt;
		f[i]+=f[i-1];
//		cout<<cnt<<endl;
	}
//	cout<<f[199999]-f[199998]<<endl;
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}