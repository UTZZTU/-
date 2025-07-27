#include <bits/stdc++.h>
using namespace std;
int n,m;
string s[110];
bool judge(int x)
{
	for(int i=1;i<m;i++)
	{
		if(s[x][i]!=s[x][i-1]) return false;
	}
	return true;
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	if(!judge(0))
	{
		cout<<"NO"<<endl;
		return;
	}
	for(int i=1;i<n;i++)
	{
		if(!judge(i))
		{
			cout<<"NO"<<endl;
			return;
		}
		if(s[i][0]==s[i-1][0])
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
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