#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n,s,a[8],q=3,i;
  cin>>n;
n/=10000;
s=n;
s+=1;
while(s!=0)
{
a[q]=a[7-q]=s%10;
s/=10;
q--;
}
for(i=0;i<8;i++)
cout<<a[i];
cout<<endl;
n+=100;
if(n/1000==(n%1000)/100)
n+=100;
n=n/100*100+(n/1000)*10+(n%1000)/100;
q=3;
while(n!=0)
{
  a[q]=a[7-q]=n%10;
  n/=10;
  q--;
}
for(i=0;i<8;i++)
cout<<a[i];
  return 0;
}