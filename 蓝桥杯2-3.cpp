#include <bits/stdc++.h>
using namespace std;
bool judge(int x)
{
	int n=x,tt=1,pos=0;
	while(n)
	{
		pos+=n%10*tt;
		n/=10;
		tt*=16;
	}
	if(pos%x==0)
	return true;
	else
	return false;
}
int main ()
{
	for(int i=10;;i++)
	{
		if(judge(i))
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}