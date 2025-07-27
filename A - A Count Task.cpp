#include <iostream>
using namespace std;
typedef long long ll;
ll t,res,num;
string s;
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>s;
		res=0;
		for(int i=0;i<s.size();i++)
		{
			num=1;
			int j=i+1;
			while(j<s.size()&&s[j]==s[i])
			{
				num++;
				j++;
			}
			i=j-1;
			res+=num*(num+1)/2;
		}
		cout<<res<<endl;
	}
	return 0;
}