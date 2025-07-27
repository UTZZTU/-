#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,k,num[100010],h[100010],f[100010],x,flag;
int main ()
{
	scanf("%lld%lld%lld",&n,&q,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&h[i]);
	}
	f[1]=num[1];
	ll cnt=1,res=num[1];
	flag=0;
//	cout<<"res:"<<res<<endl;
	for(int i=2;i<=n;i++)
	{
//		if(cnt==k)
//		{
//			if(h[i]==h[i-1])
//			{
//				res-=f[i-k];
//				res+=num[i];
//			}
//			else
//			{
//				cnt=1;
//				res+=num[i];
//			}
//			f[i]=res;
//		}
//		else
//		{
//			cnt++;
//			res+=num[i];
//			f[i]=res;
//		}
        if(h[i]==h[i-1])
        {
        	if(cnt>=k)
        	{
        		if(flag)
        		res-=f[i-k];
        		else res-=num[i-k],flag=0;
        		res+=num[i];
        		f[i]=res;
			}
			else
			{
				cnt++;
				res+=num[i];
				f[i]=res;
			}
		}
		else
		{
			flag=1;
			cnt=2;
			res+=num[i];
			f[i]=res;
		}
//		cout<<f[i]<<" "<<cnt<<endl;
		/*
4 1 2
2 2 3 3
2 2 3 3
4
		*/
	}
	while(q--)
	{
		scanf("%lld",&x);
		printf("%lld\n",f[x]);
	}
	return 0;
}