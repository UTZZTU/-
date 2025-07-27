#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int res=0;
int main ()
{
	cin>>s;
//	for(int i=s.size()-1;i>=0;i--)
//	{
//		if((s[i]-'0')&1) res++;
//	}
	int i=s.size()-1;
	while(i>=0&&(s[i]-'0')&1)
	{
		res++;
		i--;
	}
	cout<<res;
	return 0;
}