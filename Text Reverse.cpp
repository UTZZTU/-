#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main ()
{
	char s[1010];
	int n,i;
	cin>>n;
	getchar();
	for(i=1;i<=n;i++)
	{
		stack<char> p;
		gets(s);
		int j;
		char c;
		for(j=0;s[j]!='\0';j++)
		{
			if(s[j]==' ')
			{
				while(!p.empty())
				{
					c=p.top();
					p.pop();
					cout<<c;
				}
				printf(" ");
			}
			else
			{
				p.push(s[j]);
			}
		}
		while(!p.empty())
				{
					c=p.top();
					p.pop();
					cout<<c;
				}
				printf("\n");
	}
	return 0;
}