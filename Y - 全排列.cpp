#include <bits/stdc++.h>
using namespace std;
int n,a[10];
int main ()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)
		break;
		for(int i=1;i<=n;i++)
		a[i]=i;
		do
		{
			for(int i=1;i<=n;i++)
			{
				if(i!=1)
				cout<<" ";
				cout<<a[i];
			}
			cout<<endl;
		}while(next_permutation(a+1,a+1+n));
	}
	return 0;
}