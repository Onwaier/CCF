//
// Created by Onwaier Lee on 2019-11-16.
// DFS
//
#include <bits/stdc++.h>
using namespace std;

#define MAX 305
int a[MAX], b[MAX];
int n;
bool flag = false;
bool f[MAX][MAX][MAX];//储存状态信息
void dfs(int idx, int num1, int num2){
    if(flag || f[idx][num1][num2]){//剪枝 不然只有80分
        return;
    }
    f[idx][num1][num2] = 1;
    if(idx == n){
        for(int i = 0; i < 3; ++i){
            a[n] = 3 * b[idx - 1] + i - num1 - num2;
            if(a[n] > 0 && (a[n] + num2) / 2 == b[n]){
                flag = true;
                for(int i = 1; i <= n; ++i){
                    printf("%s%d", i == 1?"":" ", a[i]);
                }
                printf("\n");
                exit(0);
            }
        }
        return;
    }
    else if(idx > n){//只有2个数
        if((num1 + num2) / 2 == b[n]){
            printf("%d %d\n", a[1], a[2]);
            flag = true;
            exit(0);
        }
    }
    for(int i = 0; i < 3; ++i){
        a[idx] = 3 * b[idx - 1] + i - num1 - num2;
        if(a[idx] > 0)
            dfs(idx + 1, num2, a[idx]);
    }
}

int main(){
    freopen("//Users//onwaier//CLionProjects//CCFSolutions//a.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &b[i]);
    }
    //a[1]的范围是1 - 2 * b[1] - 1
    for(int i = 1; i <= 2 * b[1] + 1; ++i){
        a[1] = i;
        //a[2]的第一种情况
        a[2] = 2 * b[1] - a[1];
        if(!flag && a[2] > 0)
            dfs(3, a[1], a[2]);
        //a[2]的第二种情况
        a[2] = 2 * b[1] - a[1] + 1;
        if(!flag && a[2] > 0)
            dfs(3, a[1], a[2]);
    }

    return 0;
}
