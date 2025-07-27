#include <bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int t,a,b,c;
string s;
void solve()
{
	cin>>a>>b>>c;
	int f;
	f=abs(b-c);
	if(f%2==0)
	{
		printf("1 ");
	}
	else printf("0 ");
	f=abs(a-c);
	if(f%2==0)
	{
		printf("1 ");
	}
	else printf("0 ");
	f=abs(b-a);
	if(f%2==0)
	{
		printf("1\n");
	}
	else printf("0\n");
}
int main ()
{
	ios;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}