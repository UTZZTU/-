#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,p;
void solve()
{
	cin>>n;	
	p=n/500;
	if(n%500==0)
	{
		p--;
		cout<<(char)('A'+p)<<500<<endl;
	}
	else
	{
		printf("%c%03d",'A'+p,n%500);
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