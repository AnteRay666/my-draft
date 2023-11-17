//朴素Dijkstra算法
#include<bits/stdc++.h>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N]; // 邻接矩阵
int dist[N]; // 存储最短距离
bool book[N]; // 是否已确定最短路

int Dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    // 循环n次
    for (int i = 0; i < n; ++i)
    {
        // 选出距离1号节点距离最短的节点
        int u = -1;
        for (int j = 1; j <= n; ++j)
            if (!book[j] && (u == -1 || dist[u] > dist[j])) u = j;
        book[u] = true;

        // 更新边
        for (int i = 1; i <= n; ++i)
            if (!book[i] && dist[u] + g[u][i] < dist[i]) dist[i] = dist[u] + g[u][i];
    }

    if (dist[n] == INF) return -1;
    else return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof(g));

    while (m--)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = min(g[a][b], w); // 重边保留最小的边
    }

    printf("%d", Dijkstra());
    system("pause");
    return 0;
}
