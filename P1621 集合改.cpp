#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int primes[N],a,b,p,ans,fa[N];
int find(int x)
{
	while(x!=fa[x])
	x=fa[x]=fa[fa[x]];
	return x;
}
int main ()
{
	cin>>a>>b>>p;
	for(int i=a;i<=b;i++)
	fa[i]=i;
	ans=b-a+1;
	for(int i=2;i<=b;i++)
	{
		if(!primes[i])
		{
			if(i>=p)
			{
				for(int j=2*i;j<=b;j+=i)
				{
					primes[j]=1;
					int tx=find(j-i),ty=find(j);
					if(j-i>=a&&tx!=ty)
					{
						fa[ty]=tx;
					    ans--;
					}
				}
			}
			else
			{
				for(int j=2*i;j<=b;j+=i)
				primes[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}