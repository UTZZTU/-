#include <bits/stdc++.h>
using namespace std;
int t,n,m,res1,res2,res3,k;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		res1=res2=res3=0x3f3f3f3f;
		while(n--)
		{
			cin>>m>>k;
			if(k==11) res3=min(res3,m);
			else if(k==10) res1=min(res1,m);
			else if(k==1) res2=min(res2,m);
		}
		if(res3==0x3f3f3f3f&&(res1==0x3f3f3f3f||res2==0x3f3f3f3f)) printf("-1\n");
		else printf("%d\n",min(res3,res1+res2));
	}
	return 0;
}