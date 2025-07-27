#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string a("陈同帅太强了");
	string b("wfl");
	cout<<a<<endl;
	cout<<b<<endl;
	b.swap(a);
	cout<<a<<endl;
	cout<<b<<endl;
	return 0;
}