#include <bits/stdc++.h>
using namespace std;
int n,a[20],b[20],res1,res2,res3,c[20],res;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		b[i]=i;
	}
	do{
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>c[b[i]])
			ans1++;
			else if(a[i]<c[b[i]])
			ans2++;
		}
		if(ans1>ans2)
		res1++;
		else if(ans1<ans2)
		res2++;
		else
		res3++;
		res++;
	}while(next_permutation(b+1,b+1+n));
	cout<<res1<<" "<<res2<<" "<<res3;
	return 0;
}