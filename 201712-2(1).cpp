#include<bits/stdc++.h> 
using namespace std;

#define MAX (1000 + 5)
bool mark[MAX];
int getNum(int n, int &res){//��ȡ��ǰ�����е����� 
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
		if(getNum(n, res) == 1){//����1 k��������� 
			break;
		}
		if(!mark[idx]){//δ���� 
			++num;
			if(num % k == 0 || num % 10 == k){//ĩ��Ϊk������Ϊk�ı��� 
				mark[idx] = true;
			}
		}
		if(idx == n){//��β��ʱ�����Ƿ�����ֻ��һ���˵Ľ������� 
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
	memset(mark, false, sizeof(mark));//��ʼ�� 
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d\n", deal(n, k));
	return 0;
}

