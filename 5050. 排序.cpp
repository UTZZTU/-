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
		getchar();
		cin>>s;
		vector<char> vec;
		for(int i=0;i<s.size();i++)
		{
			vec.push_back(s[i]);
		}
		sort(vec.begin(),vec.end());
		for(int i=0;i<vec.size();i++)
		cout<<vec[i];
		cout<<endl;
	}
	return 0;
}