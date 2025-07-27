#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


void back_reverse(int target, int* prev, int* adjacency_matrix, int N){
    // 从终点target开始倒序
    int cur = target;
    while(*(prev+cur) != -1){
        int tmp = cur;
        // 更新cur
        cur = *(prev+cur);
        // 添加反向边
        ++(*(adjacency_matrix+tmp*N+cur));

        --(*(adjacency_matrix+cur*N+tmp));
    }
}


int main()
{
    // 点个数6
    int N = 6;
    // 使用邻接矩阵定义一个图, source:0    target:5
    /*
    int adjacency_matrix[6][6] = {  {0, 8, 2, 0, 0, 0}, \
                                    {0, 0, 3, 10,0, 0}, \
                                    {0, 0, 0, 2, 4, 0}, \
                                    {0, 0, 0, 0, 0, 6}, \
                                    {0, 0, 0, 0, 0, 5}, \
                                    {0, 0, 0, 0, 0, 0}  \
                                     };
    */
    int adjacency_matrix[6][6] = {  {0, 7, 2, 0, 0, 0}, \
                                    {0, 0, 5, 1, 0, 0}, \
                                    {0, 0, 0, 5, 4, 0}, \
                                    {0, 0, 0, 0, 0, 4}, \
                                    {0, 0, 0, 0, 0, 5}, \
                                    {0, 0, 0, 0, 0, 0}  \
                                     };
    // Ford-Fulkersen 算法
    vector<int> v;
    // 临时变量
    int tmp;
    // 访问标志
    int visited[6];
    // 全部设置为未访问
    memset(visited, 0, sizeof(int)*N);
    // 最大流量
    int max_flow = 0;
    // 记录当前的最大流量
    int cur_max_flow = 0;
    // 记录每一个点的前驱,便于添加反向边
    int prev[6];
    // 起点的前驱为 -1
    prev[0] = -1;
    // 不断使用 BFS 算法
    while(true){
        v.push_back(0);
        visited[0] = 1;
        while(!v.empty()){
            tmp = v.back();
            v.pop_back();
            for(int i=0; i<N; ++i){
                if(adjacency_matrix[tmp][i] > 0){
                    if(i == N-1){
                        ++max_flow;
                        // 记录前驱点
                        prev[i] = tmp;
                        // 倒序, 添加反向边
                        back_reverse(i, prev, (int*)adjacency_matrix, N);
                    }
                    else if(!visited[i]){
                        visited[i] = 1;
                        // 加入队列
                        v.push_back(i);
                        // 记录前驱点
                        prev[i] = tmp;
                    }
                }
            }
        }
        // 全部设置为未访问
        memset(visited, 0, sizeof(int)*N);
        // 若本次BFS后,最大流量没变化,退出循环
        if(cur_max_flow == max_flow)
            break;
        cur_max_flow = max_flow;
        printf("%d\n", max_flow);
    }
    printf("最大流量为%d\n", max_flow);
    return 0;
}