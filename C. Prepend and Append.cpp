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
		int i=0,j=s.size()-1;
		while(i<j)
		{
			if(s[i]=='0'&&s[j]=='1'||s[i]=='1'&&s[j]=='0')
			i++,j--;
			else
			break;
		}
		cout<<max(0,j-i+1)<<endl;
	}
	return 0;
}