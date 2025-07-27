#include <iostream>
using namespace std;
int n;
bool is_num(int x)
{
	return (x/100)*(x%100/10)==(x%10);
}
int main ()
{
	cin>>n;
	for(int i=n;i<1000;i++)
	{
		if(is_num(i))
		{
			printf("%d",i);
			break;
		}
	}
	return 0;
}