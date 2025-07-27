#include <iostream>
using namespace std;
typedef long long ll;
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll odd=0,even=0;
		int n,k;
		cin>>n;
		while(n--)
		{
			cin>>k;
			if(k&1)
			{
				if(k==1)
				odd++;
				else
				odd+=1+k/2;
			}
			else
			{
				if(k!=2)
				{
					even+=k/2-1;
				}
			}
		}
		if(odd>even)
		printf("Alice\n");
		else
		printf("Bob\n");
	}
	return 0;
}