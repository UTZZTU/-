#include <bits/stdc++.h>
using namespace std;
int res,f[3000],maxx;
int main ()
{
	for(int i=2;i<=2022;i++)
	{
		f[i]=f[i/2]+1;
		if(f[i]>maxx)
		{
			res=1;
			maxx=f[i];
		}
		else if(f[i]==maxx)
		{
			res++;
		}
	}
	cout<<res;
	return 0;
}