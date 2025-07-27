#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,y;
signed main ()
{
	cin>>x>>y;
	for(int b=0;b<=1000000;b++)
	{
		int c=(y-1000*b)/2500;
		int a=x-b-c;
		if(a>=0&&b>=0&&c>=0&&a+b+c==x&&1000*b+2500*c==y)
		{
			cout<<a<<" "<<b<<" "<<c;
			return 0;
		}
	}
	puts("-1");
	return 0;
}