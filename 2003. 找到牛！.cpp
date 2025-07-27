#include <bits/stdc++.h>
using namespace std;
int ans1,ans2;
string a;
int main ()
{
	getline(cin,a);
	for(int i=1;i<a.size();i++)
	{
		if(a[i]==a[i-1]&&a[i]=='(')
		ans1++;
		if(a[i]==a[i-1]&&a[i]==')')
		ans2+=ans1;
	}
	cout<<ans2;
	return 0;
}