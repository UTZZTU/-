#include <bits/stdc++.h>
using namespace std;
double sum;
int main ()
{
	for(int i=1;;i++)
	{
		sum+=1.0/i;
		if(sum>12)
		{
			cout<<i;
			break;
		}
	}
	return 0;
}