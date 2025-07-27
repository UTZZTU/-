#include <iostream>
using namespace std;
int n,res;
char s[10000];
int main ()
{
	cin>>n;
	getchar();
	cin>>s+1;
	for(int i=1;i<n;i++)
	{
		res=0;
		for(int j=1;j<=n-i;j++)
		{
			if(s[j]!=s[j+i])
			{
				res=j;
			}
			else
			break;
		}
		cout<<res<<endl;
	}
	return 0;
}