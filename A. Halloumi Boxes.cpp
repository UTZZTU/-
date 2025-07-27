#include <bits/stdc++.h>
using namespace std;
int t,n,k,a[110];
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(k==1)
		{
			int i=2;
			for(i;i<=n;i++)
			{
				if(a[i]<a[i-1]) break;
			}
			if(i==n+1) puts("YES");
			else puts("NO");
		}
		else puts("YES");
	}
	return 0;
}