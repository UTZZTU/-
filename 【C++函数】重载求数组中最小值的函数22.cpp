#include <iostream>
#include <algorithm>
using namespace std;
int miniElement(int array[],int n)
{
	sort(array,array+n);
	return array[0];
}
double miniElement(double array[],int n)
{
	sort(array,array+n);
	return array[0];
}
int main ()
{
	int n,a[50],b;
	double w[50],s;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	b=miniElement(a,n);
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>w[i];
	s=miniElement(w,n);
	cout<<b<<endl;
	cout<<s<<endl;
	return 0;
}