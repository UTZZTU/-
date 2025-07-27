#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n,m,s1[100010],s2[100010];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	scanf("%d",&s1[i]);
	for(int i=1;i<=m;i++)
	scanf("%d",&s2[i]);
	sort(s2+1,s2+1+m);
	for(int i=1;i<=n;i++)
	{
		int j=lower_bound(s2+1,s2+1+m,s1[i])-s2;
		if(s1[i]==s2[j])
		printf("%d ",s1[i]);
	}
	return 0;
}
