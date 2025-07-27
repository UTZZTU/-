#include <bits/stdc++.h>//版权归熬夜的Alan Walker所以，侵权必究 
using namespace std;//使用命名空间 
int x,y,m,numone,numtwo;//定义所需要的变量 
char n;//定义所需要的字符 n 
int main() {
	vector<int> c;//定义vector数组 
	cin>>x>>y;//输入x，y。x为数组个数，y为插入或删除个数 
	for (int i = 0; i < x; i++) {
		cin>>m;//输入末尾的数 
		c.push_back(m);//添加 
	}
	for(int i=0; i<y; i++) {//不可使用Switch，否则判断不了 
		cin>>n;//输入字符 
		if(n=='D') {
			cin>>numone;//删除的数 
			if(numone<c.size())//可以判断是否大于数组，如果不是就执行，否则就不执行 
			c.erase(c.begin() + numone);//
		}
		if(n=='Z') {
			cin>>numone>>numtwo;
			if(numone>c.size())//判断是否大于数组，是就加入到后面 
			c.push_back(numtwo);
			else
			c.insert(c.begin()+numone, numtwo);//不是就直接插入 
		}
	}
	cout<<c.size()<<endl;//输出个数 
	for (int i = 0; i < c.size(); i++)
		cout << c[i] << " ";//输出数组 
	return 0;//退出 
}
