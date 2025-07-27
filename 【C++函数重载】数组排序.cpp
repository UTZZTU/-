#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void fun(int p[15],int n)
{
	sort(p,p+n);
}
void fun(string q[15],int n)
{
	sort(q,q+n);
}
int main ()
{
	int n,m,i,a[15];
	string s[15];
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	fun(a,n);
	cin>>m;
	for(i=0;i<m;i++)
	cin>>s[i];
	fun(s,m);
	for(i=0;i<n-1;i++)
	cout<<a[i]<<" ";
	cout<<a[i];
	cout<<endl;
	for(i=0;i<m-1;i++)
	cout<<s[i]<<" ";
	cout<<s[i];
	return 0;
}