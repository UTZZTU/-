#include <bits/stdc++.h>
using namespace std;
int n,pd;
bool judge(int x)
{
	if(x==2||x==3)
	return true;
	else if(x%6!=1&&x%6!=5)
	return false;
	else
	{
		for(int i=5;i<=floor(sqrt(x));i+=6)
		{
			if(x%i==0||x%(i+2)==0)
			return false;
		}
		return true;
	}
}
int main ()
{
    while(cin>>n)
    {
    	pd=0;
    	for(int i=2;i<n;i++)
    	{
    		if(i%10==1&&judge(i))
    		{
    			pd=1;
    			cout<<i<<" ";
			}
		}
		if(!pd)
		cout<<-1;
		cout<<endl;
	}
	return 0;
}