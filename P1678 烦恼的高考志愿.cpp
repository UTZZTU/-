#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tot;
int a[100010];
int main ()
{
	int m,n,k;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		int j=lower_bound(a+1,a+1+m,k)-a;
		if(j>m)
		tot+=k-a[m];
		else if(j==1)
		tot+=a[j]-k;
		else
		tot+=min(a[j]-k,k-a[j-1]);
	}
	cout<<tot;
	return 0;
}