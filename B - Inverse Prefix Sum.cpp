#include <iostream>
using namespace std;
typedef long long ll;
ll n,s[1010];
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		cout<<s[i]-s[i-1]<<" ";
	}
	return 0;
}