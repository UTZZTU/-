#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int n,f[100],sum;
string s;
signed main ()
{
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		int j=i;
		while(j<n&&s[j]==s[i])
		{
			j++;
		}
		j--;
		f[s[i]-'a']=max(f[s[i]-'a'],j-i+1);
		i=j;
	}
	for(int i=0;i<26;i++)
	{
		if(f[i])
		{
			sum+=f[i];
		}
	}
	cout<<sum;
	return 0;
}