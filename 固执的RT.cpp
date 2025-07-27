#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,res,k;
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		res+=k;
	}
	if(res>=m) cout<<"YES";
	else cout<<"NO";
	return 0;
}