#include <bits/stdc++.h>
using namespace std;
vector<char> vec;
string u="WHERETHEREISAWILLTHEREISAWAY";
int main ()
{
	for(int i=0;i<u.size();i++)
	{
		vec.push_back(u[i]);
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<u.size();i++)
	cout<<vec[i];
	return 0;
}