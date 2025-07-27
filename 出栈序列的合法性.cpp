#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main ()
{
    int m,n,k,a[1010],i,js,flag;
    cin>>m>>n>>k;
    while(k--)
    {
        flag=0;
        stack<int> s;
        js=1;
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n;i++)
        {
        	s.push(i);
			if(s.size()>m)
                {
                    flag=1;
                    break;
                }
            if(i==a[js])
            {
            	s.pop();
				js++;
                while(!s.empty()&&s.top()==a[js])
                {
                    s.pop();
                    js++;
                }
            }
        }
        if(flag==1||!s.empty())
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}