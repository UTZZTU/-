#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	int n,a[200010],i;
	vector<int> b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		b.push_back(a[i]);
		reverse(b.begin(),b.end());
	}
	for(i=0;i<b.size()-1;i++)
	printf("%d ",b[i]);
	printf("%d",b[i]);
	return 0;
}
