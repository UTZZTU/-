#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll va,vb,vc,a,b,c,t;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>va>>vb>>vc;
		if((va+vc-vb)&1||(va+vb-vc)&1||(vb+vc-va)&1)
		cout<<"No"<<endl;
		else
		{
			a=(vb+vc-va)/2;
			b=(va+vc-vb)/2;
			c=(va+vb-vc)/2;
			if(a<=0||b<=0||c<=0||a>=b+c||b>=a+c||c>=a+b)
			cout<<"No"<<endl;
			else
			{
				cout<<"Yes"<<endl;
				cout<<a<<" "<<b<<" "<<c<<endl;
			}
		}
	}
	return 0;
}