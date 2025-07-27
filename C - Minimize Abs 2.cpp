#include <bits/stdc++.h>
using namespace std;
#define int long long
int d;
int f[2000010],cnt,minn=0x3f3f3f3f3f3f3f3f;
signed main ()
{
	while(1)
	{
		++cnt;
		f[cnt]=cnt*cnt;
		if(f[cnt]>2000000000000) break;
	}
	cin>>d;
	for(int i=1;i<=cnt;i++)
	{
		if(f[i]>d)
		{
			minn=min(minn,f[i]+(int)1-d);
			break;
		}
		else
		{
			int u=d-f[i];
			int pos=lower_bound(f+1,f+1+cnt,u)-f;
			if(pos-1>=0)
			{
				minn=min(minn,abs(f[i]+f[pos-1]-d));
			}
			minn=min(minn,abs(f[i]+f[pos]-d));
		}
	}
	cout<<minn;
	return 0;
}