//
// Created by Onwaier Lee on 2019-10-30.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    //freopen("//Users//onwaier//CLionProjects//CCFSolutions//a.txt", "r", stdin);
    int n;
    string s, post;
    cin >> n;
    stack<char>op;
    stack<int>res;
    for(int i = 0; i < n; ++i){
        cin >> s;
        /*
         * 第一步将中缀表达式转为后缀表达式
         * 需要用栈来存放运算符号（+、-、*、/）和括号（题目中没有）
         * 这里比较简单就没有优先级
         */
        for(auto ch:s){
            if(isdigit(ch)){
                post.push_back(ch);
            }
            else if(ch == '+' || ch == '-'){//为+-时，当栈为空时，入栈。否则先弹栈顶元素
                while(!op.empty()){
                    post.push_back(op.top());
                    op.pop();
                }
                op.push(ch);
            }
            else{//为*与/时，当栈顶元素为*与/时，出栈。其它情况入栈
                while(!op.empty() && (op.top() == 'x' || op.top() == '/')){
                    post.push_back(op.top());
                    op.pop();
                }
                op.push(ch);
            }
        }
        while(!op.empty()){
            post.push_back(op.top());
            op.pop();
        }
        /*
         * post为后缀表达式，注意后缀表达式中的数字都是0-9，并且除都是去尾。
         * 需要用另一个栈存储数字
         */
        for(auto ch:post){
            if(isdigit(ch)){
                res.push(ch -'0');
            }
            else{
                int num2 = res.top();
                res.pop();
                int num1 = res.top();
                res.pop();
                switch (ch){
                    case '+':
                      res.push(num1 + num2);
                      break;
                    case '-':
                        res.push(num1 - num2);
                        break;
                    case 'x':
                        res.push(num1 * num2);
                        break;
                    case '/':
                        res.push(num1 / num2);
                        break;
                }
            }
        }
        if(res.top() == 24){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
