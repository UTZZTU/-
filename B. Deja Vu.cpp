#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
ll t,n,q,a[100010],x[100010],sum[31],f[100010],b[100010],pos[100];
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		set<int> st;
		vector<int> vec;
		scanf("%lld%lld",&n,&q);
		memset(pos,-1,sizeof pos);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			b[i]=a[i];
//			if(a[i]==1)
//			{
//				f[i]=-1;
//				continue;
//			}
			ll pos=0;
			while(a[i]%2==0)
			{
				a[i]/=2;
				pos++;
			}
//			if(a[i]==1)
			f[i]=pos;
//			else f[i]=-1;
		}
//		for(int i=1;i<=30;i++) sum[i]=0;
		for(int i=1;i<=q;i++)
		{
			scanf("%lld",&x[i]);
//			sum[x[i]]++;
			if(pos[x[i]]==-1)
			{
				pos[x[i]]=i;
			}
		}
		for(int i=1;i<=)
		for(int i=1;i<=n;i++)
		{
//			if(f[i]==-1) continue;
			for(int j=1;j<=30;j++)
			{
				if(j<=f[i])
				{
					b[i]+=(ll)pow((ll)2,j-1)*(ll)sum[j];
				}
				else break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			printf("%lld ",b[i]);
		}
		printf("\n");
	}
	return 0;
}