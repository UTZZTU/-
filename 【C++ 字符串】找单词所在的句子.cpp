#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string a="There is no reason for any individual to have a computer in their home.",b="Computers are useless. They can only give you answers.",c="To err is human, but to really foul things up requires a computer.",d="The electronic computer is to individual privacy what the machine gun was to the horse cavalry.";
	string e;
	cin>>e;
	int p;
	p=a.find(e);
	if(p!=-1)
	cout<<a<<endl;
	p=b.find(e);
	if(p!=-1)
	cout<<b<<endl;
	p=c.find(e);
	if(p!=-1)
	cout<<c<<endl;
	p=d.find(e);
	if(p!=-1)
	cout<<d<<endl;
	return 0;
}