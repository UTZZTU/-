#include <bits/stdc++.h>
using namespace std;
int n,s11,s12,s13,s21,s22,s23;
int ans=0;
bool check(int a,int b)
{
	if(abs(a-b)<=2||abs(a-b)>=n-2)
	return true;
	else
	return false;
}
int main ()
{
	cin>>n;
	cin>>s11>>s12>>s13>>s21>>s22>>s23;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(check(i,s11)&&check(j,s12)&&check(k,s13)||check(i,s21)&&check(j,s22)&&check(k,s23))
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}