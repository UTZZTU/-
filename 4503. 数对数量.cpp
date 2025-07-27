#include <bits/stdc++.h>
using namespace std;
int a,b,n,ans;
int main ()
{
	cin>>a>>b>>n;
	for(int i=0;i<=a;i++)
	{
		for(int j=0;j<=b;j++)
		{
			if(i+j==n)
			ans++;
		}
	}
	cout<<ans;
	return 0;
}