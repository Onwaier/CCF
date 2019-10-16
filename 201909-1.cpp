#include<bits/stdc++.h>
using namespace std;

/*
	N苹果树的棵数 M操作轮数
	rmNum去掉苹果数 idx疏果个数最多的苹果树的最小编号
	maxRmNum M轮后去掉苹果最多的 tmpRmNum存储去掉苹果数之和 
	resNum最后一轮所有苹果树剩下的苹果总数 
*/
int main(){
	freopen("E:\\a.txt", "r", stdin);//从文件中读取数据 
	int N, M;
	int num, rmNum = 0, idx = 0, maxRmNum = 0, tmpRmNum = 0, resNum = 0;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i){
		scanf("%d", &num);
		resNum += num;
		tmpRmNum = 0;
		for(int j = 0; j < M; ++j){//输入 
			scanf("%d", &rmNum);
			tmpRmNum += rmNum;
		}
		if(abs(tmpRmNum) > maxRmNum){
			maxRmNum = -tmpRmNum;
			idx = i + 1;
		}
		resNum += tmpRmNum;
	}
	printf("%d %d %d\n", resNum, idx, maxRmNum);
	return 0;
} 
