#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,v,res,f[100010],sum;
int main ()
{
	cin>>n>>v;
	for(int i=1;i<=n;i++)
	cin>>f[i];
	for(int i=1;i<=n;i++)
	{
		sum+=f[i];
		if(sum>v)
		{
			sum=f[i];res++;
		}
	}
	if(sum)
	res++;
	cout<<res;
	return 0;
}