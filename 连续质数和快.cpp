#include <cstdio>
#define MX 1e9
#define MN -1e9
typedef long long int ll;
using namespace std;
int pri[10000];
int bet[10000];
bool isp[100010];
ll cnt;
inline ll solve(ll tar){           //����������
    ll i=0,j=0,tol=0;              //��ʵ����д�ɺ�����ֱ�Ӹ�����ȥ�Ϳ��ԡ�
    do{                        
        j++;
        while(bet[j]-bet[i]>tar)      //����ֻ����һ��ѭ����������ѭ���Ļ��һЩ��
            i++;                      //�ܶ������е����ⶼ������һ��ѭ����ɡ�
        if(bet[j]-bet[i]==tar)        //��Щ������Ĺ�ͬ�ص��ǣ�
            tol++;                    //�����ǰ���в�������������ͬ�����������ж��������㡣
    }while(j>i);                      //Ҳ����˵...���б���������ģ���
    return tol;                    
}
int main(){
    ll i,j,n,tar;
    bet[cnt]+=pri[cnt];
    for(i=2;i<=100010;i++){               //�ð���ɸɸѡ����
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
