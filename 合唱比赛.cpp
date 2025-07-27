#include <bits/stdc++.h>
using namespace std;
int n,f[1010],res;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		res+=f[i];
	}
	sort(f+1,f+1+n);
	printf("%.6f %.6f\n",(double)(res-f[n])*1.0/(n-1),(double)(res-f[1])*1.0/(n-1));
	return 0;
}