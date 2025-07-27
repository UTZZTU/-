#include <iostream>
using namespace std;
string s,u;
int n;
int main ()
{
	cin>>n;
	getchar();
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(i+1<s.size())
		{
			if(s[i]=='n'&&s[i+1]=='a')
			{
				u+="nya";
				i++;
			}
			else
			u+=s[i];
		}
		else
		{
			u+=s[i];
		}
	}
	cout<<u;
	return 0;
}