#include <bits/stdc++.h>
using namespace std;
int sum,js;
int main ()
{
	int a,b;
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		js++;
		printf("%5d",i);
		if(js%5==0)
		cout<<endl;
		sum+=i;
	}
	if(js%5!=0)
	cout<<endl;
	cout<<"Sum = "<<sum;
	return 0;
}