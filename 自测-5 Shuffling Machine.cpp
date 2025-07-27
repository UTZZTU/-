#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int wz[55],zwz[55],k,js;
	string a[55];
	a[0]="0000";
	for(int i=1;i<53;i++)
	{
		int u=i%13;
		if(u==0)
		{
			if(i>=1&&i<=13)
		a[i]+='S';
		else if(i>=14&&i<=26)
		a[i]+='H';
		else if(i>=27&&i<=39)
		a[i]+='C';
		else
		a[i]+='D';
		a[i]+='1';
		a[i]+='3';
			continue;
		}
		if(i>=1&&i<=13)
		a[i]+='S';
		else if(i>=14&&i<=26)
		a[i]+='H';
		else if(i>=27&&i<=39)
		a[i]+='C';
		else
		a[i]+='D';
		if(u<10)
		a[i]+='0'+u;
		else
		{
		a[i]+='1';
		a[i]+='0'+u%10;	
		}
	}
	a[53]="J1",a[54]="J2";
	cin>>k;
	for(int i=1;i<=54;i++)
	cin>>wz[i];
	for(int i=1;i<=54;i++)
	{
		js=0;
		int cswz=i;
		while(js<k)
		{
			cswz=wz[cswz];
			js++;
		}
		zwz[cswz]=i;
	}
	for(int i=1;i<=54;i++)
	{
		if(i!=1)
		cout<<" ";
		cout<<a[zwz[i]];
	}
	return 0;
}