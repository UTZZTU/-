#include <iostream>
#include <string>
using namespace std;
int main ()
{
	int t;
	cin>>t;
	getchar();
	for(int i=1;i<=t;i++)
	{
		string a;
		cin>>a;
		int l=a.size();
		if(l<=2)
		cout<<a<<endl;
		else
		{
			for(int j=0;j<l;j++)
			{
				if(j==0||j==1)
				cout<<a[j];
				else if(j&1)
				cout<<a[j];
			}
			cout<<endl;
		}
	}
	return 0;
}