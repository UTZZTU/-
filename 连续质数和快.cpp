#include <cstdio>
#define MX 1e9
#define MN -1e9
typedef long long int ll;
using namespace std;
int pri[10000];
int bet[10000];
bool isp[100010];
ll cnt;
inline ll solve(ll tar){           //这是求解过程
    ll i=0,j=0,tol=0;              //其实不用写成函数，直接复制下去就可以。
    do{                        
        j++;
        while(bet[j]-bet[i]>tar)      //这里只用了一层循环，比两层循环的会快一些！
            i++;                      //很多求子列的问题都可以用一层循环完成。
        if(bet[j]-bet[i]==tar)        //那些的问题的共同特点是：
            tol++;                    //如果当前子列不满足条件，相同起点的所有子列都不会满足。
    }while(j>i);                      //也就是说...子列必须是有序的？。
    return tol;                    
}
int main(){
    ll i,j,n,tar;
    bet[cnt]+=pri[cnt];
    for(i=2;i<=100010;i++){               //用埃氏筛筛选素数
        if(isp[i])
            continue;
        pri[++cnt]=i;
        bet[cnt]=pri[cnt]+bet[cnt-1];
        for(j=i;j*i<=100010;j++){
            isp[j*i]= true;
        }
    }
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&tar);
        printf("%lld\n",solve(tar));
    }
}
