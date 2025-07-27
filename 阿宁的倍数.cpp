#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
#define il inline
int n,q,a[400010],cnt,op,x,res;
vector<int> vec[200010];
il int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
int main ()
{
	
	n=read(),q=read();
	cnt=n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
			for(int j=1;j<=floor(sqrt(a[i]));j++)
		{
			if(a[i]%j==0)
			{
				int l=j,r=a[i]/j;
				vec[l].push_back(i);
				if(r!=l)
				{
					vec[r].push_back(i);
				}
			}
		}
	}
	while(q--)
	{
		op=read(),x=read();
		if(op==2)
		{
			int l=upper_bound(vec[a[x]].begin(),vec[a[x]].end(),x)-vec[a[x]].begin();
			printf("%d\n",vec[a[x]].size()-l);
		}
		else
		{
			a[++cnt]=x;
			for(int j=1;j<=floor(sqrt(x));j++)
		{
			if(x%j==0)
			{
				int l=j,r=x/j;
				vec[l].push_back(cnt);
				if(r!=l)
				{
					vec[r].push_back(cnt);
				}
			}
		}
		}
	}
	return 0;
}