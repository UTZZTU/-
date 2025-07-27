#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
double a,b,res1,res2;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		res1+=a*b;
		res2+=a;
	}
	printf("%.10f",(double)res1*1.0/res2);
	return 0;
}