#include <iostream>
#include <stack>
#include <string>
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
		stack<char> p1,p2;
		for(int i=0;i<a.length();i++)
		{
			if(a[i]>='a'&&a[i]<='z')
			cout<<a[i];
			else if(a[i]=='(')
			{
				p1.push(a[i]);
			}
			else if(a[i]==')')
			{
				p1.pop();
				cout<<p2.top();
				p2.pop();
			}
			else
			p2.push(a[i]);
		}
		printf("\n");
	}
	return 0;
}