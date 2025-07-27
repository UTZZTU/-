#include <bits/stdc++.h>
using namespace std;
int n,res;
int main ()
{
	scanf("%d",&n);
	for(int i=0;i*4<=n;i++)
	{
		if((n-i*4)%5==0) res++;
	}
	cout<<res;
	return 0;
}