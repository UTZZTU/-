#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

char str[100010];
int cnt,cur;

int main()
{
    scanf("%s",str);
    vector<char> a(str,str+strlen(str));
    for(int i = 0; i < a.size(); i++)
    {
        if(i != 0 && a[i] == a[i-1])
        {
            cur = i-2;
            a.erase(a.begin()+i-1,a.begin()+i+1);
            cnt++;
            if(cur-2 >= 0)
            {
                i = cur-3;
            }
            else
            {
                i = -1;
            }
        }

    }
    if(cnt%2==0)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }
    return 0;
}
