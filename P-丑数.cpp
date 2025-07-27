#include <bits/stdc++.h>
using namespace std;
bool judge(int x)
{
	while(x%2==0)
	x/=2;
	while(x%3==0)
	x/=3;
	while(x%5==0)
	x/=5;
	if(x==1)
	return true;
	else
	return false;
}
int n;
int main ()
{
	while(cin>>n)
	{
		if(n==0)
		break;
		if(judge(n))
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}