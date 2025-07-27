#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int ans=0;
	string a,b;
	cin>>a;
	b=a;
	sort(b.begin(),b.end());
	do
	{
		if(a==b)
		{
			cout<<ans;
			return 0;
		}
		else
		ans++;
	}while(next_permutation(b.begin(),b.end()));
	return 0;
}