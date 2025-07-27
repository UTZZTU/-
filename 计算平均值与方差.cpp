#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int n;
	while(cin>>n)
	{
		int a[25];
		double sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		sum=sum*1.0/n;
		printf("%.2f ",sum);
		double s=0;
		for(int i=1;i<=n;i++)
		{
			s+=(a[i]-sum)*(a[i]-sum);
		}
		s=s*1.0/n;
		printf("%.2f\n",s);
	}
	return 0;
}
