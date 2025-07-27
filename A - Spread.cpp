#include <iostream>
using namespace std;
string s;
int main ()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(i) cout<<" ";
		cout<<s[i];
	}
	return 0;
}