#include <bits/stdc++.h>
using namespace std;
int n,a[3],b[3],c,p;
int main ()
{
	cin>>n;
	while(n--)
	{
		cin>>c>>p;
		if(c==0)
		{
			a[p-1]++;
		}
		else
		{
			b[p-1]++;
		}
	}
	printf("%d %d %d\n%d %d %d\n",a[0],a[1],a[2],b[0],b[1],b[2]);
	if(a[0]>b[0]||a[0]==b[0]&&a[1]>b[1]||a[0]==b[0]&&a[1]==b[1]&&a[2]>b[2]) printf("The first win!");
	else printf("The second win!");
	return 0;
}