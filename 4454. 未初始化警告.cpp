#include <bits/stdc++.h>
using namespace std;
int f[100010],n,k,res,x,y;
int main ()
{
	cin>>n>>k;
	while(k--)
	{
		cin>>x>>y;
		if(y!=0)
		{
			if(!f[y])
			res++;
		}
		f[x]=1;
	}
	cout<<res;
	return 0;
}