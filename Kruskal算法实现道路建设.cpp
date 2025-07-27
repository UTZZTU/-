/*
	���ܣ�Kruskal�㷨ʵ�ֵ�·����
	���룺��ׯ������·���� ��·��Ϣ�Լ��ѽ���·��Ϣ 
	�������С���½���·���Ⱥ� 

	���뻷����Dev-C++ v5.11
	����ע�ͣ����Ĳ� 
	�޶����ڣ�2022��12��10�� 

	�ο����ף������������ݽṹ(��������󷽷���C++��������)(��3��)��
	��Σ�2021��9�µ�3��			ӡ�Σ�2021��9�µ�1��ӡˢ
	ҳ�룺PP335-9
*/
#include<iostream>
#include <algorithm>
using namespace std;
const int heh = 20;
const int max = 32767;

#define re register  //�ӿ�����ٶ� 
#define il inline    //���������������ӿ�����ٶ� 

struct Edges //���ô�ߵĽṹ�� 
{
	int u,v,w;
}edge[200005];

struct letter  //���½��ĵ�·�ߵĽṹ�� 
{
	int u,v,w;
}s[200005];
int fa[5005],n,m,ans,eu,ev,k,cnt;  //��ҪԪ�أ��粢�鼯�� 
char c1,c2;
 
il bool cmp1(Edges a,Edges b)     //��д���ź���1
{
    return a.w<b.w;
}

il bool cmp2(letter a,letter b)     //��д���ź���2
{
    if(a.u!=b.u)
    return a.u<b.u;
    else
    return a.v<b.v;
}

il int find(int x)               //find���������� 
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}

il void kruskal()
{
    sort(edge,edge+m,cmp1);
    //�Ա߼����д�С�������� 
    for(re int i=0;i<m;i++)
    {
        eu=find(edge[i].u), ev=find(edge[i].v);
        if(eu==ev)
        {
            continue;
        }
        //��������������Ƚڵ���һ���ģ��Ͳ������� 
        s[++cnt].u=edge[i].u;
        s[cnt].v=edge[i].v;
        s[cnt].w=edge[i].w;
        //����Ҫ�����µ�·����Ϣ 
        ans+=edge[i].w;
        //����һ����ȡ������ߡ�
        fa[ev]=eu;
        //�ϲ����� 
    }
}

il void pre_process(int x,int y)  //Ԥ���� 
{
	eu=find(x), ev=find(y);
    if(eu!=ev)
    {
        fa[ev]=eu;
        //�������ȣ���ϲ����� 
    }
}
    
template <class T>
struct Edge
{
	int dest;
	Edge<T>* link;
	Edge() {}
	Edge(int num) :dest(num), link(NULL) {}
};

//ͼ�ж���Ķ��� 
template <class T>
struct  Vertex
{
	T data;
	Edge<T>* adj;
};

template <class T>
class Graphlnk
{
public:
	Graphlnk(int sz = heh);//ͼ�Ĺ��캯�� 
	~Graphlnk();//ͼ���������� 
	T getValue(int i)//�õ��±�Ϊi�Ķ��� 
	{
		return (i >= 0 && i < numVertices) ? NodeTable[i].data : 0;
	}
	int getVnum()//�õ���ǰͼ�н���� 
	{
		return numVertices;
	}
	int getEnum()//�õ���ǰͼ�бߵ���Ŀ 
	{
		return numEdges;
	}
	bool insertVertex(const T& vertex);//������ 
	bool insertEdge(int v1, int v2);//����� 
	int getFirstNeighbor(int v);//�õ���һ���ڽӶ��� 
	int getNextNeighbor(int v, int w);//�õ���һ���ڽӵ� 
	void input();//����ͼ 
	void output();//���ͼ 
	int getVertexPos(const T vertex)    //��������vertex��ͼ�е�λ��
	{
		for (int i = 0; i < numVertices; i++)
		{
			if (NodeTable[i].data == vertex)//�ҵ����ظö����Ӧ���±� 
			{
				return i;
			}
		}
		return -1;//δ�ҵ�����-1�� 
	}
private:
	int maxVertices;//ͼ����󶥵���
	int numVertices;
	int numEdges;
	Vertex<T>* NodeTable;
};

template <class T>
Graphlnk<T>::Graphlnk(int sz)   //���캯��������һ���յ��ڽӱ�
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	NodeTable = new Vertex<T>[maxVertices];	//�������������
	if (NodeTable == NULL)
	{
		cerr << "�洢�����" << endl;
	}
	for (int i = 0; i < maxVertices; i++)
	{
		NodeTable[i].adj = NULL;
	}
}

template <class T>
Graphlnk<T>::~Graphlnk()
{
	for (int i = 0; i < numVertices; i++)
	{
		Edge<T>* p = NodeTable[i].adj;
		while (p != NULL)
		{
			NodeTable[i].adj = p->link;
			delete p;
			p = NodeTable[i].adj;
		}
	}
	delete[]NodeTable;//ɾ�����������
}

template <class T>
int Graphlnk<T>::getFirstNeighbor(int v)
{
	if (v != -1)//����v����
	{
		Edge<T>* p = NodeTable[v].adj;
		if (p != NULL)
		{
			return p->dest;   //����, ���ص�һ���ڽӶ���
		}
	}
	return -1;		//��һ���ڽӶ��㲻����
}

template <class T>
int Graphlnk<T>::getNextNeighbor(int v, int w)
{
	if (v != -1) 			 //����v����
	{
		Edge<T>* p = NodeTable[v].adj;	   //��Ӧ�������һ���߽��
		while (p != NULL && p->dest != w)
		{
			p = p->link;
		}
		if (p != NULL && p->link != NULL)
		{
			return p->link->dest;
		}
	}
	return -1; 			//��һ�ڽӶ��㲻����
}
template <class T>
bool Graphlnk<T>::insertVertex(const T& vertex)
{
	//���붥�� 
	if (numVertices == maxVertices)
	{
		return false;
	}
	NodeTable[numVertices].data = vertex;
	NodeTable[numVertices].adj = NULL;
	numVertices++;
	return true;
}

template <class T>
bool Graphlnk<T>::insertEdge(int v1, int v2)   //����Ȩ����ͼ
{
	//������Ȩ�� 
	Edge<T>* q, * p;
	if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices)//�ȶ�������������ж� 
	{
		p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
		{
			//�ҵ�ָ��v2����ı� 
			p = p->link;
		}
		if (p != NULL)
		{
			//������Ѿ����ڷ���false 
			return false;
		}
		p = new Edge<T>;
		p->dest = v2;
		p->link = NodeTable[v1].adj;
		NodeTable[v1].adj = p;
		q = new Edge<T>;
		q->dest = v1;
		q->link = NodeTable[v2].adj;
		NodeTable[v2].adj = q;
		numEdges++;
	}
	return true;
}
template <class T>
void Graphlnk<T>::input()
{
	int i, j, k, vn, en;
	T v1, v2;
	cin >> vn >> en;
	for (i = 0; i < vn; i++)
	{
		cin >> v1;
		insertVertex(v1);
	}
	i = 0;
	while (i < en)
	{
		cin >> v1 >> v2;
		j = getVertexPos(v1);
		k = getVertexPos(v2);
		if (j == -1 || k == -1)
		{
			cout << "��������ߵ�����������Ϣ��" << endl;
		}
		else
		{
			insertEdge(j, k);
			i++;
		}
	}
}

template <class T>
void Graphlnk<T>::output()
{
	int i, vn;
	Edge<T>* p;
	vn = numVertices;
	for (i = 0; i < vn; i++)
	{
		cout << i << " " << NodeTable[i].data;//�������Ԫ�� 
		p = NodeTable[i].adj;
		while (p != NULL)
		{
			cout << "-->" << p->dest;
			p = p->link;
		}
		cout << endl;
	}
}

//	########################  ���������  ########################
int main()
{
	cin>>n>>m;
	for(re int i=1;i<=30;i++)  //���鼯Ԥ���� 
    {
        fa[i]=i;
    }
	for(re int i=0;i<m;i++)   //���߼� 
	{
		cin>>c1>>c2>>edge[i].w;
		edge[i].u=(c1-'A'+1);
		edge[i].v=(c2-'A'+1);
	}
	cin>>k;
	while(k--)      //����Ԥ���� 
	{
		cin>>c1>>c2;
		pre_process((c1-'A'+1),(c2-'A'+1));
	}
	kruskal();
	cout<<ans<<endl;
	sort(s+1,s+cnt+1,cmp2);
	for(int i=1;i<=cnt;i++)   //����½���·����ϸ��Ϣ 
	{
		cout<<(char)(s[i].u-1+'A')<<" "<<(char)(s[i].v-1+'A')<<" "<<s[i].w<<endl;
	}
	return 0;									// �����˳�
}
