#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int res;
int get(char a,char b)
{
	int cnt=0;
	while(a!=b)
	{
		a++;
		if(a>'z')
		{
			a='a';
		}
		cnt++;
	}
	return cnt;
}
void solve()
{
	cin>>s;
	int i=0,j=s.size()-1;
	while(i<j)
	{
		res+=min(get(s[i],s[j]),get(s[j],s[i]));
		i++,j--;
	}
	cout<<res<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}