#include<bits/stdc++.h>
using namespace std;

int arr[3][3];

bool judge(int num) {//�жϵ�ǰ����num�Ƿ��ʤ 
	for(int i = 0; i < 3; ++i){//�г��� 
		if(arr[i][0] == num && arr[i][1] == num && arr[i][2] == num){
			return true;
		}
	}
	for(int i = 0; i < 3; ++i){//�г��� 
		if(arr[0][i] == num && arr[1][i] == num && arr[2][i] == num){
			return true;
		}
	}
	//�Խǳ��� 
	if(arr[0][0] == num && arr[1][1] == num && arr[2][2] == num){
		return true;
	}
	if(arr[0][2] == num && arr[1][1] == num && arr[2][0] == num){
		return true;
	}
	return false;
}

int score(int num) {//������ǰ����ĵ÷� 
	int res  = 1;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(arr[i][j] == 0){
				++res;
			}
		}
	}
	if(num == 1){
		return res;
	}
	else{
		return -res;
	}
}


int dfs(int num){
	int maxVal = -1 << 30;
	int minVal = 1 << 30;
	if(score(1) == 1){//ƽ�� (��������һ����Alice)
		return 0;
	}
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(!arr[i][j]){
				arr[i][j] = num;
				if(judge(num)){//�ֳ�ʤ�� 
					if(num == 1){
						maxVal = max(maxVal, score(num));
					}
					else{
						minVal = min(minVal, score(num));
					}
				}
				else{//�� 
					if(num == 1){
						maxVal = max(maxVal, dfs(2));
					}
					else{
						minVal = min(minVal, dfs(1));
					} 
				}
				arr[i][j] = 0;
			}
		}
		
	}
	if(num == 1){//���ص�ǰ�����ߵ�����������ֵ 
		return maxVal;
	}
	else{
		return minVal;
	}
}

int main() {
	freopen("E://a.txt", "r", stdin);
	int T;
	
	//��������  
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				scanf("%d", &arr[i][j]);
			}
		}
		if(judge(2)){//�ֳ�ʤ�� 
			printf("%d\n", score(2));
		}
		else{
			printf("%d\n", dfs(1));
		}
	}
	return 0;
}
