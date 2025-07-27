#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n,a[100010],m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	while(m--)
	{
		int k;
		cin>>k;
		int p=lower_bound(a,a+n,k)-a;
		if(a[p]==k)
		{
			printf("Yes %d\n",p+1);
		}
		else
		printf("No %d\n",p+1);
	}
	return 0;
}