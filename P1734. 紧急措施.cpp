#include <bits/stdc++.h>
using namespace std;
string email,y,m,e;
int n,cnt;
int main ()
{
    cin>>email;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>y>>m>>e;
    	if(e==email)
    	{
    		cnt++;
    		cout<<y<<" ";
    		for(auto c:m)
    		{
    			if(c>='a'&&c<='z') cout<<(char)(c-32);
    			else if(c>='A'&&c<='Z') cout<<(char)(c+32);
    			else cout<<(char)(c);
			}
			cout<<endl;
		}
	}
	if(!cnt) cout<<"empty";
    return 0;
}
