#include<bits/stdc++.h> 
using namespace std;

#define MAX (1000 + 5)
bool mark[MAX];
int getNum(int n, int &res){//获取当前队列中的人数 
	bool flag = false;
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(!mark[i]){
			if(!flag){
				res = i;
				flag = true;
			}
			++cnt;
		}
	}
	return cnt;
}
int deal(int n, int k) {
	int num = 0, idx = 1, res = 0;
	while(true){
		if(getNum(n, res) == 1){//处理1 k等特殊情况 
			break;
		}
		if(!mark[idx]){//未出队 
			++num;
			if(num % k == 0 || num % 10 == k){//末数为k或者数为k的倍数 
				mark[idx] = true;
			}
		}
		if(idx == n){//到尾的时候考虑是否满足只有一个人的结束条件 
			if(getNum(n, res) == 1){
				break;
			}
			idx = 1;
		}
		else{
			idx = idx + 1; 
		}
	}
	return res;
}
int main(){
	//freopen("E://a.txt", "r", stdin);
	memset(mark, false, sizeof(mark));//初始化 
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d\n", deal(n, k));
	return 0;
}

