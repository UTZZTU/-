#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[1000100],cnt,q;
void solve()
{
	cin>>q;
	while(q--)
	{
		int op,x;
		cin>>op;
		if(op==1)
		{
			cin>>x;
			f[x]++;
			if(f[x]==1) cnt++;
		}
		else if(op==2)
		{
			cin>>x;
			f[x]--;
			if(f[x]==0) cnt--;
		}
		else cout<<cnt<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}