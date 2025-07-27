#include <iostream>
using namespace std;
int main ()
{
	int n,a,b;
	while(cin>>n)
	{
		a=0;
		if(n==0)
		break;
		for(int i=1;i<=n;i++)
		{
			int k;
			k=i;
			while(k%5==0)
			{
				a++;
				k/=5;
			}
		}
		printf("%d\n",a);
	}
	return 0;
}