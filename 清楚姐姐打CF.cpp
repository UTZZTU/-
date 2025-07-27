#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll maxx,k,ai;
int main ()
{
	scanf("%d %lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&ai);
		maxx=max(maxx,ai);
	}
	k=maxx-k;
	if(k<0)
	cout<<"0";
	else
	cout<<k;
	return 0;
}