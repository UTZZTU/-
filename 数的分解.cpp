#include <iostream>
using namespace std;
int fun(int n)
{
  while(n!=0)
  {
    if(n%10==2||n%10==4)
    return 0;
    n/=10;
  }
  return 1;
}
int main()
{
  // 请在此输入您的代码
int sum=0,i,j,k;
for(i=1;i<=2019;i++)
{
  for(j=i+1;j<=(2019-i)/2;j++)
  {
    k=2019-i-j;
    if(k!=i&&k!=j&&fun(i)!=0&&fun(j)!=0&&fun(k)!=0)
    sum++;
  }
}
cout<<sum;
  return 0;
}