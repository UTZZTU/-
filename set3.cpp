#include <iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;
 
multiset<int> s;///set容器是有序的
vector<int> v;
multiset<int>::iterator it;//迭代器
int policy;
 void a()//添加进程
{
    int cost;
    cin>>cost;
    s.insert(cost);
}
void re_policy(int policy)//根据当前策略删除
{
    switch(policy)
    {
    case 1:
        if (s.empty())
            cout << "-1" << endl;//当队列为空时输出-1；
        else
        {
            it = s.begin();//找到花费最小的进程（set容器的开头处（因为其有序的））
            v.push_back((*it));//向vector中添加进程（被删除）
            s.erase(it);//在进程中移除
        }
        break;
    case 2:
        if(s.empty())
            cout << "-1" << endl;
        else
        {
            int size = s.size();
            for (it = s.begin(); it != s.end(); it++)
            {
                size--;
                if (size == 0)
                {
                    break;
                }
            }//找到set最后一个元素（即花费最大的元素）
            v.push_back((*it));
            s.erase(it);
            break;
        }
    }
}
void p()//输入策略
{
    cin>>policy;
}
int main()
{
    int maxcost,re_num,i;
    char oper;
    //bool flag;
    int re[1000];
    while(cin>>maxcost>>re_num)//输入最大花费和删除列表的进程数
    {
        for(i=0;i<re_num;i++)
            cin>>re[i];
            //flag=false;
            s.clear();
            v.clear();
           // count1=0;
            policy=1;
            while(cin>>oper&&oper!='e')//输入操作符
            {
                switch(oper)
                {
                case 'a':a();
                    break;
                case 'r':re_policy(policy);
                    break;
                case 'p':p();
                    break;
                }
            }
            for(i=0;i<re_num;i++)
            {
                cout<<v[re[i]-1]<<endl;//输出和删除列表中的顺序数相同的进程的花费
            }
            cout<<endl;
    }
    return 0;
}