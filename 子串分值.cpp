#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int a[26];
int main()
{
  // 请在此输入您的代码
string s;
cin>>s;
int l=s.size(),i,j,sum=0,gs;
for(i=0;i<l;i++)
{
  memset(a,0,sizeof(a));
  gs=0;
  for(j=i;j<l;j++)
  {
    if(a[s[j]-'a']==0)
    {
      a[s[j]-'a']++;
      gs++;
    }
    else if(a[s[j]-'a']==1)
    {
      a[s[j]-'a']++;
      gs--;
    }
    sum+=gs;
  }
}
cout<<sum;
  return 0;
}