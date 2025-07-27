#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[200010],res,cnt,cz;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		res=cnt=cz=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+1+n);
		int i=1,j=n;
		for(i;i<j;i++)
		{
			if(res+a[i]<=a[j])
			{
				res+=a[i];
				cnt+=a[i];
				a[i]=0;
			}
			else
			{
				if(res>=a[j])
				{
					res-=a[j];
					a[j]=0;
					cnt+=1;
					j--;
//							i--;
				}
				else
				{
					a[i]-=a[j]-res;
					cnt+=a[j]-res;
					a[j]=0;
					cnt++;
					j--;
					res=0;
				}
				i--;
			}
		}
//		cout<<cnt<<endl;
		if(res)
		{
			int num=0;
			for(int k=1;k<=n;k++)
			{
				if(a[k])
				{
					num=a[k];
					break;
				}
			}
			int uu=(num+res)/2,vv=(num+res+1)/2;
			if(uu==vv)
			{
				cnt+=uu-res;
				cnt++;
			}
			else
			{
				cnt+=uu-res;
				cnt++;
				cnt++;
			}
		}
		else
		{
			for(int k=1;k<=n;k++)
			{
				if(a[k])
				{
					if(a[k]<=3)
					{
						cnt+=a[k];
					}
					else
					{
						cnt+=(a[k]+1)/2+1;
					}
				}
			}
		}
		
		printf("%lld\n",cnt);
	}
	return 0;
}