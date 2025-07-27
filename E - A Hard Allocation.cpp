#include <iostream>
using namespace std;
int t,n,m;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int y=n%m==0?0:1;
		cout<<y<<endl;
	}
	return 0;
}