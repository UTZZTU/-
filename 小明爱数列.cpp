#include <bits/stdc++.h>//��Ȩ�鰾ҹ��Alan Walker���ԣ���Ȩ�ؾ� 
using namespace std;//ʹ�������ռ� 
int x,y,m,numone,numtwo;//��������Ҫ�ı��� 
char n;//��������Ҫ���ַ� n 
int main() {
	vector<int> c;//����vector���� 
	cin>>x>>y;//����x��y��xΪ���������yΪ�����ɾ������ 
	for (int i = 0; i < x; i++) {
		cin>>m;//����ĩβ���� 
		c.push_back(m);//��� 
	}
	for(int i=0; i<y; i++) {//����ʹ��Switch�������жϲ��� 
		cin>>n;//�����ַ� 
		if(n=='D') {
			cin>>numone;//ɾ������ 
			if(numone<c.size())//�����ж��Ƿ�������飬������Ǿ�ִ�У�����Ͳ�ִ�� 
			c.erase(c.begin() + numone);//
		}
		if(n=='Z') {
			cin>>numone>>numtwo;
			if(numone>c.size())//�ж��Ƿ�������飬�Ǿͼ��뵽���� 
			c.push_back(numtwo);
			else
			c.insert(c.begin()+numone, numtwo);//���Ǿ�ֱ�Ӳ��� 
		}
	}
	cout<<c.size()<<endl;//������� 
	for (int i = 0; i < c.size(); i++)
		cout << c[i] << " ";//������� 
	return 0;//�˳� 
}
