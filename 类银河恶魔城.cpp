#include <bits/stdc++.h>
using namespace std;
int n,k,a[1010],b[1010];
double f[1010];
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		f[i]=a[i]*0.7+b[i]*0.2;
	}
	sort(f+1,f+1+n);
	for(int i=1;i<=n;i++)
	{
		double x=a[i]*0.7+b[i]*0.2+10;
		int pos=upper_bound(f+1,f+1+n,x)-f;
		pos=n-pos+2;
		if(pos<=k) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}