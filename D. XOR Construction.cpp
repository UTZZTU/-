#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,a[N],b1;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++) scanf("%d",&a[i]),a[i]^=a[i-1];
	for(int i=20;i>=0;i--)
	{
		int cnt=0;
		for(int j=n-1;j>=0;j--)
		{
			cnt+=(a[j]>>i&1);
		}
		if(cnt>n-cnt) b1|=(1<<i);
	}
	cout<<b1;
	for(int i=1;i<n;i++) cout<<" "<<(b1^a[i]);
	return 0;
}