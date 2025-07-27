#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
	cin>>s;
	vector<int> vec1,vec2;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			if(s[i]=='b')
			{
				if(vec1.size()) vec1.pop_back();
			}
			else
			{
				vec1.push_back(i);
			}
		}
		else
		{
			if(s[i]=='B')
			{
				if(vec2.size()) vec2.pop_back();
			}
			else
			{
				vec2.push_back(i);
			}
		}
	}
	vec1.insert(vec1.end(),vec2.begin(),vec2.end());
	sort(vec1.begin(),vec1.end());
	string v;
	for(int i=0;i<vec1.size();i++)
	{
		v+=s[vec1[i]];
	}
	cout<<v<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}