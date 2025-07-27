#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main ()
{
	stack<char> p;
	string a;
	getline(cin,a);
	for(int i=0;i<a.length();i++)
	{
		if(!p.empty()&&p.top()==a[i])
		{
			p.pop();
		}
		else
		p.push(a[i]);
	}
	if(p.empty())
	printf("Yes");
	else
	printf("No");
	return 0;
}