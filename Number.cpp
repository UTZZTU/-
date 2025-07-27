#include <bits/stdc++.h>
using namespace std;
int n;
string p;
int main ()
{
	cin>>n>>p;
	if(n<p.size())
	printf("T_T");
	else
	{
		cout<<p;
		for(int i=1;i<=n-p.size();i++)
		printf("0");
	}
	return 0;
}