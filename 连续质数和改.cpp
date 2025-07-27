
#include <iostream>
using namespace std;
const int maxp = 2000, n = 10000;
int prime[maxp], total = 0;
bool isprime(int k) //bool��������������
{
    for (int i = 0; i < total; i++)
        if (k % prime[i] == 0) //�ж�������һ�ַ�����������������鵱�����е� ���� ����ȡ�ࣻ
            return false;
    return true;
}
int main()
{
    for (int i = 2; i < n; i++)
        if (isprime(i))
            prime[total++] = i; //total++�����ú�ӡ��˴�֮ǰ�Ĵ����ǰ�2~n֮�������ȫ�����洢��prime[total]�����С�
    prime[total] = n + 1;
    int m,t;
    cin >> t;
    
    while (t--)
    {
	    cin >> m;
        int ans = 0;                        //���ڼ������
        for (int i = 0; prime[i] <= m; i++) //���ѭ������ö�����еĿ�����
        {
            int cnt = 0;                             //���
            for (int j = i; j < total, cnt < m; j++) //��ѭ�������ж�����͵Ĵ�С�Ƿ����
                cnt += prime[j];
            if (cnt == m)
                ++ans;
        }
        printf("%d",ans);
        if(t!=0)
        printf("\n");
    }
    return 0;
}


