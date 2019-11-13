//
// Created by onwaier on 2019/11/12.
//
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>>v1, v2;
int main() {
//    freopen("/home/onwaier/CLionProjects/CFFSolutions/a.txt", "r", stdin);
    int num1, num2, n;
    long long res = 0;
    scanf("%d", &n);
    for(int i= 0; i < n; ++i){
        scanf("%d%d", &num1, &num2);
        v1.push_back(make_pair(num1, num2));
    }
    for(int i= 0; i < n; ++i){
        scanf("%d%d", &num1, &num2);
        v2.push_back(make_pair(num1, num2));
    }
    for(int i = 0, j = 0; i < n && j < n;){
        if(v1[i].first <= v2[j].first && v1[i].second >= v2[j].first){
            res += (min(v1[i].second, v2[j].second) - v2[j].first);
        }
        else if(v2[j].first <= v1[i].first &&  v2[j].second >= v1[i].first){
            res += (min(v2[j].second, v1[i].second) - v1[i].first);
        }
        if(v1[i].second > v2[j].second)
            ++j;
        else
            ++i;
    }
    printf("%lld\n", res);
    return 0;
}
