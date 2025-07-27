#include <iostream>
using namespace std;
int main ()
{
    int n=111*111*111,ans;
    for(int i=1;;i+=2)
    {
       ans=0;
       ans+=i;
       for(int j=i+2;ans<n;j+=2)
       {
       	ans+=j;
	   }
	   if(ans==n)
	   {
	   	cout<<i;
	   	return 0;
	   }
	}
	return 0;
}