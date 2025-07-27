#include <bits/stdc++.h>
using namespace std;
int f[100010],l,r,ans,n;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&f[i]);
	sort(f+1,f+1+n);
	scanf("%d %d",&l,&r);
	int pos=upper_bound(f+1,f+1+n,r)-f;
	if(pos==1)
	{
		cout<<r;
		return 0;
	}
    pos--;
    if(f[pos]>=l)
    {
    	ans+=f[pos];
		ans+=r;
		cout<<ans;
	}
	else
	{
		cout<<r;
		return 0;
	}
	return 0;
}