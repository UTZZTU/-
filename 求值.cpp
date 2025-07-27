#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
  // 请在此输入您的代码
  int sum=0,i,j;
  for(i=7;;i++)
  {
    sum=0;
    for(j=1;j<=i;j++)
    if(i%j==0)
    sum++;
    if(sum==100)
    {
      printf("%d",i);
      return 0;
    }
  }
  return 0;
}