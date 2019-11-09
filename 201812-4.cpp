#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 500005
struct Node{
    int u,v,w;
    Node(int u = 0, int v = 0, int w = 0):u(u), v(v), w(w){}

};
Node graph[MAX];
int fa[MAX];
/*
 * 并查集
 * 1. 初始化
 * 2. 查
 * 3. 合并
 */
void init(int n){
    for(int i = 0; i <= n; ++i){
        fa[i] = i;
    }
}
int find(int num){
    int tmp = num;
    while(fa[num] != num){
        num = fa[num];
    }
    while(fa[tmp] != num){//压缩路径
        int tmp2 = fa[tmp];
        fa[tmp] = num;
        tmp = tmp2;
    }
    return num;
}
bool unions(int num1, int num2){
    int root1 = find(num1);
    int root2 = find(num2);
    if(root1 == root2){
        return false;
    }
    else{
        fa[root1] = root2;
        return true;
    }
}
bool cmp(const Node& a, const Node &b){
    return a.w < b.w;
}
int kru(int n, int m){//Kruskal算法
    sort(graph, graph + m, cmp);
    init(n);
    int cnt = 0;
    for(int i = 0; i < m; ++i){
        int u = graph[i].u;
        int v = graph[i].v;
        if(unions(u,v)){//并查集来判断是否成环
            ++cnt;
            if(cnt == n - 1){
                return graph[i].w;
            }
        }
    }
}

int main(){
    int n,m, root;
    int u, v, w;
    scanf("%d%d%d", &n, &m, &root);
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d", &graph[i].u, &graph[i].v, &graph[i].w);
    }
    printf("%d\n", kru(n, m));
}