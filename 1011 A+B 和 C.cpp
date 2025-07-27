#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;
int main ()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b>>c;
		if(a+b>c)
		printf("Case #%d: true\n",i);
		else
		printf("Case #%d: false\n",i);
	}
	return 0;
}