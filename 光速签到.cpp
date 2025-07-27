#include <bits/stdc++.h>
using namespace std;
int a[10],n;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[1]!=0) cout<<-1;
	else
	{
		for(int i=n;i>=1;i--) cout<<a[i];
	}
	return 0;
}