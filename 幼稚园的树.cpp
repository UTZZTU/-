#include <bits/stdc++.h>
using namespace std;
int t,n,h[1010],a,k,b,m;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
		scanf("%d%d%d%d",&a,&k,&b,&m);
		m--;
		while(m--)
		{
			for(int i=1;i<=n;i++)
			{
				h[i]+=a;
				if(h[i]>k)
				h[i]=b;
			}
		}
		for(int i=1;i<=n;i++)
		cout<<h[i]<<" ";
		cout<<endl;
	}
	return 0;
}