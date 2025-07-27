#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
typedef long long ll;
int main ()
{
	ll sum=0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	map<string,int> mp;
	string a;
	while(getline(cin,a))
	{
		mp[a]++;
		sum++;
	}
	map<string,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		cout<<it->first<<" "<<fixed << setprecision(4) << it->second*100.0/sum << endl;
	}
	return 0;
}