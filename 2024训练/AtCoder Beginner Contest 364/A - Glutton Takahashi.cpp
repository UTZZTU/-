#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,flag,cnt;
string s;
void solve()
{
	cin>>n;
	flag=n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s=="sweet") cnt++;
		else cnt=0;
		if(cnt>=2&&flag==n) flag=i;
	}
	if(flag<n) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
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