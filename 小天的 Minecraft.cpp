#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,b,c,p=16;
void print(__int128 x)
{
    if (x>9) print(x/10);
    putchar('0'+x%10);
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		double s=pow(a/16.0,16)+1820*pow(a/16.0,12)*(pow(b/16.0,4)+pow(c/16.0,4));
		printf("%.10f\n",s);
	}
	return 0;
}