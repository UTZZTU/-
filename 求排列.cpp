#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main ()
{
   int a[10],sum=0;
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
   	a[i]=i;
   }
   do
   {
   	int t=ceil(n*1.0/2),q=0,h=0;
   	for(int j=1;j<=t;j++)
   	q+=a[j];
   	for(int j=t;j<=n;j++)
   	h+=a[j];
   	if(q==h)
   	sum++;
   }while(next_permutation(a+1,a+1+n));
   printf("%d",sum);
   return 0;
}