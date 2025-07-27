#include <bits/stdc++.h>
using namespace std;
int n,a[200010],k,x,y;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		a[k]=i;
	}
	cin>>x>>y;
	if(abs(a[x]-a[y])==1)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}