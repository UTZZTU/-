#include <bits/stdc++.h>
using namespace std;
int t,n,m,x,y;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>x>>y;
		if(x==y) puts("Yes");
		else if(x>y) puts("No");
		else if(n-m>=y-x) puts("Yes");
		else puts("No");
	}
	return 0;
}