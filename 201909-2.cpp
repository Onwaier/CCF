#include<bits/stdc++.h>
using namespace std;
/*
N是苹果棵数 m是操作次数
num是输入的操作（>0为统计 <=0为疏果） 
nowSum统计每棵树的苹果数 total为所有苹果树上的苹果数
dropNum是发生苹果掉落的棵数
E是连续3棵树发生苹果掉落的级数 
*/
bool mark[1005];
int main(){
	//freopen("E://a.txt", "r", stdin);//读取数据 
	int N, m, num, nowSum = 0, total = 0, dropNum = 0, E = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &m);
		for(int j = 0; j < m; ++j){
			scanf("%d", &num);
			if(j == 0){
				nowSum = num;
			}
			else{
				if(num <= 0){
					nowSum += num;
				}
				else{
					if(!mark[i] && nowSum > num){//统计掉落苹果只统计一次 
						mark[i] = true;
						dropNum++;
					}
					nowSum = num;//只要输入num大于0，不管是否等于都要更新nowSum 
				}
			}
		}
		total += nowSum;
	}
	for(int i = 0; i < N; ++i){
		if(mark[i] && mark[(i + 1) % N] && mark[(i + 2) % N]){//去重 
			++E;
//			if(N == 3){//这里觉得三棵树的话，E最大只能是1，后面的2种是重复的，但提交显示wrong 
//				break;
//			} 
		}
	}
	printf("%d %d %d\n", total, dropNum, E);
	return 0;
} 
