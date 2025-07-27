#include <bits/stdc++.h>
using namespace std;
bool judge(int x)
{
	while(x)
	{
		int p=x%16;
		if(p<10)
		{
			return false;
		}
		x/=16;
	}
	return true;
}
int main ()
{
	for(int i=2023;;i++)
	{
		if(judge(i))
		{
			printf("%d",i);
			break;
		}
	}
	return 0;
}