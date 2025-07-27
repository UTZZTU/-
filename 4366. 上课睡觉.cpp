#include <bits/stdc++.h>
using namespace std;
int t,n,a[100010],res,minn;
int num(int x)
{
	int ans=0,number=0,pos=0;
	for(int i=1;i<=n;i++)
	{
		if(number+a[i]>x)
		{
			if(number!=x)
			{
				return 0x3f3f3f3f;
			}
			number=a[i];
			ans++;
		}
		else
		{
			number+=a[i];
			pos++;
		}
	}
	if(number!=x)
	{
		return 0x3f3f3f3f;
	}
	ans++;
	return ans*x==res?pos-1:0x3f3f3f3f;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		res=0,minn=0x3f3f3f3f;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			res+=a[i];
		}
		if(res==0)
		{
			printf("0\n");
			continue;
		}
		for(int i=1;i*i<=res;i++)
		{
			if(res%i==0)
			{
				minn=min(minn,num(i));
				minn=min(minn,num(res/i));
			}
		}
		printf("%d\n",minn);
	}
	return 0;
}