#include <iostream>
using namespace std;
int k;
int main ()
{
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cout<<(char)('A'+i-1);
	}
	return 0;
}