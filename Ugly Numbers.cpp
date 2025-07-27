#include <iostream>
using namespace std;
int main ()
{
	int i=1,sum=0;
	for(i;;i++)
	{
		int k=i;
		while(k%5==0)
		{
			k/=5;
		}
		while(k%3==0)
		{
			k/=3;
		}
		while(k%2==0)
		{
			k/=2;
		}
		if(k==1)
		{
			sum++;
			if(sum==1500)
			{
				printf("%d",i);
				break;
			}
		}
	}
	return 0;
}