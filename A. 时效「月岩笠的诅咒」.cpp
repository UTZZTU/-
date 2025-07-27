#include <bits/stdc++.h>
using namespace std;
string a,b;
int main ()
{
	cin>>a>>b;
	int i=0,j=0;
	for(i;a[i]!='.';i++)
	{
		;
	}
	for(j;b[j]!='.';j++)
	{
		;
	}
	i++,j++;
	for(int k=1;k<=12;k++)
	{
		if(a[i]!=b[j])
		{
			cout<<"NO";
			return 0;
		}
		i++,j++;
	}
	cout<<"YES";
	return 0;
}