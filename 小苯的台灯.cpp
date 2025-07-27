#include <bits/stdc++.h>
using namespace std;
int cnt[4],n,k;
void solve()
{
	memset(cnt,0,sizeof(cnt));
	cin>>n>>k;
	if(!n)
	{
		cout<<0<<endl;
		return;
	}
	int pp=0;
	cnt[n]=1;
	while(1)
	{
		n=(n+k)%4;
		if(cnt[n])
		{
			cout<<-1<<endl;
			return;
		}
        cnt[n]=1;
		pp++;
		if(n==0) break;
//         cout<<n<<endl;
	}
	cout<<pp<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}