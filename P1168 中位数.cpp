#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[100010];
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;2*i-1<=n;i++)
	{
		sort(a+1,a+2*i);
		printf("%d\n",a[i]);
	}
	return 0;
}