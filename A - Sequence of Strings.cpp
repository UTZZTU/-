#include <iostream>
using namespace std;
int n;
string a[100];
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}