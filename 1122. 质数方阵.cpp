#include<bits/stdc++.h>
#define f(a,b,c) for(int c=a;c<=b;c++)
using namespace std;
const int N=1000;
int mapp[N][N],len=0,n,m,num=0;
int shusu[11][11][11][11][11]={};
int susu[5]={0,1,3,7,9};
bool su[1010000]={};
string ans[N];
void primes()
{
    for(int i=2;i<=99999;i++)
    {
        if(su[i]) continue;
        if(i>=10000) 
        {
            shusu[(i/10000)][(i/1000)%10][(i/100)%10][(i/10)%10][i%10]=1;
        }
        for(int j=i;j<=99999/i;j++) su[i*j]=1;
    }
}
int main()
{
  primes();
  scanf("%d%d",&n,&m);
  mapp[1][1]=m;
  f(1,4,i1)
  {
    mapp[5][5]=susu[i1];
    f(0,9,i2)
    {
      mapp[4][4]=i2;
      f(0,9,i3)
      {
        mapp[3][3]=i3;
        mapp[2][2]=n-mapp[1][1]-mapp[3][3]-mapp[4][4]-mapp[5][5];
        if(mapp[2][2]<0) continue;
        if(mapp[2][2]>9) continue;
        if(!shusu[mapp[1][1]][mapp[2][2]][mapp[3][3]][mapp[4][4]][mapp[5][5]]) continue;
        f(1,4,i4)
        {
          mapp[3][5]=susu[i4];
          f(1,4,i5)
          {
            mapp[2][5]=susu[i5];
            f(1,4,i6)
            {
              mapp[1][5]=susu[i6];
              mapp[4][5]=n-mapp[1][5]-mapp[2][5]-mapp[3][5]-mapp[5][5];
              if(mapp[4][5]<0) continue;
              if(mapp[4][5]>9) continue;
              if(!shusu[mapp[1][5]][mapp[2][5]][mapp[3][5]][mapp[4][5]][mapp[5][5]]) continue;
              f(1,9,i7)
              {
                mapp[4][1]=i7;
                f(0,9,i8)
                {
                  mapp[4][2]=i8;
                  mapp[4][3]=n-mapp[4][1]-mapp[4][2]-mapp[4][4]-mapp[4][5];
                  if(mapp[4][3]<0) continue;
                  if(mapp[4][3]>9) continue;
                  if(!shusu[mapp[4][1]][mapp[4][2]][mapp[4][3]][mapp[4][4]][mapp[4][5]]) continue;
                  f(1,4,i9)
                  {
                    mapp[5][3]=susu[i9];
                    f(0,9,i10)
                    {
                      mapp[2][3]=i10;
                      mapp[1][3]=n-mapp[2][3]-mapp[3][3]-mapp[4][3]-mapp[5][3];
                      if(mapp[1][3]<0) continue;
                      if(mapp[1][3]>9) continue;
                      if(!shusu[mapp[1][3]][mapp[2][3]][mapp[3][3]][mapp[4][3]][mapp[5][3]]) continue;
                      f(1,9,i11)
                      {
                        mapp[1][4]=i11;
                        mapp[1][2]=n-mapp[1][1]-mapp[1][3]-mapp[1][4]-mapp[1][5];
                        if(mapp[1][2]<0) continue;
                        if(mapp[1][2]>9) continue;
                        if(!shusu[mapp[1][1]][mapp[1][2]][mapp[1][3]][mapp[1][4]][mapp[1][5]]) continue;
                        f(1,4,i12)
                        {
                          mapp[5][2]=susu[i12];
                          mapp[3][2]=n-mapp[1][2]-mapp[2][2]-mapp[4][2]-mapp[5][2];
                          if(mapp[3][2]<0) continue;
                          if(mapp[3][2]>9) continue;
                          if(!shusu[mapp[1][2]][mapp[2][2]][mapp[3][2]][mapp[4][2]][mapp[5][2]]) continue;
                          f(0,9,i13)
                          {
                            mapp[2][4]=i13;
                            mapp[5][1]=n-mapp[4][2]-mapp[3][3]-mapp[2][4]-mapp[1][5];
                            if(mapp[5][1]<0) continue;
                            if(mapp[5][1]>9) continue;
                            if(!shusu[mapp[5][1]][mapp[4][2]][mapp[3][3]][mapp[2][4]][mapp[1][5]]) continue;
                            mapp[5][4]=n-mapp[5][1]-mapp[5][2]-mapp[5][3]-mapp[5][5];
                            if(mapp[5][4]<0) continue;
                            if(mapp[5][4]>9) continue;
                            if(!shusu[mapp[5][1]][mapp[5][2]][mapp[5][3]][mapp[5][4]][mapp[5][5]]) continue;
                            mapp[3][4]=n-mapp[1][4]-mapp[2][4]-mapp[4][4]-mapp[5][4];
                            if(mapp[3][4]<0) continue;
                            if(mapp[3][4]>9) continue;
                            if(!shusu[mapp[1][4]][mapp[2][4]][mapp[3][4]][mapp[4][4]][mapp[5][4]]) continue;
                            mapp[3][1]=n-mapp[3][2]-mapp[3][3]-mapp[3][4]-mapp[3][5];
                            if(mapp[3][1]<0) continue;
                            if(mapp[3][1]>9) continue;
                            if(!shusu[mapp[3][1]][mapp[3][2]][mapp[3][3]][mapp[3][4]][mapp[3][5]]) continue;
                            mapp[2][1]=n-mapp[1][1]-mapp[3][1]-mapp[4][1]-mapp[5][1];
                            if(mapp[2][1]<0) continue;
                            if(mapp[2][1]>9) continue;
                            if(!shusu[mapp[1][1]][mapp[2][1]][mapp[3][1]][mapp[4][1]][mapp[5][1]]) continue;
                            if(!shusu[mapp[2][1]][mapp[2][2]][mapp[2][3]][mapp[2][4]][mapp[2][5]]) continue;
                            /*f(1,5,ii)
                            {
                              f(1,5,ji)
                              {
                                printf("%d",mapp[ii][ji]);
                              }
                              printf("\n");
                            }
                            printf("\n");*/

                            num++;
                            f(1,5,i)
                            f(1,5,j)
                            ans[num]+=mapp[i][j]+'0';
                          } 
                        }
                      }
                    } 
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  sort(ans+1,ans+num+1);
  bool fl=0;
  f(1,num,i)
  {
    if(fl) printf("\n");
    f(0,24,j)
    {
        printf("%c",ans[i][j]);
        if((j+1)%5==0) printf("\n");
    }
    fl=1;
  }
  if(!num) printf("NONE");
  return 0;
} 
