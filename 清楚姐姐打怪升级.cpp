#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t,a,h[1000010],v[1000010],tt;
bool judge()
{
	ll cz,hp,cs;
	for(int i=1;i<=n;i++)
	{
		if(a>=h[i])
		{
			if(i==1)
			tt+=1;
			else
			tt+=t;
			continue;
		}
		else
		{
			if(i==1)
			tt+=1;
			else
			tt+=t;
			hp=min(h[i],h[i]-a+t*v[i]);
			if(hp==h[i])
			return false;
			if(hp<=a)
			{
				tt+=t;
				continue;
			}
			else
			{
				cz=h[i]-hp;
				cs=ceil((hp-a)*1.0/cz);
				tt+=(cs+1)*t;
			}
		}
	}
	return true;
}
int main ()
{
	scanf("%lld%lld%lld",&n,&t,&a);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&h[i],&v[i]);
	}
	if(judge())
	printf("%lld",tt);
	else
	printf("-1");
	return 0;
}