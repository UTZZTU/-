#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

vector<int>record;
vector<vector<int>> result;
void print()
{
    for (auto it : record)
        cout << it << "\t";
    cout << "\n==============================="
        << endl;
}
/*n是个数，m是总数,本函数的目的是得到n个数相加和为m的所有情况
    考虑下来，可以采用递归的思想
*/
void func(int n, int m)
{
    static int index = 0;
    if (n == 2)
    {
            for (int i = 1; i < m; ++i)
            {
                record.push_back(i);
                record.push_back(m - i);
                result.push_back(record);
                cout << "case: " << ++index << endl;
                print(); 
                record.pop_back();
                record.pop_back();
            }
        
        return;
    }
    for (int beg =  1; beg <= m -2 ; ++beg)
    {
        record.push_back(beg);
        func(n - 1, m - beg);
        record.pop_back();
    }

}
int main()
{
    func(4, 19);

    return 0;
}