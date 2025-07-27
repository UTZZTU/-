#include <bits/stdc++.h>
using namespace std;
string a[30];
int sum;
int main ()
{
	for(int i=0;i<30;i++)
	cin>>a[i];
	for(int i=1;i<=28;i++)
	{
		for(int j=1;j<=58;j++)
		{
			if(a[i][j]<a[i-1][j]&&a[i][j]<a[i][j-1]&&a[i][j]<a[i+1][j]&&a[i][j]<a[i][j+1])
			sum++;
		}
	}
	cout<<sum;
	return 0;
}