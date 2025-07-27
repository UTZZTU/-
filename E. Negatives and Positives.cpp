#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[200010],res,num,minn;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		res=num=0,minn=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]<0)
			{
				num++;
			}
			res+=abs(a[i]);
			minn=min(minn,abs(a[i]));
		}
		if(num&1)
		{
			res-=2*minn;
		}
		cout<<res<<endl;
	}
	return 0;
}