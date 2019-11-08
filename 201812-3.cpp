//
// Created by onwaier on 2019/11/7.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

#define  MAX 100000 +5
struct Node{
    int num[4];
    int len;
    Node(string s){//定义构造函数
        memset(num, 0, sizeof(num));
        int cnt = 0, sum = 0;
        len = 0;
        bool flag = false;
        for(auto ch: s){
            if(ch == '.'){
                ++cnt;
                sum = 0;
            }
            else if(ch == '/'){
                flag = true;
            }
            else{
                if(flag){
                    len = len * 10 + (ch - '0');
                }
                else{
                    num[cnt] = num[cnt] * 10 + (ch - '0');
                }
            }
        }
        if(!flag){
            len = (cnt + 1) * 8;
        }
    }
    bool operator < (const Node &a)const{//重载< 用于排序
        return num[0] != a.num[0]?num[0] < a.num[0]:num[1] != a.num[1]?num[1]<a.num[1]:
                                                    num[2]!= a.num[2]?num[2] < a.num[2]:num[3] != a.num[3]?num[3] < a.num[3]:len !=a.len?
                                                                                                                             len < a.len:true;
    }
};

int cal(Node &a, Node &b, int bit){//前bit位异或
    long long num1 = a.num[0] * pow(256, 3) + a.num[1] * pow(256, 2) + a.num[2] * pow(256, 1) + a.num[3];
    long long num2 = b.num[0] * pow(256, 3) + b.num[1] * pow(256, 2) + b.num[2] * pow(256, 1) + b.num[3];
    long long res = num1 ^ num2;
    return res >> (32 - bit);
}
void update(Node& node, int len){//合并 修改node长度及ip地址
    node.len = len;
    long long num1 = node.num[0] * pow(256, 3) + node.num[1] * pow(256, 2) + node.num[2] * pow(256, 1) + node.num[3];
    num1 = (num1 >> (32 - len)) << (32 - len);
    int idx = 3;
    while(idx >= 0){
        node.num[idx--] = num1 % 256;
        num1 = num1 >> 8;
    }
}
vector<Node>v;
void deal(){
    int len = v.size();
    vector<Node>vec;
    for(int i = 0; i < len; ++i){
        //从小到大合并
        if(vec.empty()){
            vec.push_back(v[i]);
        }
        else{
            Node node = vec.back();
            while(i < len && v[i].len > node.len && cal(v[i], node, node.len) == 0){
                ++i;
            }
            if(i >= len){
                break;
            }
            else{
                vec.push_back(v[i]);
            }
        }
    }
    //同级合并
    for(auto it = vec.begin(); it != vec.end() - 1; ++it){
        if(it->len == (it + 1)->len && cal(*it, *(it + 1), it->len) == 1){//合并 删除一个
            vec.erase(it + 1);
            update(*it, it->len - 1);
            if(it != vec.begin()){//合并完成后，若前面有元素，则需要考虑是否能合并
                it -= 2;
            }
            else{
                it -= 1;//前面没有元素了
            }
        }
    }
    for(int i = 0; i < vec.size(); ++i){
        printf("%d.%d.%d.%d/%d\n", vec[i].num[0], vec[i].num[1], vec[i].num[2], vec[i].num[3], vec[i].len);
    }
}
int main(){
    //freopen("/home/onwaier/CLionProjects/CFFSolutions/a.txt", "r", stdin);
    //ios::sync_with_stdio(false);
    int n;
    string s;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        cin >> s;
        v.push_back(Node(s));
    }
    sort(v.begin(), v.end());
    deal();

    return 0;
}