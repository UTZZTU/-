#include <iostream>
#include <set>
using namespace std;
int n;
string s;
set<char> st;
int main ()
{
	cin>>n>>s;
	for(int i=0;i<s.size();i++)
	{
		st.insert(s[i]);
		if(st.size()==3)
		{
			cout<<i+1;
			return 0;
		}
	}
	return 0;
}