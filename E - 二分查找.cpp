#include <bits/stdc++.h>
using namespace std;
#define il inline
#define re register
map<int,int> mp;
int n,q,k,f[1000100];
il int read()
{
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*k;
}
il bool check(int x)
{
	int pos=lower_bound(f+1,f+1+n,x)-f;
	if(pos>n)
	return false;
	if(f[pos]==x)
	return true;
	return false;
}
int main ()
{
	n=read();
	q=read();
	for(re int i=1;i<=n;i++)
	f[i]=read();
	sort(f+1,f+1+n);
	while(q--)
	{
		k=read();
		if(mp[k]==1)
		printf("YES\n");
		else if(mp[k]==-1)
		printf("NO\n");
		else
		{
			if(check(k))
			{
				mp[k]=1;
				printf("YES\n");
			}
			else
			{
				mp[k]=-1;
				printf("NO\n");
			}
		}
	}
	return 0;
}