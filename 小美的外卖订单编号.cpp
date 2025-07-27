#include <bits/stdc++.h>
using namespace std;
int q,m,x;
int main ()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&m,&x);
		if(x%m==0) printf("%d\n",m);
		else printf("%d\n",x%m);
	}
	return 0;
}