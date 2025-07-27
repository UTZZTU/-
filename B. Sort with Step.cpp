#include <bits/stdc++.h>
using namespace std;
int t,n,k,p[200010],f[200010];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			f[p[i]]=i;
		}
		vector<int> vec;
		for(int i=1;i<=n;i++)
		{
			if(abs(i-f[i])%k!=0)
			{
				vec.push_back(i);
			}
		}
		if(vec.size()==0)
		{
			puts("0");
		}
		else if(vec.size()==2)
		{
			int x=vec[0],y=vec[1];
			if(abs(x-f[y])%k==0&&abs(y-f[x])%k==0) puts("1");
			else puts("-1");
		}
		else puts("-1");
	}
	return 0;
}