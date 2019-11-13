//
// Created by onwaier on 2019/11/13.
//

#include <bits/stdc++.h>
using namespace std;

#define MAX 105
struct Node{
    int dotCnt;
    vector<string>strVec;
};

Node docu[105];

bool myCmp(string str1, string str2){//自定义字符串比较
    if(str1[0] == '#'){//对于ID区分大小写
        return str1 == str2;
    }
    else{//标签不区分大小写
        transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
        transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
        return str1 == str2;
    }
}
int main() {
    //freopen("/home/onwaier/CLionProjects/CFFSolutions/a.txt", "r", stdin);
    int n, m;
    string str1, str2;
    int cnt = 0, idx = 0, dotCnt;
    Node node;
    vector<string>vec;
    vector<int>res;
    bool flag = false;
    //输入数据
    scanf("%d%d",&n, &m);
    getchar();
    for(int i = 0; i < n; ++i){
        getline(cin, str1);
        idx = 0;
        while(idx < str1.size() && str1[idx] == '.')
            ++idx;
        docu[i].dotCnt = idx;
        istringstream s(str1.substr(idx));
        node.strVec.clear();
        flag = false;
        while(s >> str2){
            if(!flag){
                flag = true;
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
            }
            docu[i].strVec.push_back(str2);
        }
    }


    for(int i = 0; i < m; ++i){
        getline(cin, str1);
        istringstream s(str1);
        vec.clear();
        while(s >> str2){//空格分隔
            vec.push_back(str2);
        }
        res.clear();
        idx = 0;
        dotCnt = -1;
        for(int j = 0; j < n; ++j){//逐行匹配
            for(int k = 0; k < docu[j].strVec.size(); ++k){
                if(docu[j].dotCnt > dotCnt && myCmp(vec[idx], docu[j].strVec[k])){
                    ++idx;//匹配后代
                    if(idx == vec.size()){//贪婪匹配 只有最后一级需要重新匹配
                        idx = vec.size() - 1;
                        res.push_back(j + 1);
                    }
                    else{
                        dotCnt = docu[j].dotCnt;
                    }
                }
            }

        }

        //输出
        if(res.size() == 0){
            printf("0\n");
        }
        else{
            printf("%d ", res.size());
            for(int j = 0; j < res.size(); ++j){
                printf("%s%d", j == 0?"":" ", res[j]);
                if(j == res.size() - 1){
                    printf("\n");
                }
            }
        }


    }

    return 0;
}