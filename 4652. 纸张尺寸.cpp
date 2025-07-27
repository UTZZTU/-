#include <bits/stdc++.h>
using namespace std;
string s;
int lo=1189,sh=841;
int main ()
{
	cin>>s;
	for(int i=0;i<s[1]-'0';i++)
	{
		lo/=2;
		swap(lo,sh);
	}
	cout<<lo<<endl<<sh;
	return 0;
}