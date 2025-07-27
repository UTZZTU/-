#include<iostream>
#include<algorithm>
using namespace std;
long long x3,y3;
int m(long long x3,long long y3);
int main()
{
	long long x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int sum=0;
	long x5,y5;
	x5=x2-x1;y5=y2-y1;
	x3=x2-x1;y3=y2-y1;
	m(x3,y3);
	x5=(x5/x3)-1;
	cout<<x5;
}
int m(long long x4,long long y4)
{
int min;
min=__gcd(x4,y4);
if(min==1){x3=x4;return 0;}
while(x4%min==0&&y4%min==0)
	{	
		x3=x4/min;y3=y4/min;
		x4=x4/min;y4=y4/min;
		
	}
return 0;
}
