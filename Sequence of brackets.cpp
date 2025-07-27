#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
int main ()
{
	string a;
	getline(cin,a);
	stack<char> p;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]==')')
		{
			if(!p.empty()&&p.top()=='(')
			{
				p.pop();
			}
			else
			p.push(a[i]);
		}
		else if(a[i]==']')
		{
			if(!p.empty()&&p.top()=='[')
			{
				p.pop();
			}
			else
			p.push(a[i]);
		}
		else if(a[i]=='}')
		{
			if(!p.empty()&&p.top()=='{')
			{
				p.pop();
			}
			else
			p.push(a[i]);
		}
		else if(a[i]=='>')
		{
			if(!p.empty()&&p.top()=='<')
			{
				p.pop();
			}
			else
			p.push(a[i]);
		}
		else
		p.push(a[i]);
	}
	if(p.empty())
	printf("yes");
	else
	printf("no");
	return 0;
}