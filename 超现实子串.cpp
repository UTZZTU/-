#include <bits/stdc++.h>
using namespace std;
int n,a[1000010],maxx=0,l;
bool judge(int i,int j,int l)
{
	if(l&1)
	{
		if(a[j]==a[i]+ceil(l/2.0))
		return true;
		return false;
	}
	else
	{
		if(a[j]==a[i]-ceil(l/2.0))
		return true;
		return false;
	}
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int j=i+1,l=1;
		while(j<=n&&judge(i,j,l))
		{
			l++;
			j++;
		}
		maxx=max(maxx,j-i);
	}
	cout<<maxx;
	return 0;
}