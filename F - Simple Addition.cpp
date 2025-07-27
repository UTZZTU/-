#include <iostream>
using namespace std;
typedef long long ll;
ll p,q,res;

int main ()
{
	while(~scanf("%lld%lld",&p,&q))
	{
		if(p<0&&q<0)
		break;
		res=0;
		if(q-p<10)
		{
			for(int i=p;i<=q;i++)
			{
				int j=i;
				while(j&&j%10==0)
				{
					j/=10;
				}
				res+=j%10;
			}
		}
		else
		{
			while(q-p>=10)
			{
				for(p;p%10!=0;p++)
			{
				res+=p%10;
			}
			for(q;q%10!=0;q--)
			{
				res+=q%10;
			}
			res+=(q/10-p/10)*45;
			q/=10;
			p/=10;
			}
			for(int i=p;i<=q;i++)
			{
				int j=i;
				while(j&&j%10==0)
				{
					j/=10;
				}
				res+=j%10;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}