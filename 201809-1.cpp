//
// Created by onwaier on 2019/11/11.
#include <bits/stdc++.h>
using namespace std;
#define  MAX 1000 + 5
int arr[MAX], res[MAX];
int main() {
    //freopen("/home/onwaier/CLionProjects/CFFSolutions/a.txt", "r", stdin);
    int n;
    //输入
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }

    //处理
    for(int i = 0; i < n; ++i){
        if(i == 0){//最左边只有右边一个邻居
            res[i] = (arr[i] + arr[i + 1])/2;
        }
        else if(i == n - 1){
            res[i] = (arr[i] + arr[i - 1]) / 2;
        }
        else{
            res[i] = (arr[i - 1] + arr[i] + arr[i + 1]) / 3;
        }
    }

    //输出
    for(int i = 0; i < n; ++i){//最右边只有左边一个邻居
        printf("%s%d", i == 0?"":" ", res[i]);
    }
    return 0;
}
