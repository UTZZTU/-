#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int a[4][4],wzi,wzj,i,j,b[10],qs,w1,w2,xz,sum=0;
    memset(b,0,sizeof(b));
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            cin>>a[i][j];
            b[a[i][j]]++;
            if(a[i][j]==0)
            {
                wzi=i;
                wzj=j;
            }
        }
    }
    for(i=0;i<10;i++)
    {
        if(b[i]==0)
        {
            qs=i;
            break;
        }
    }
    a[wzi][wzj]=qs;
    for(i=1;i<=3;i++)
    {
        cin>>w1>>w2;
        printf("%d\n",a[w1][w2]);
    }
    cin>>xz;
    if(xz==1)
    sum+=a[1][1]+a[1][2]+a[1][3];
    else if(xz==2)
        sum+=a[2][1]+a[2][2]+a[2][3];
    else if(xz==3)
        sum+=a[3][1]+a[3][2]+a[3][3];
    else if(xz==4)
        sum+=a[1][1]+a[2][1]+a[3][1];
    else if(xz==5)
        sum+=a[1][2]+a[2][2]+a[3][2];
    else if(xz==6)
        sum+=a[1][3]+a[2][3]+a[3][3];
    else if(xz==7)
        sum+=a[1][1]+a[2][2]+a[3][3];
    else if(xz==8)
        sum+=a[3][1]+a[2][2]+a[1][3];
    
    if(sum==6)
        printf("10,000");
    else if(sum==7)
        printf("36");
    else if(sum==8)
        printf("720");
    else if(sum==9)
        printf("360");
    else if(sum==10)
    printf("80");
    else if(sum==11)
        printf("252");
    else if(sum==12)
        printf("108");
    else if(sum==13)
        printf("72");
    else if(sum==14)
        printf("54");
    else if(sum==15)
        printf("180");
    else if(sum==16)
        printf("72");
    else if(sum==17)
        printf("180");
    else if(sum==18)
        printf("119");
    else if(sum==19)
        printf("36");
    else if(sum==20)
        printf("306");
    else if(sum==21)
        printf("1,080");
    else if(sum==22)
        printf("144");
    else if(sum==23)
        printf("1,080");
    else if(sum==24)
        printf("3,600");
    return 0;
}