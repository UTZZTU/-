#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n;
void solve()
{
	cin>>n;
	string s="";
	int i=1;
	while(s.size()<n)
	{
		s=s+(char)('0'+i)+s;
		i++;
	}
	cout<<i-1<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<s[i]-'0'<<" ";
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