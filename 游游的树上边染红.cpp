#include <bits/stdc++.h>
using namespace std;
int n,u,v,w,res;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		res+=w;
	}
	cout<<res;
	return 0;
}