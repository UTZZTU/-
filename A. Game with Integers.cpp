#include <bits/stdc++.h>
using namespace std;
int t,n;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%3==1||n%3==2)
		{
			printf("First\n");
		}
		else printf("Second\n");
	}
	return 0;
}