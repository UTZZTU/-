#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int a[110];
int main ()
{
	int n,m;
	while(cin>>n>>m)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=m;i++)
		{
			int q,h;
			cin>>q>>h;
			a[q]++;
			a[h]++;
		}
		sort(a+1,a+n+1);
		printf("%d\n",a[n]);
	}
	return 0;
}