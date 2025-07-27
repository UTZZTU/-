#include <bits/stdc++.h>
using namespace std;
int n,x,a[110],res;
int main ()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(x>a[i])
		{
			res+=a[i];
		}
		else break;
	}
	cout<<res;
	return 0;
}