#include <bits/stdc++.h>
using namespace std;
char s[110];
char w[10][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int r[110],k=1;
int main ()
{
	int tot=0;
	cin>>s;
	for(int i=0;s[i]!='\0';i++)
	{
		tot+=s[i]-'0';
	}
	while(tot!=0)
	{
		r[k]=tot%10;
		tot/=10;
		k++;
	}
	for(int i=k-1;i>=1;i--)
	{
		if(i!=k-1)
		cout<<" ";
		cout<<w[r[i]];
	}
	return 0;
}