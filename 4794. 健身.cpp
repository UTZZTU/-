#include <bits/stdc++.h>
using namespace std;
int n,a[100],res[3];
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		res[i%3]+=a[i];
	}
	cout<<max(res[0],max(res[1],res[2]));
	return 0;
}