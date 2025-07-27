#include <iostream>
#include <stack>
using namespace std;
int n;
string s;
stack<char> st;
int main ()
{
	cin>>n;
	getchar();
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==',')
		{
			if(st.empty())
			{
				s[i]='.';
			}
		}
		else if(s[i]=='"')
		{
			if(st.empty())
			st.push(',');
			else
			st.pop();
		}
	}
	cout<<s;
	return 0;
}