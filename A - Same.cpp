#include <iostream>
#include <algorithm>
using namespace std;
int n,a[110];
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	if(a[1]==a[n]) puts("Yes");
	else puts("No");
	return 0;
}