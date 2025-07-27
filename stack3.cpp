#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
int main ()
{
	stack<char> p;
	string s;
    getline(cin,s);
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]=='(')
		p.push(s[i]);
		else if(s[i]==')')
		{
			if(!p.empty()&&p.top()=='(')
			p.pop();
			else
			p.push(s[i]);
		}
	}
	if(p.size()==0)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}