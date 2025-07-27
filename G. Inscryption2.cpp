#include <bits/stdc++.h>
using namespace std;
int t,n,f[1000010],res1,res2,res3,cnt1,cnt2,cnt3,post[1000010],flag,res,p,q,x,y;
double maxx;
double get_num()
{
	if(1+cnt1-cnt2==1)
	{
		return (double)(res+(cnt3+1)/2)*1.0/();
	}
	else
	{
		
	}
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		res=1;
		flag=0;
		maxx=0;
		res1=res2=res3=cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
			if(f[i]==1) res1++;
			else if(f[i]==-1) res2++;
			else if(f[i]==0) res3++;
		}
		int t1=0,t2=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==-1) t1++;
			else t2++;
			if(t1>t2)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			puts("-1");
			continue;
		}
		post[n+1]=0;
		for(int i=n;i>=1;i--)
		{
			if(f[i]==-1) post[i]=1;
			else post[i]=0;
			post[i]+=post[i+1];
		}
//		for(int i=1;i<=n;i++)
//		{
////			if(i==0) ;
//			if(f[i]==1) cnt1++;
//			else if(f[i]==-1) cnt2++;
//			else if(f[i]==0) cnt3++;
//			if(cnt1+cnt3>=post[i+1])
//			{
////				printf("**%d %d %d %d\n",i,cnt1,cnt2,cnt3);
//				res1-=cnt1;
//				res3-=cnt3;
//				if(res1>=res3)
//				{
//					int p=1+cnt1+cnt3+res1;
//					int q=1+cnt1+cnt3-post[i+1]+(res1-res3);
//					int yz=__gcd(p,q);
//					printf("%d %d\n",p/yz,q/yz);
////					printf("%d %d %d %d\n",res1,res3,cnt1,cnt3);
//					break;
//				}
//				else if(res1<res3)
//				{
//					int p=1+cnt1+cnt3+res1+(res3-res1+1)/2;
//					int q=1+cnt1+cnt3-post[i+1]+(res3-res1)%2;
//					int yz=__gcd(p,q);
//					printf("%d %d\n",p/yz,q/yz);
////					printf("%d %d %d %d\n",res1,res3,cnt1,cnt3);
//					break;
//				}
//			}
//		}
		
		
		
		
		for(int i=1;i<=n;i++)
		{
//			if(i==0) ;
			if(f[i]==1) cnt1++;
			else if(f[i]==-1) cnt2++;
			else if(f[i]==0) cnt3++;
			if(1+cnt1-cnt2<1)
			{
				int bp=cnt2-cnt1;
				res+=(bp);
				cnt3-=bp;
				cnt2-=bp;
				if(get_num()>maxx)
				{
					p=;
					q=;
				}
			}
			else
			{
				cnt1-=cnt2;
				cnt2=0;
			}
		}
		
		int yz=__gcd(p,q);
		printf("%d %d\n",p/yz,q/yz);
	}
	return 0;
}