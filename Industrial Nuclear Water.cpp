#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int main ()
{
	ll x1,y1,z1,x2,y2,z2;
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		if(x1==-x2&&y1==-y2&&z1==-z2)
		printf("No\n");
		else if(y1*y1+z1*z1>1000*x1&&y2*y2+z2*z2<1000*x2||y1*y1+z1*z1<1000*x1&&y2*y2+z2*z2>1000*x2||y1*y1+z1*z1>-1000*x1&&y2*y2+z2*z2<-1000*x2||y1*y1+z1*z1<-1000*x1&&y2*y2+z2*z2>-1000*x2)
		printf("No\n");
		else if(x1*x1+z1*z1>1000*y1&&x2*x2+z2*z2<1000*y2||x1*x1+z1*z1<1000*y1&&x2*x2+z2*z2>1000*y2||x1*x1+z1*z1>-1000*y1&&x2*x2+z2*z2<-1000*y2||x1*x1+z1*z1<-1000*y1&&x2*x2+z2*z2>-1000*y2)
		printf("No\n");
		else if(x1*x1+y1*y1>1000*z1&&x2*x2+y2*y2<1000*z2||x1*x1+y1*y1<1000*z1&&x2*x2+y2*y2>1000*z2||x1*x1+y1*y1>-1000*z1&&x2*x2+y2*y2<-1000*z2||x1*x1+y1*y1<-1000*z1&&x2*x2+y2*y2>-1000*z2)
		printf("No\n");
		else
		printf("Yes\n");
	}
	return 0;
}