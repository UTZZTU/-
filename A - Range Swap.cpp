#include <iostream>
using namespace std;
int n,p,q,r,s,a[110],b[110];
int main ()
{
	cin>>n>>p>>q>>r>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i>=p&&i<=q)
		{
			b[i]=a[i-p+r];
		}
		else if(i>=r&&i<=s)
		{
			b[i]=a[i-r+p];
		}
		else
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	cout<<b[i]<<" ";
	return 0;
}