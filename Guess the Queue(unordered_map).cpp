#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <unordered_map>

using namespace std;

deque<long long> a;
deque<long long>::iterator cur;
unordered_map<long long,long long> b;
unordered_map<long long,long long>::iterator pos;
int n,t,cnt,op;
long long tmp;

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        printf("Case %d:\n",++cnt);
        scanf("%d",&t);
        for(int i = 0; i < t; i++)
        {
           scanf("%d",&op);
           if(op == 1)
           {
               char ch;
               long long num;
               scanf(" %c",&ch);
               scanf("%lld",&num);
               if(!b.empty())
               {
                    if(ch == 'B')
                    {
                        b.insert(pair<int,int>(num,b.size()+1-tmp));
                    }
                    else
                    {
                        tmp++;
                        b.insert(pair<int,int>(num,1-tmp));
                    }
               }
               else
               {
                   b.insert(pair<int,int>(num,1-tmp));
               }
               if(ch == 'B')
               {
                   a.push_back(num);
               }
               else
               {
                   a.push_front(num);
               }
           }
           else if(op == 2)
           {
                char ch;
                scanf(" %c",&ch);
                if(ch == 'B')
                {
                    b.erase(a.back());
                    a.pop_back();
                }
                else
                {
                    b.erase(a.front());
                    a.pop_front();
                    tmp--;
                }
           }
           else
           {
                char ch;
                long long num;
                scanf(" %c",&ch);
                scanf("%lld",&num);
                if(ch == 'D')
                {
                    printf("%lld\n",a[num-1]);
                }
                else
                {
                    printf("%lld\n",b[num]+tmp);
                }
           }
        }
        a.clear();
        b.clear();
    }
    return 0;
}
