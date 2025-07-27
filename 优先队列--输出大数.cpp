#include <iostream>
#include <algorithm>
using namespace std;
int a[1100];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	while(cin>>n>>m)
	{
		int i,j;
		for(i=1;i<=n;i++)
		cin>>a[i];
		sort(a+1,a+1+n);
		j=n;
		for(i=1;i<=m;i++)
		{
			printf("%d",a[j]);
			j--;
			if(i!=m)
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}