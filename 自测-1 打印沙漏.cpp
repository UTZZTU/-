#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int maxn,n;
	char c;
	cin>>n>>c;
	for(int i=1;;i++)
	{
		if(2*i*i-1<=n)
		maxn=i;
		else
		break;
	}
	for(int i=2*maxn-1;i>=1;i-=2)
	{
		for(int j=1;j<=(2*maxn-i-1)/2;j++)
		cout<<" ";
		for(int j=1;j<=i;j++)
		cout<<c;
		cout<<endl;
	}
	for(int i=3;i<=2*maxn-1;i+=2)
	{
		for(int j=1;j<=(2*maxn-i-1)/2;j++)
		cout<<" ";
		for(int j=1;j<=i;j++)
		cout<<c;
		cout<<endl;
	}
	cout<<n-2*maxn*maxn+1;
	return 0;
}