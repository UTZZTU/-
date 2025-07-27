#include <iostream>
#include <algorithm>
using namespace std;
string s[110];
int n,k;
int main ()
{
	cin>>n>>k;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+1+k);
	for(int i=1;i<=k;i++)
	cout<<s[i]<<endl;
	return 0;
}