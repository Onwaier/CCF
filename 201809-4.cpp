//
// Created by Onwaier Lee on 2019-11-16.
//  差分约束 最短路
//
#include <bits/stdc++.h>
using namespace std;
#define MAX 305

struct Node{
    int v;
    int w;
    Node(int v, int w):v(v), w(w){}
};
int a[MAX], b[MAX], dist[MAX], cnt[MAX];//dist[i] = a[0] + a[1] + …… + a[i]
bool mark[MAX];
vector<vector<Node>>graph(MAX);


bool spfa(int sta, int n){//用于求最长路
    //初始化
    memset(dist, 0, sizeof(dist));
    memset(mark, false, sizeof(mark));
    memset(cnt, 0, sizeof(cnt));//计数 处理负环

    queue<int>que;
    int frt;
    que.push(0);
    ++cnt[0];
    mark[0] = true;
    while (!que.empty()){
        frt = que.front();
        que.pop();
        mark[frt] = false;
        for(int i = 0; i < graph[frt].size(); ++i){
            int u = frt, v = graph[frt][i].v, w = graph[frt][i].w;
            if(dist[v] < dist[u] + w){//松弛条件与最短路时不同
                dist[v] = dist[u] + w;
                if(!mark[v]){
                    mark[v] = true;
                    ++cnt[v];
                    que.push(v);
                    if(cnt[v] > n + 1){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main(){
    //freopen("//Users//onwaier//CLionProjects//CCFSolutions//a.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < n - 2; ++i){//除了第一个和最后一个
        graph[i].push_back(Node(i + 3, 3 * b[i + 2]));
        graph[i + 3].push_back(Node(i, -3 * b[i + 2] - 2));
    }
    //特殊处理第一个与最后一个
    graph[0].push_back(Node(2, 2 * b[1]));
    graph[2].push_back(Node(0, -2 * b[1] - 1));
    graph[n - 2].push_back(Node(n, 2 * b[n]));
    graph[n].push_back(Node(n - 2, -2 * b[n] - 1));

    //每一个都要不小于1
    for(int i = 0; i < n; ++i){
        graph[i].push_back(Node(i + 1, 1));
    }

    spfa(0, n);
    for(int i = 1; i <= n; ++i){
        a[i] = dist[i] - dist[i - 1];
    }
    for(int i = 1; i <= n; ++i){
        printf("%s%d", i == 0?"":" ", a[i]);
    }
    return 0;
}

