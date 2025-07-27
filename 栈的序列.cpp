#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	getchar();
	while(n--)
	{
		string a,b;
		cin>>a>>b;
		stack<char> p;
		int i,j=0;
		if(a.size()!=b.size())
		{
			printf("NO\n");
		}
		else
		{
			for(i=0;a[i]!='\0';i++)
		{
			if(a[i]==b[j])
			{
				j++;
				while(!p.empty()&&p.top()==b[j]&&j<b.size())
				{
					p.pop();
					j++;
				}
			}
			else
			p.push(a[i]);
		}
		if(p.empty())
		printf("YES\n");
		else
		printf("NO\n");
		}
		
	}
	return 0;
}