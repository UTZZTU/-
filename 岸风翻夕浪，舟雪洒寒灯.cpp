#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main ()
{
	string a,b;
	ll k,sum=1,js=1,w;
	cin>>k;
	while(k>=sum)
	{
		b=a;
		w=js;
		while(w!=0)
		{
			a+=w%10+'0';
			w/=10;
		}
		a+=b;
		js++;
		sum=2*sum+1;
	}
	b=a;
		w=js;
		while(w!=0)
		{
			a+=w%10+'0';
			w/=10;
		}
		a+=b;
	cout<<a[k-1];
	return 0;
}