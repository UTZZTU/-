#include <bits/stdc++.h>
using namespace std;
int t,n,f[200010],res1,res2,res3,a[200010];
bool judge(int x)
{
	for(int i=1;i<=n;i++)
	{
		a[i]=abs(f[i]-x);
		if(i!=1)
		{
			if(a[i]<a[i-1])
			return false;
		}
	}
	return true;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		res1=0;
		res2=0;
		res3=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
			if(i!=1)
			{
				if(f[i]>f[i-1])
				res1++;
				else if(f[i]==f[i-1])
				res2++;
				else
				res3++;
			}
		}
		if(res1==0||res3==0)
		{
			printf("%d\n",f[1]);
		}
		else
		{
			bool flag=false;
			for(int i=2;i<=n;i++)
			{
				if(f[i]<f[i-1])
				{
					int mid;
					if((f[i]+f[i-1])%2==0)
					{
						mid=(f[i]+f[i-1])/2;
					}
					else
					{
						mid=(f[i]+f[i-1])/2+1;
					}
					if(judge(mid))
					{
						flag=true;
						printf("%d\n",mid);
						break;
					}
				}
			}
			if(!flag)
			printf("-1\n");
		}
	}
	return 0;
}