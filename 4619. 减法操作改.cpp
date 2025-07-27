#include <bits/stdc++.h>
using namespace std;
int a[200010],judge,n;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		if(a[i]&1)
		{
			a[i]--;
			a[i+1]--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0||a[i]&1)
		{
			judge=1;
			break;
		}
	}
	if(judge)
	cout<<"NO";
	else
	cout<<"YES";
	return 0;
}