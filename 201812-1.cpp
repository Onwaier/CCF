//
// Created by onwaier on 2019/11/4.
//

#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    //freopen("/home/onwaier/CLionProjects/CFFSolutions/a.txt", "r", stdin);
    int r, g, y;//r g y表示红,縁，黄灯的时间
    scanf("%d%d%d", &r, &g, &y);
    int n;//总共经过的道路段数和红绿灯的数目
    int k, t, sum = 0;//k标记区分 t表示时间
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &k, &t);
        switch(k){
            case 0:
                sum += t;
                break;
            case 1:
                sum += t;
                break;
            case 2:
                sum += (t + r);
                break;
            case 3:
                break;
            default:
                break;
        }
    }
    printf("%d\n", sum);
    return 0;
}