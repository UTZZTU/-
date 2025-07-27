#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxx;
int main ()
{
	cin>>n>>m;
	maxx=n;
	for(int i=1;i<=n/i;i++)
	{
		if(n%i==0)
		{
			if(i<=m)
			{
				maxx=min(maxx,(ll)n/i);
			}
			if(n/i<=m)
			{
				maxx=min(maxx,(ll)i);
			}
		}
	}
	cout<<maxx;
	return 0;
}