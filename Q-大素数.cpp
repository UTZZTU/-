#include <bits/stdc++.h>
using namespace std;
bool judge(int x)
{
	if(x==1)
	return false;
	if(x==2||x==3)
	return true;
	if(x%6!=1&&x%6!=5)
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
int n;
int main ()
{
	while(cin>>n)
	{
		if(judge(n))
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}