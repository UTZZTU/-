#include <bits/stdc++.h>
using namespace std;
int a[1010],n;
int main ()
{
	cin>>n;
	for(int i=1;i<=1000;i++)
	{
		a[i]=a[i-1]+i;
		if(a[i]==n)
		{
			cout<<"YES";
			return 0;
		}
		if(a[i]>n)
		break;
	}
	cout<<"NO";
	return 0;
}