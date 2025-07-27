#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res,n,xend,yend,l1,l2,r1,r2,stepx,stepy;
int main ()
{
	scanf("%lld%lld%lld",&n,&xend,&yend);
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			scanf("%lld%lld",&l2,&r2);
			res+=(ll)abs(l2-xend)+(ll)abs(r2-yend);
			l2=xend,r2=yend;
		}
		else
		{
			l1=l2,r1=r2;
			scanf("%lld%lld",&l2,&r2);
			if(r1<=r2&&r1-(i-1)>=r2-i&&l1>=l2&&l1+(i-1)<=l2+i)
			{
				;
			}
			else
			{
				stepx=0,stepy=0;
				if(r1>r2)
				{
					stepx=r1-r2;
					r2+=stepx;
				}
				else if(r1-(i-1)<r2-i)
				{
					stepx=r2-i-(r1-(i-1));
					r2-=stepx;
				}
				if(l1<l2)
				{
					stepy=l2-l1;
					l2-=stepy;
				}
				else if(l1+(i-1)>l2+i)
				{
					stepy=l1+(i-1)-(l2+i);
					l2+=stepy;
				}
				res+=stepx+stepy;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}