#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
string a="https://ac.nowcoder.com",b="ac.nowcoder.com",c="https://www.nowcoder.com",d="www.nowcoder.com",s;
void solve()
{
	cin>>s;
	if(s.find(c)==0||s.find(d)==0) cout<<"Nowcoder"<<endl;
	else if(s.find(a)==0||s.find(b)==0) cout<<"Ac"<<endl;
	else cout<<"No"<<endl;
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