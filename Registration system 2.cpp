#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	getchar();
	string a;
	map<string,int> p;
	while(n--)
	{
		getline(cin,a);
		map<string,int>::iterator it=p.find(a);
		if(it==p.end())
		{
			printf("OK\n");
			p[a]=1;
		}
		else
		{
			cout<<a<<p[a]<<endl;
			p[a]++;
		}
	}
	return 0;
}