#include <bits/stdc++.h>
using namespace std;
int n;
bool judge(int x)
{
	if(x==2||x==3)
	return true;
	else if(x%6!=1&&x%6!=5)
	return false;
	else
	{
		for(int i=5;i<=floor(sqrt(x));i+=6)
		{
			if(x%i==0||x%(i+2)==0)
			return false;
		}
		return true;
	}
}
int main ()
{
	scanf("%d",&n);
	if(judge(n))
	cout<<1;
	else if(n%2==0)
	cout<<2;
	else
	{
		if(judge(n-2))
		cout<<2;
		else
		cout<<3;
	}
	return 0;
}