#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
void solve()
{
	int n,y,r;
	scanf("%d-%d-%d",&n,&y,&r);
	printf("%d-%02d-%02d",n+10,y,r);
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