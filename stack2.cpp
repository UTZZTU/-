#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main ()
{
	stack<char> p;
	char s;
	while(cin>>s)
	{
		if(s=='@')
		break;
		else if(s=='(')
		p.push(s);
		else if(s==')')
		{
			if(!p.empty()&&p.top()=='(')
			p.pop();
			else
			p.push(s);
		}
	}
	if(p.empty())
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}