#include <iostream>
#include <cmath>
using namespace std;
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
int main ()
{
	int i=2,pd=0,j;
	int ans=0;
	for(i;i<=20210605;i++)
	{
		if(fun(i))
		{
			pd=0;
			j=i;
			while(j!=0)
			{
				if(fun(j%10))
				j/=10;
				else
				{
					pd=1;
					break;
				}
			}
			if(pd==0)
			ans++;
		}
	}
	cout<<ans;
	return 0;
}