#include <bits/stdc++.h>
using namespace std;
int f[1000010],n,m,k,res,ans;
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&k);
		f[max(1,k-2)]++;
		f[k+3]--;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=f[i];
		if(ans>0)
		res++;
	}
	cout<<res;
	return 0;
}