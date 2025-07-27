#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x2,y2,x3,y3=1,x4=1,y4,n;
int main ()
{
	scanf("%lld",&n);
	if(n==2)
	cout<<"1";
	else if(n==3)
	cout<<"2";
	else
	{
		x3=floor(sqrt(n));
		y4=x3;
		n-=x3*x3;
		if(n%x3!=0)
		n=n/x3+1;
		else
		n=n/x3;
		y4+=n;
		cout<<abs(y4-y3)+abs(x4-x3);
	}
	return 0;
}