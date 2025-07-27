#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k,f[200010],five[200010],two[200010];
ll res=0;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		res=0;
		for(int i=1;i<=n;i++)
		{
			cin>>f[i];
			int j=f[i],res=0;
			while(j%2==0)
			{
				res++;
				j/=2;
			}
			two[i]=res;
			res=0;
			while(j%5==0)
			{
				res++;
				j/=5;
			}
			five[i]=res;
		}
		for(int i=1;i<=n;i++)
		{
			int tt=0,ff=0;
			for(int j=i;j<=n;j++)
			{
				tt+=two[j],ff+=five[j];
				if(min(tt,ff)==k) 
				{
					res++;
					cout<<i<<" "<<j<<endl;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}