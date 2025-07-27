#include <iostream>
using namespace std;
int main ()
{
	string s,t;
	cin>>s>>t;
	int ans=0,a=0,b=0;
	for(a;a<s.size()&&b<t.size();a++)
	{
		if(s[a]==t[b])
		{
			ans++;
			b++;
		}
	}
	cout<<ans;
	return 0;
}