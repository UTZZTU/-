#include <iostream>
#include <algorithm>
using namespace std;
int a[100010];
int main ()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		break;
		else
		{
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			sort(a+1,a+1+n);
			cout<<(a[n]-a[1])*2<<endl;
		}
	}
	return 0;
}