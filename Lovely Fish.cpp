#include <iostream>
#include <string>
using namespace std;
int o;
int main ()
{
    string a,b;
    int n,q,l,r,s;
    cin>>n>>q;
    s=q;
    getchar();
    cin>>a;
    while(q--)
    {
    	cin>>l>>r;
    	b.assign(a,l-1,r);
    	int jc=0,i,sum=0;
    	for(i=0;i<r-l+1;i++)
    	{
    		if(b[i]=='0')
    		sum++;
    		if(sum>(i+1-sum+jc))
    		{
    			jc++;
			}
		}
		if(b[i-1]=='0')
		jc++;
		if(q==s)
		o=jc;
		else
		o^=jc;
	}
	cout<<o;
	return 0;
}