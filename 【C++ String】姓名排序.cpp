#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
int main ()
{
	string a[105];
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<n;i++)
	cout<<a[i]<<",";
	cout<<a[i];
	return 0;
}