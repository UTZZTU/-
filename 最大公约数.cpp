#include <iostream>
using namespace std;
int fun(int x,int y)
{
	int a=max(x,y),b=min(x,y),c;
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
int main ()
{
	int a,b;
	while(cin>>a>>b)
	{
		printf("%d\n",fun(a,b));
	}
	return 0;
}