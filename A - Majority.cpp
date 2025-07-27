#include <iostream>
using namespace std;
string u="For",v;
int n,num;
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>v;
		if(v==u)
		num++;
	}
	if(num>n-num)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}