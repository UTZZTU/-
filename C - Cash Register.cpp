#include <iostream>
using namespace std;
int res,num;
string s;
int main ()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='0')
		{
			res++;
		}
		else
		{
			int j=i+1;
            num=1;
            while(j<s.size()&&s[j]=='0')
            {
            	num++;
            	j++;
			}
			if(num&1)
			res++;
			res+=num/2;
			i=j-1;
		}
	}
	cout<<res;
	return 0;
}