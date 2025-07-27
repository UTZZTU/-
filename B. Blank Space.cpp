#include <bits/stdc++.h>
using namespace std;
int t,n,a[110],res,maxx;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		maxx=res=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) res++;
			else
			{
				maxx=max(maxx,res);
				res=0;
			}
		}
		maxx=max(maxx,res);
		printf("%d\n",maxx);
	}
	return 0;
}