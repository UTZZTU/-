#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s;
		vector<char> vec;
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]=='a'||s[i]=='e')
			{
				vec.push_back(s[i]);
				i--;
				vec.push_back(s[i]);
				if(i!=0)
				vec.push_back('.');
			}
			else
			{
				vec.push_back(s[i]);
				i--;
				vec.push_back(s[i]);
				i--;
				vec.push_back(s[i]);
				if(i!=0)
				vec.push_back('.');
			}
		}
		reverse(vec.begin(),vec.end());
		for(int i=0;i<vec.size();i++) cout<<vec[i];
		cout<<endl;
	}
	return 0;
}