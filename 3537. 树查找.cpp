#include <bits/stdc++.h>
using namespace std;
int a[1010];
int b[35],k=0,bj;
int main ()
{
	for(int i=1;;i++)
	{
		b[i]=b[i-1]+pow(2,k);
		k++;
		if(b[i]>1000)
		{
		    bj=i;
		    break;
		}
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	}
	cin>>k;
	if(k>bj||b[k-1]>=n)
	cout<<"EMPTY";
	else
	{
		for(int i=b[k-1]+1;i<=min(b[k],n);i++)
		{
			if(i!=b[k-1]+1)
			cout<<" ";
			cout<<a[i];
		}
	}
	return 0;
}