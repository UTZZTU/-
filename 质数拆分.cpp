#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
bool fun(int n)
{
  if(n==1||n==0)
  return false;
  else if(n==2||n==3)
  return true;
  else if(n%6!=1&&n%6!=5)
  return false;
  else
  {
    for(int i=5;i<=floor(sqrt(n));i+=6)
    {
      if(n%i==0||n%(i+2)==0)
      return false;
    }
return true;
  }
}
ll a[2500]={1};
int main()
{
	int pre[2000],k=1;
for(int i=1;i<=2019;i++)
{
  if(fun(i))
  pre[k++]=i;
}
for(int i=1;i<k;i++)
{
	for(int j=2019;j>=pre[i];j--)
	{
		a[j]+=a[j-pre[i]];
	}
}
cout<<a[2019];
  return 0;
}