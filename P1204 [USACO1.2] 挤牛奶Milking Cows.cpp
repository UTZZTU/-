#include <bits/stdc++.h>
using namespace std;
//#define int long long
int n,l,r,maxx1,maxx2,f[1000010],cnt1,cnt2,res,flag=1;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		f[l]++;
		f[r+1]--;
	}
	int i=0;
	while(i<=1000000&&!(res+f[i]))
	{
		res+=f[i];
		i++;
	}
	cnt1=i;
//	cout<<i<<endl;
	for(i;i<=1000000;i++)
	{
		res+=f[i];
		if(res)
		{
			if(flag)
			{
//				cnt1++;
//				cnt2=0;
				;
			}
			else
			{
//				cout<<i<<endl;
				maxx2=max(maxx2,i-cnt2);
//				cnt2=0;
				cnt1=i;
				flag=1;
			}
		}
		else
		{
			if(!flag)
			{
//				cnt2++;
//				cnt1=0;
				;
			}
			else
			{
//				cout<<i<<endl;
				maxx1=max(maxx1,i-1-cnt1);
//				cnt1=0;
				cnt2=i-1;
				flag=0;
			}
		}
	}
	printf("%d %d",maxx1,maxx2);
	return 0;
}