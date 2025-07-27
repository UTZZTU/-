#include <bits/stdc++.h>
using namespace std;
int a1,a2,a3,a5,n,js,js2;
double a4;
int main ()
{
	cin>>n;
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		if(k%10==0)
		a1+=k;
		if(k%5==1)
		{
			js++;
			if(js&1)
			a2+=k;
			else
			a2-=k;
		}
		if(k%5==2)
		a3++;
		if(k%5==3)
		{
			a4+=k;
			js2++;
		}
		if(k%5==4)
		{
			a5=max(a5,k);
		}
	}
	a4=a4*1.0/js2;
	if(!a1)
	cout<<"N";
	else
	cout<<a1;
	if(!js)
	cout<<" N";
	else
	cout<<" "<<a2;
	if(!a3)
	cout<<" N";
	else
	cout<<" "<<a3;
	if(!js2)
	cout<<" N";
	else
	printf(" %.1f",a4);
	if(!a5)
	cout<<" N";
	else
	cout<<" "<<a5;
	return 0;
}