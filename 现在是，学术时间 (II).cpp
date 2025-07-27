#include <bits/stdc++.h>
using namespace std;
int t,x,y,px,py,maxx;
double res=0;
int main ()
{
	cin>>t;
	while(t--)
	{
		maxx=0;
		res=0;
		cin>>x>>y>>px>>py;
		if(px<=x&&py<=y)
		{
			maxx=max((x-px)*py,max((x-px)*(y-py),max(px*py,px*(y-py))));
			res=max(res,(double)maxx*1.0/(x*y));
		}
		else if(px>x&&py>y)
		{
			res=max(res,(double)x*y*1.0/(px*py));
		}
		else if(px>x&&py<=y)
		{
			res=max(res,(double)x*py*1.0/(px*py+x*y-x*py));
			res=max(res,(double)x*(y-py)*1.0/((y-py)*px+x*y-x*(y-py)));
		}
		else if(px<=x&&py>y)
		{
			res=max(res,(double)y*px*1.0/(px*py+x*y-y*px));
			res=max(res,(double)y*(x-px)*1.0/((x-px)*py+x*y-y*(x-px)));
		}
		printf("%.9f\n",res);
	}
	return 0;
}