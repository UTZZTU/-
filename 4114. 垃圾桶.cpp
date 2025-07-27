#pragma GCC optimize(2)
#include <iostream>
#include <vector>
using namespace std;
#define int long long
int t,n,res;
string s;
signed main ()
{
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		vector<int> vec;
		res=0;
		scanf("%lld",&n);
		getchar();
		cin>>s;
		for(int j=0;j<n;j++)
		{
			if(s[j]=='1') vec.push_back(j+1);
		}
		for(int j=0;j<vec.size();j++)
		{
			if(j==0)
			{
				int x=vec[j];
				x-=1;
				res+=x*(x+1)/2;
			}
			if(j==vec.size()-1)
			{
				int x=vec[j];
				x=n-x;
				res+=x*(x+1)/2;
			}
			else
			{
				int x=vec[j],y=vec[j+1],d;
				d=y-x-1;
				if(d&1)
				{
					int dd=d/2;
					res+=dd*(dd+1);
					res+=(d+1)/2;
				}
				else
				{
					int dd=d/2;
					res+=dd*(dd+1);
				}
			}
		}
		printf("Case #%d: %lld\n",i,res);
	}
	return 0;
}