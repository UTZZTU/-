#include <bits/stdc++.h>
using namespace std;
int n,a[100010],maxx;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int j=i+1;
		while(j<=n&&abs(a[j]-a[j-1])<=1) j++;
		maxx=max(maxx,j-i);
		i=j-1;
	}
	cout<<maxx;
	return 0;
}