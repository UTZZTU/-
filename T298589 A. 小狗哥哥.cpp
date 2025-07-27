#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,f[100010],l=-0x3f3f3f3f3f3f3f3f,r=0x3f3f3f3f3f3f3f3f,flag1=0,flag2=0,k;
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		if(f[i]==1)
		{
			flag1=1;
			l=max(l,(ll)ceil(m*1.0/i));
		}
		else
		{
			flag1=1;
			flag2=1;
			l=max(l,(ll)ceil(m*1.0/(i*f[i])));
			if(m%((f[i]-1)*i)==0)
			r=min(r,m/((f[i]-1)*i)-1);
			else
			r=min(r,(ll)floor(m*1.0/((f[i]-1)*i)));
		}
	}
	if(!flag1||!flag2)
	{
		cout<<"xiaogougege";
	}
	else
	{
		cout<<max((ll)0,r-l+1);
	}
	return 0;
}