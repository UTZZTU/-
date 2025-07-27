#include <bits/stdc++.h>
using namespace std;
#define il inline
#define re register
il int fast_read()
{
	int x=0,k=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*k;
}
int t,n,d,f[50010],a[50010];

int main ()
{
	t=fast_read();
	while(t--)
	{
		int maxx=1,pos=0;
		n=fast_read(),d=fast_read();
		for(re int i=1;i<=n;i++)
		{
			a[i]=fast_read();
			f[i]=1;
		}
		int b[100010]={0};
		b[a[1]]=1;
		for(int i=2;i<=n;i++)
		{
			pos=0;
			for(int j=max(a[i]-d,1);j<=a[i]+d;j++)
			{
				if(b[j]&&j!=a[i])
				{
					pos=max(pos,b[j]);
				}
			}
			f[i]+=pos;
		    if(f[i]>maxx)
		    maxx=f[i];
		    b[a[i]]=f[i];
		}
		printf("%d\n",maxx);
	}
	return 0;
}