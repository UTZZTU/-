#include <bits/stdc++.h>
using namespace std;
int n,a[1000010],sum;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]&1)
		sum++;
	}
	if(sum&1)
	cout<<"Alice";
	else
	cout<<"Bob";
	return 0;
}