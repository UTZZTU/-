#include <bits/stdc++.h>
using namespace std;
int h,w,k,sum;
string a[15];
int main ()
{
	cin>>h>>w>>k;
	getchar();
	for(int i=0;i<h;i++)
	cin>>a[i];
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(a[i][j]=='1')
			sum++;
		}
	}
	if(sum<=k)
	cout<<0;
	else
	cout<<2;
	return 0;
}