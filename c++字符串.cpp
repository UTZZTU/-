#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string a,b;
	getline(cin,a);
	for(int i=0;i<a.size();i++)
	{
		if(!(a[i]>='0'&&a[i]<='9'))
		{
			if(a[i]>='a'&&a[i]<='z')
			{
				b+=a[i]-32;
			}
			else
			b+=a[i];
		}
	}
	cout<<b;
	return 0;
}