#include<stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string a,b,c;
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	if(a>b)
	a.swap(b);
	if(a>c)
	a.swap(c);
	if(b>c)
	b.swap(c);
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c;
	return 0;
}