#include <bits/stdc++.h>
using namespace std;
int n,res,x,k;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		res+=k;
	}
	for(int i=1;i<=5;i++)
	{
		if((res+i)%(n+1)!=1)
		x++;
	}
	cout<<x;
	return 0;
}