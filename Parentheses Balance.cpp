#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	getchar();
	while(n--)
	{
		string a;
		getline(cin,a);
		stack<char> p;
		for(int i=0;i<a.length();i++)
		{
			if(p.empty())
			{
				p.push(a[i]);
			}
			else
			{
				if(a[i]==')')
				{
					if(p.top()=='(')
					p.pop();
					else
					p.push(a[i]);
				}
				else if(a[i]==']')
				{
					if(p.top()=='[')
					p.pop();
					else
					p.push(a[i]);
				}
				else
				p.push(a[i]);
			}
		}
		if(p.empty())
		{
			printf("Yes\n");
		}
		else
		printf("No\n");
	}
	return 0;
}