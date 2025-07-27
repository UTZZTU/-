#include <iostream>
#include <algorithm>
using namespace std;
int n,a[110];
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int i=n-1;
	while(a[i]==a[n])
	{
		i--;
	}
	cout<<a[i];
	return 0;
}