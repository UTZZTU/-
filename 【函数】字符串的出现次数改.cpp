#include <iostream>
#include <string>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	string s,w;
	while(n--)
	{
	    cin>>s;
		int pd=0,wz2=0,ans=0;
		cin>>w;
		string u,cf;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]==w[wz2])
			{
				pd=1;
				cf+=s[i];
				wz2++;
				if(wz2==w.length())
				{
					pd=0;
					cf.clear();
					wz2=0;
					ans++;
				}
			}
			else
			{
				if(pd==0)
				{
					u+=s[i];
				}
				else
				{
					pd=0;
					cf+=s[i];
					u+=cf;
					cf.clear();
					wz2=0;
					i--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}