#include <bits/stdc++.h>
using namespace std;
int t;
string s,p;
int main  ()
{
	cin>>t;
	getchar();
	for(int w=1;w<=t;w++)
	{
		cin>>s>>p;
		int i=0,j=0;
		for(i;i<s.size();i++)
		{
			int judge=0;
			while(j<p.size())
			{
				if(s[i]==p[j])
				{
					judge=1;
					j++;
					break;
				}
				else
				j++;
			}
			if(!judge) break;
		}
		if(i<s.size()) cout<<"Case #"<<w<<": IMPOSSIBLE"<<endl;
		else cout<<"Case #"<<w<<": "<<p.size()-s.size()<<endl;
	}
	return 0;
}