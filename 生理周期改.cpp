#include<cmath>
#include<iostream>
using namespace std;
int ti,gan,zhi,t,j;
int main()
{
    cin>>ti>>gan>>zhi>>t;
    for(j=t+1;j<=21252;j++)//�ӵ�ǰ����������ʼö��
        if((j-ti)%23==0)
        break;
    for(;j<=21252;j+=23)//�ҵ������߷��ڵĵ�һ�������Ҫ��֤������ÿһ�춼�������߷��ڣ����ھͱ����23.
        if((j-gan)%28==0)
        break;
    for(;j<=21252;j+=23*28)//�ҵ������͸���߷��ں�Ҫ��֤������ÿһ�춼���������ĸ߷��ڣ�������Ϊ���߳˻�
        if((j-zhi)%33==0)//�ҵ�����ͬʱ����һ�����ѭ��
        break;
    cout<<j-t;//����࿪ʼʱ��������������
    return 0;
}

