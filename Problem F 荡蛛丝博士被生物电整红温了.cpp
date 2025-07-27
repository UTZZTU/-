#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,a,b,c,d;
signed main ()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d;
		if(a>b) swap(a,b);
		if(c>d) swap(c,d);
		if(b-a>=20||d-c>=20) printf("9");
		else
		{
			int maxx=0;
			for(int i=a;i<=b;i++)
			{
				for(int j=c;j<=d;j++)
				{
					int num=i+j;
					while(num)
					{
						int x=num%10;
						maxx=max(maxx,x);
						num/=10;
					}
				}
			}
			printf("%lld",maxx);
		}
		if(t!=0) printf("\n");
	}
	return 0;
}