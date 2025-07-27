#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,f[100010],res,cnt,pos;
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&f[i]);
	sort(f+1,f+1+n);
	for(int i=n;i>=1;i--)
	{
		if(f[i]%2==0) res+=f[i];
		else
		{
			pos++;
			if(pos==2)
			{
				res+=cnt+f[i];
				pos=0;
				cnt=0;
			}
			else if(pos==1)
			{
				cnt+=f[i];
			}
		}
	}
	cout<<res;
	return 0;
}