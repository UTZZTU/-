#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
	ll r,x1,y1,x2,y2;
	double rans,xans,yans;
	cin>>r>>x1>>y1>>x2>>y2;
	if(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))>=r)
	{
		rans=r;
		xans=x1;
		yans=y1;
		printf("%.6f %.6f %.6f",xans,yans,rans);
	}
	else
	{
		rans=r+sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		if(x2>x1&&y2<y1)
		{
			xans=x2-(x2-x1)*1.0/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*rans*1.0/2;
			yans=y2+(y1-y2)*1.0/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*rans*1.0/2;
		}
		else if(x2>x1&&y2>y1)
		{
			xans=x2-(x2-x1)*1.0/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*rans*1.0/2;
			yans=y2-(y2-y1)*1.0/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*rans*1.0/2;
		}
		else if(x2<x1&&y2>y1)
		{
			xans=x2+(x1-x2)*1.0/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*rans*1.0/2;
			yans=y2-(y2-y1)*1.0/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*rans*1.0/2;
		}
		else if(x2<x1&&y2<y1)
		{
			xans=x2+(x1-x2)*1.0/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*rans*1.0/2;
			yans=y2+(y1-y2)*1.0/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*rans*1.0/2;
		}
		else if(x1==x2&&y1>y2)
		{
			xans=x2;
			yans=y2+rans*1.0/2;
		}
		else if(x1==x2&&y1<y2)
		{
			xans=x2;
			yans=y2-rans*1.0/2;
		}
		else if(y1==y2&&x1>x2)
		{
			xans=x2+rans*1.0/2;
			yans=y2;
		}
		else if(y1==y2&&x1<x2)
		{
			xans=x2-rans*1.0/2;
			yans=y2;
		}
		else
		{
			xans=x2+rans*1.0/2;
			yans=y2;
		}
		rans=rans*1.0/2;
		printf("%.6f %.6f %.6f",xans,yans,rans);
	}
	return 0;
}