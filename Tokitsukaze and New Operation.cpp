#include <bits/stdc++.h>
using namespace std;
int t;
string a,b;
int main ()
{
	cin>>t;
	getchar();
	while(t--){
		cin>>a>>b;
		if(a.size()!=b.size())
		cout<<-1<<endl;
		else{
			string res;
			for(int i=0;i<a.size();i++){
				int t=(a[i]-'0')*(b[i]-'0');
				res+=to_string(t);
			}
			cout<<res<<endl;
		}
	}
	return 0;
}