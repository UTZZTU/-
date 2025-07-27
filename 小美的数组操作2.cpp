#include <bits/stdc++.h>
using namespace std;
int t,n,k,u,v,f[110];
bool judge()
{
	for(int i=2;i<=n;i++)
	{
		if(f[i]<f[i-1]) return false;
	}
	return true;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
		}
		while(k--){
			scanf("%d%d",&u,&v);
			f[u]++,f[v]--;
		}
		if(judge()) puts("Yes");
		else puts("No");
	}
	return 0;
}