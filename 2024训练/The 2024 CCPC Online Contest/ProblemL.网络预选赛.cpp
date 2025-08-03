#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,m,res;
string s[510];
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i+1>=n||j+1>=m) continue;
			if(s[i][j]=='c'&&s[i][j+1]=='c'&&s[i+1][j]=='p'&&s[i+1][j+1]=='c') res++;
		}
	}
	cout<<res<<endl;
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