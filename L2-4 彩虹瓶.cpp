#include <iostream>
#include <stack>
using namespace std;
int main ()
{
    stack<int> s;
    stack<int> w;
    int n,m,k,r,j,i;
    cin>>n>>m>>k;
    while(k--)
    {
        j=1;
        for(i=1;i<=n;i++)
        {
            cin>>r;
            if(r==j)
            {
                w.push(r);
                j++;
            }  
            else
            {
                while(s.size()!=0&&s.top()==j)
                {
                    w.push(j);
                    j++;
                    s.pop();
                }
                if(r==j)
                {
                    w.push(j);
                    j++;
                }
                else 
                {
                    if(s.size()<m)
                    s.push(r);
            }
              while(s.size()!=0&&s.top()==j)
                {
                    w.push(j);
                    j++;
                    s.pop();
                }  
        }
           
    }
       while(s.size()!=0&&s.top()==j)
                {
                    w.push(j);
                    j++;
                    s.pop();
                } 
            if(w.size()==n)
                printf("YES\n");
            else
                printf("NO\n");
        while(!s.empty())
            s.pop();
        while(!w.empty())
            w.pop();
}
 return 0;
}