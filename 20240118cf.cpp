#include <bits/stdc++.h>
using namespace std;
int n,f[50];
string a,b,c;
bool judge()
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==c[i]||b[i]==c[i]) ;
		else return true;
	}
	return false;
}
void solve()
{
	cin>>n;
	cin>>a>>b>>c;
	if(judge()) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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