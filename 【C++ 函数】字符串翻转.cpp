#include <bits/stdc++.h>
using namespace std;
void fun(string &a,string b)
{
	int l=b.size();
	for(int i=l-1;i>=0;i--)
	{
		a+=b[i];
	}
}
int main ()
{
	string s;
	while(getline(cin,s))
	{
		string o;
		fun(o,s);
		cout<<o<<endl;
	}
	return 0;
}