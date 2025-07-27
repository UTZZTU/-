#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,f[110];
signed main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int res1=0,res2=0,res3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>f[i];
			if(f[i]>0) res1++;
			else if(f[i]==0) res2++;
			else res3++;
		}
		if(res2)
		{
			puts("0");
		}
		else if(res3)
		{
			if(res3&1) puts("0");
			else
			{
				puts("1");
				cout<<1<<" "<<0<<endl;
			}
		}
		else
		{
			puts("1");
			cout<<1<<" "<<0<<endl;
		}
	}
	return 0;
}