#include <bits/stdc++.h>
using namespace std;
int f[1010],n,m,k,t,res,tot,num;
int main ()
{
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		memset(f,0,sizeof f);
		res=tot=num=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&t);
			f[max(1,t-k)]++;
			f[min(n,t+k)+1]--;
		}
		for(int i=1;i<=n;i++)
		{
			res+=f[i];
			if(!res)
			{
				tot++;
			}
			else
			{
				num+=ceil(tot*1.0/(2*k+1));
				tot=0;
			}
		}
		num+=ceil(tot*1.0/(2*k+1));
		printf("%d\n",num);
	}
	return 0;
}