#include <iostream>
using namespace std;
int main ()
{
    char c;
    int pd=0,js=0,zs=0;
    while(~scanf("%c",&c))
    {
        if(c=='\n')
            zs=1;
            if(c!='6')
            {
                if(pd==1)
                {
                    if(js>=10)
                    {
                        printf("27");
                    }
                    else if(js>=4)
                    {
                        printf("9");
                    }
                    else
                    {
                        for(int i=1;i<=js;i++)
                        printf("6");
                    }
                    if(zs!=1)
                    printf("%c",c);
                        js=0;
                        pd=0;
                }
                else
                    if(zs!=1)
                    printf("%c",c);
            }
            else
            {
                pd=1;
                js++;
            }
        if(zs==1)
            break;
    }
    return 0;
}