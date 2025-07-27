#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s;
		int i=0,j=n-1;
		while(i<n&&s[i]=='B') i++;
		while(j>=0&&s[j]=='A') j--;
		if(i>=j) printf("0\n");
		else
		{
			printf("%d\n",j-i);
		}
	}
	return 0;
}