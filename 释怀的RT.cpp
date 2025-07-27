#include <bits/stdc++.h>
using namespace std;
int n,f[1000010],k,res,sum;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		f[max(1,i-k)]++;
		f[i]--;
		f[i+1]++;
		f[min(n,i+k)+1]--;
	}
	for(int i=1;i<=n;i++)
	{
		res+=f[i];
		if(res) sum++;
	}
	cout<<sum;
	return 0;
}