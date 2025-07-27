#include <iostream>
#include <stack>
using namespace std;
int main ()
{
	int n;
	while(cin>>n)
	{
		stack<int> p;
		while(n!=0)
		{
			p.push(n%2);
			n/=2;
		}
		while(!p.empty())
		{
			cout<<p.top();
			p.pop();
		}
		cout<<endl;
	}
	return 0;
}