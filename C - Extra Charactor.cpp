#include <iostream>
using namespace std;
string s,t;
int main ()
{
	getline(cin,s);
	getline(cin,t);
	for(int i=0;i<t.size();i++)
	{
		if(s[i]!=t[i])
		{
			cout<<i+1;
			return 0;
		}
	}
	return 0;
}