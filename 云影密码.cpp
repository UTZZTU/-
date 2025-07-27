#include <bits/stdc++.h>
using namespace std;
int t;
int main ()
{
	cin>>t;
	getchar();
	while(t--){
		string u,v;
		int res=0;
		cin>>u;
		for(int i=0;i<u.size();i++){
			if(u[i]=='0')
			{
				v+='a'+(res-1);
				res=0;
			}
			else
			res+=u[i]-'0';
		}
		v+='a'+(res-1);
		cout<<v<<endl;
	}
	return 0;
}