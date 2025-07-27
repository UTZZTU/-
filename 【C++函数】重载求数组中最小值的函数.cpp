#include <iostream>
#include <algorithm>
using namespace std;
void fun1(int a[],int n,int& w)
{
	sort(a,a+n);
	w=a[0];
}
void fun2(double a[],int n,double& e)
{
	sort(a,a+n);
	e=a[0];
}
int main ()
{
	int n,a[22],i,q1;
	double b[22],q2;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	fun1(a,n,q1);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&b[i]);
	}
	fun2(b,n,q2);
	printf("%d\n%.1f",q1,q2);
	return 0;
}