#include<bits/stdc++.h>
using namespace std;

/*
	Nƻ�����Ŀ��� M��������
	rmNumȥ��ƻ���� idx�����������ƻ��������С���
	maxRmNum M�ֺ�ȥ��ƻ������ tmpRmNum�洢ȥ��ƻ����֮�� 
	resNum���һ������ƻ����ʣ�µ�ƻ������ 
*/
int main(){
	freopen("E:\\a.txt", "r", stdin);//���ļ��ж�ȡ���� 
	int N, M;
	int num, rmNum = 0, idx = 0, maxRmNum = 0, tmpRmNum = 0, resNum = 0;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i){
		scanf("%d", &num);
		resNum += num;
		tmpRmNum = 0;
		for(int j = 0; j < M; ++j){//���� 
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
