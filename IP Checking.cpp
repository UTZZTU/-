#include <iostream>
using namespace std;
typedef long long ll;
int main ()
{
	int t;
	cin>>t;
	getchar();
	for(int i=1;i<=t;i++)
	{
		int a,b,c,d;
		ll s1,s2,s3,s4;
		ll u1=0,u2=0,u3=0,u4=0,m=1;
		scanf("%d.%d.%d.%d",&a,&b,&c,&d);
		scanf("%lld.%lld.%lld.%lld",&s1,&s2,&s3,&s4);
		while(a!=0)
		{
			u1+=(a%2)*m;
			m*=10;
			a/=2;
		}
		m=1;
		while(b!=0)
		{
			u2+=(b%2)*m;
			m*=10;
			b/=2;
		}
		m=1;
		while(c!=0)
		{
			u3+=(c%2)*m;
			m*=10;
			c/=2;
		}
		m=1;
		while(d!=0)
		{
			u4+=(d%2)*m;
			m*=10;
			d/=2;
		}
		if(u1==s1&&u2==s2&&u3==s3&&u4==s4)
		{
			printf("Case %d: Yes\n",i);
		}
		else
		printf("Case %d: No\n",i);
	}
	return 0;
}