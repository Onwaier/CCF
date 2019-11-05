//
// Created by Onwaier Lee on 2019-11-04.
//
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>

using namespace std;

#define MAX 10005
struct Node{
    bool flag;
    int num;
};
vector<deque<Node>>v(MAX);
bool mark[MAX];

int getIdx(int n){//获取第一个非空下标
    for(int i = 0; i < n; ++i){
        if(!v[i].empty()){
            return i;
        }
    }
    return -1;
}
bool deal(int n){
    int idx = 0;
    while((idx = getIdx(n)) != -1){
        int cnt = 0;
        while(cnt < n - 1){//避免死锁导致的死循环

            bool ch = v[idx].front().flag;
            int num = v[idx].front().num;
            if(v[num].empty()){//空
                return false;
            }
            if((v[num].front().flag != ch) && v[num].front().num == idx){//成对指令出队
                v[idx].pop_front();
                v[num].pop_front();
                break;
            }
            else {
                idx = num;//递进寻找成对指令
            }
            ++cnt;
        }
        if(cnt == n - 1){//死锁
            break;
        }
    }
    return idx == -1;
}
int main(){
    //freopen("//Users//onwaier//CLionProjects//CCFSolutions//a.txt", "r", stdin);
    int T, n;
    string s, str;
    scanf("%d%d", &T, &n);
    getchar();
    for(int i = 0; i < T; ++i){
        for(int j = 0; j < n; ++j){
            if(!v[j].empty())//清空队列
                v[j].clear();
            getline(cin, s);
            stringstream ss(s);
            while(ss >> str){//将字符串分割 获取数字及指令
                Node tmp;
                tmp.flag = str[0] == 'R'?true:false;
                tmp.num = stoi(str.substr(1));
                v[j].push_back(tmp);
            }
        }
        if(deal(n)){
            printf("0\n");
        }
        else{
            printf("1\n");
        }
    }
    return 0;
}
