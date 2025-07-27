#include <bits/stdc++.h>
using namespace std;
#define il inline
il int read()
{
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*k;
}
int t,n,l,k,maxx,minn,s[1000010];
int main ()
{
	t=read();
	while(t--)
	{
		l=read();
		n=read();
		maxx=0;
		minn=0;
		for(int i=1;i<=n;i++)
		{
			s[i]=read();
			maxx=max(maxx,max(s[i],l-s[i]));
		}
		sort(s+1,s+1+n);
		for(int i=1;i<=n;i++)
		{
			k=min(s[i],l-s[i]);
			minn=max(minn,k);
		}
		printf("%d %d\n",minn,maxx);
	}
	return 0;
}
