#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N = 1e7;
typedef pair<int,int>PII;
int n;
unordered_map<int,PII>S;
int main()
{
    cin>>n;
    for(int c = 0;c*c <= n;c++)
    {
        for(int d = c;c*c + d*d <= n;d++)
        {
            int p = c*c + d*d;
            if(S.count(p)==0)
            {
                S[c*c+d*d] = {c,d};
            }
        }
    }
    for(int a=0;a*a<=n;a++)
    {
        for(int b=a;a*a+b*b<=n;b++)
        {
            int t = n - a*a - b*b;
            if(S.count(t))
            {
                printf("%d %d %d %d\n",a,b,S[n- a*a - b*b].first,S[n-a*a-b*b].second);
                return 0;
            }
        }
    }
    return 0;
}
