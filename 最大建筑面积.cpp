#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,h[1010],maxx;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>h[i];
	for(int i=1;i<=n;i++)
	{
		int j=i,k=0;
		while(j<=n&&h[j]==h[i])
		{
			k++;
			j++;
		}
		maxx=max(maxx,h[i]*k);
		i=j-1;
	}
	cout<<maxx;
	return 0;
}