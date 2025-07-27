#include <bits/stdc++.h>
using namespace std;
int n;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%3==1||i%3==2)
		{
			cout<<"1 ";
		}
		else
		{
			cout<<"2 ";
		}
	}
	return 0;
}