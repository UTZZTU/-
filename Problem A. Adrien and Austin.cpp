#include <bits/stdc++.h>
using namespace std;
int n,k;
int main ()
{
	cin>>n>>k;
	if(n==0) puts("Austin");
	else
	{
		if(n%2==0&&k==1)
		{
			puts("Austin");
		}
		else puts("Adrien");
	}
	return 0;
}