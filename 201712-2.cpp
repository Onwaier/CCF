#include<bits/stdc++.h> 
using namespace std;

int deal(int n, int k) {
	queue<int>que[2];
	for(int i = 1; i <= n; ++i){
		que[0].push(i);
	}
	int cnt = 0, frt;
	while(que[0].size() + que[1].size() > 1){
		int idx = 0;
		while(que[idx].empty())idx++;
		while(!que[idx].empty()){
			++cnt;
			frt = que[idx].front();
			que[idx].pop();
			if(cnt % k != 0 && cnt % 10 != k){
				que[1 - idx].push(frt);
			}
			if(que[idx].size() + que[1 - idx].size() == 1){
				break;
			}
		}
	}
	int idx = 0;
	while(que[idx].empty())idx++;
	return que[idx].front();
}
int main(){
	//freopen("E://a.txt", "r", stdin);
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d\n", deal(n, k));
	return 0;
}
