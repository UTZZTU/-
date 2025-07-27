#include <iostream>
using namespace std;
typedef long long ll;
ll f[1000];
ll a[10000010];
int main ()
{
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=1000;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	
	return 0;
}