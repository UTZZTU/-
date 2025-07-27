#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,k,res;
int get_b(int n,int m,int level);
int get_a(int n,int m,int level)
{
		n%=k;
		int val;
		if(level==0)
		val=get_b(n,m,level+1);
		else val=0x3f3f3f3f;
//		cout<<"val "<<val<<endl;
		if(n)
		{
			if(n+2*m<k) ;
			else if(m)
			{
				int pos=(k-n)/2;
				int cnt=k-n-pos*2;
				if(m>=pos)
				{
					m-=pos;
					n=0;
					if(cnt&&m)
					{
						m--;
						n=1;
					}
				}
				
			}
		}
		if(k&1)
		{
			if(n)
			{
				if(m>=k/2)
				{
					m-=k/2;
					n--;
				}
			}
		}
		else
		{
			m%=(k/2);
		}
		return min(n+m,val);
}
int get_b(int n,int m,int level)
{
	if(k%2==0)
	{
		m%=(k/2);
		int val;
		if(level==0)
		val=get_a(n,m,level+1);
		else val=0x3f3f3f3f;
		if(m)
		{
			if(m*2+n<k) ;
			else
			{
				int pos=k-m*2;
				n-=pos;
				m=0;
				n%=k;
			}
		}
		return min(n+m,val);
	}
	else
	{
		if(k==1)
		{
			n%=k;
			return n+m;
		}
		else
		{
			int pos=k/2;
			int minn=min(n,m/pos);
			int val;
			if(level==0)
			val=get_a(n,m,level+1);
			else val=0x3f3f3f3f;
			m-=minn*pos;
			n-=minn;
			if(m*2+n<k) ;
			else if(n)
			{
				int pp=k-m*2;
				if(n>=pp)
				{
					n-=pp;
					m=0;
					n%=k;
				}
			}
			return min(n+m,val);
		}
	}
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
//		printf("%lld\n",get_a(n,m,0));
//		printf("%lld\n",get_b(n,m,0));
		printf("%lld\n",min(get_a(n,m,0),get_b(n,m,0)));
	}
	return 0;
}

/*
6 2 5 0
0 3 3 3
6 1 5 2
9 5 17
*/