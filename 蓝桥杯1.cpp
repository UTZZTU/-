#include <bits/stdc++.h>
using namespace std;
int n=2022,sum;
int main ()
{
	while(n)
	{
		sum++;
		n/=2;
	}
	cout<<sum;
	return 0;
}