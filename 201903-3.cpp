
//
// Created by Onwaier Lee on 2019-10-31.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1005
char data[MAX][82000];
bool mark[MAX];//标记磁盘是否缺失
int toNum(char ch){
    if(isdigit(ch)){
        return ch -'0';
    }
    else{
        return ch - 'A' + 10;
    }
}
char toChar(int num){
    if(num < 10){
        return num + '0';
    }
    else{
        return 'A' + (num - 10);
    }
}
void deal(int diskIdx, int n, int idx){
    if(mark[diskIdx]){
        for(int j = idx; j < idx + 8; ++j){
            printf("%c", data[diskIdx][j]);
        }
        printf("\n");
    }
    else{
        for(int i = idx; i < idx + 8; ++i){
            int res = -1;
            for(int j = 0; j < n; ++j){
                if(diskIdx != j){
                    if(res == -1){
                        res = toNum(data[j][i]);
                    }
                    else{
                        res = res ^ toNum(data[j][i]);
                    }
                }
            }
            printf("%c", toChar(res));
        }
        printf("\n");
    }
}
int main(){
    //freopen("/home/onwaier/文档/a.txt", "r", stdin);
    //先处理有序的情况
    int n, s, l, m, total;
    //n为阵列中硬盘的数目，s为阵列中条带的大小，l为现存硬盘的数目
    //m为查询次数, total为阵列总长度
    int idx1, idx2;//idx1为磁盘的序号, idx2为块的序号
    string str;//str为磁盘的数据
    memset(mark, false, sizeof(mark));
    scanf("%d%d%d", &n, &s, &l);

    for(int i = 0; i < l; ++i){
        scanf("%d ", &idx1);
        //scanf("%s", data[idx1]);
        //gets(data[idx1]);
        fgets(data[idx1], 82000, stdin);//注意fgets的用法
        mark[idx1] = true;//表示磁盘存在未缺失
        //printf("%s\n", data[idx1]);
    }
    total = strlen(data[idx1]) / 8 * (n - 1);
    //cout << "total:" << total << endl;
    scanf("%d", &m);
    for(int i = 0; i < m; ++i){
        scanf("%d", &idx2);
        //块号超过阵列长度
        if(idx2 >= total){
            cout << "-" << endl;
            continue;
        }
        int diskIdx, stripeIdx, checkCnt, checkPos, dataPos;//磁盘号,条带号,前面校验盘的数量,校验盘所处的位置,数据的位置
        //先确定位于哪块磁盘
        diskIdx = idx2 / s % n;
        if(!mark[diskIdx] && l < n - 1){//磁盘缺失且剩余磁盘不足于恢复数据
            cout << "-" << endl;
            continue;
        }
        stripeIdx = idx2 / s / n;
        checkPos = n - 1 -diskIdx;
        if(stripeIdx < checkPos){
            checkCnt = 0;
        }
        else{
            checkCnt = (stripeIdx - checkPos) / (n - 1) + 1;
        }

        //再确定磁盘中的哪个位置
        dataPos = (stripeIdx + checkCnt) * s + (idx2 % s);
        deal(diskIdx, n, dataPos * 8);
//        for(int j = dataPos * 8; j <dataPos * 8 + 8; ++j){
//            printf("%c", data[diskIdx][j]);
//        }
//        printf("\n");
    }
    return 0;
}
