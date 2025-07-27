#include <iostream>
using namespace std;
int t,n,res,k;
int main ()
{
	cin>>t;
	while(t--)
	{
		res=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			if(k&1)
			res++;
		}
		cout<<res<<endl;
	}
	return 0;
}