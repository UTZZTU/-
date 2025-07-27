#include <bits/stdc++.h>
using namespace std;
int n,h,m,f[1000010],maxx;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h>>m;
		f[h*60+m]++;
		maxx=max(maxx,f[h*60+m]);
	}
	cout<<maxx;
	return 0;
}