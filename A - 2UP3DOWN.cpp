#include <iostream>
using namespace std;
int x,y;
int main ()
{
	cin>>x>>y;
	if(x>y)
	{
		if(x-y<=3) puts("Yes");
		else puts("No");
	}
	else
	{
		if(y-x<=2) puts("Yes");
		else puts("No");
	}
	return 0;
}