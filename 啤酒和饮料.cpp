#include <bits/stdc++.h>
using namespace std;
int main ()
{
	for(int i=1;;i++)
	{
		for(int j=i+1;;j++)
		{
			if(2.3*i+j*1.9==82.3)
			{
				cout<<i;
				return 0;
			}
			else if(2.3*i+1.9*j>82.3)
			break;
		}
	}
	return 0;
}