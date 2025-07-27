#include <iostream>
using namespace std;
typedef long long ll;
string s;
ll res,k=1;
int main ()
{
	cin>>s;
	for(int i=s.size()-1;i>=0;i--)
	{
		res+=k*(s[i]-'A'+1);
		k*=26;
	}
	cout<<res;
	return 0;
}