#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main ()
{
	set<string> p;
	int n;
	cin>>n;
	getchar();
	while(n--)
	{
		string a;
		getline(cin,a);
		set<string>::iterator it=p.find(a);
		if(it==p.end())
		{
			p.insert(a);
			printf("OK\n");
		}
		else
		{
			for(int i=1;;i++)
			{
				string m,l;
				int k=i;
				m+=a;
				while(k!=0)
				{
					l+='0'+k%10;
					k/=10;
				}
				reverse(l.begin(),l.end());
				m+=l;
				set<string>::iterator it=p.find(m);
				if(it==p.end())
				{
					cout<<m<<endl;
					p.insert(m);
					break;
				}
			}
		}
	}
	return 0;
}