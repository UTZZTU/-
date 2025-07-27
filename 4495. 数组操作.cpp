#include <bits/stdc++.h>
using namespace std;
int a[100010];
int js;
int main ()
{
	int n,k,v;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=k;i++)
	{
		int u=upper_bound(a+1,a+1+n,js)-a;
		if(u>n)
		cout<<"0"<<endl;
		else
		{
			cout<<a[u]-js<<endl;
			js+=a[u]-js;
		}
	}
	return 0;
}