#include <bits/stdc++.h>
using namespace std;
int t,n,res;
double maxx;
string s;
int main ()
{
	cin>>t;
	while(t--){
		cin>>n;
		getchar();
		cin>>s;
		maxx=0;
		for(int i=1;i<=n;i++){
			unordered_map<char,int> mp;
			res=0;
			for(int j=i;j<=n;j++){
				mp[s[j-1]]++;
				if(mp[s[j-1]]==2){
					res++;
				}
				else if (mp[s[j-1]]>2){
					res-=(mp[s[j-1]]-1)*(mp[s[j-1]]-2)/2;
					res+=(mp[s[j-1]])*(mp[s[j-1]]-1)/2;
				}
				maxx=max(maxx,res*1.0/(j-i+1));
			}
		}
		printf("%.6f\n",maxx);
	}
	return 0;
}