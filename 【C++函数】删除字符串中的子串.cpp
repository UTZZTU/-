#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void fun(string& a,string& b)
{
	int p;
	p=a.find(b);
	while(p!=-1)
	{
		a.erase(p,b.size());
		p=a.find(b);
	}
}
int main ()
{
	string a,b;
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		cin>>a;
		cin>>b;
		fun(a,b);
		cout<<a<<endl;
	}
	return 0;
}