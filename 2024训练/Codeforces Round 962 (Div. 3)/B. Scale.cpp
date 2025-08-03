#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
string s[1010];
void solve()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n/k;i++)
	{
		string t;
		for(int j=0;j<n/k;j++)
		{
			int xx=i*k,yy=j*k;
			if(s[xx][yy]=='1') t+='1';
			else t+='0';
		}
		cout<<t<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}