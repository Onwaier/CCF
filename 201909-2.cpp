#include<bits/stdc++.h>
using namespace std;
/*
N��ƻ������ m�ǲ�������
num������Ĳ�����>0Ϊͳ�� <=0Ϊ����� 
nowSumͳ��ÿ������ƻ���� totalΪ����ƻ�����ϵ�ƻ����
dropNum�Ƿ���ƻ������Ŀ���
E������3��������ƻ������ļ��� 
*/
bool mark[1005];
int main(){
	//freopen("E://a.txt", "r", stdin);//��ȡ���� 
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
					if(!mark[i] && nowSum > num){//ͳ�Ƶ���ƻ��ֻͳ��һ�� 
						mark[i] = true;
						dropNum++;
					}
					nowSum = num;//ֻҪ����num����0�������Ƿ���ڶ�Ҫ����nowSum 
				}
			}
		}
		total += nowSum;
	}
	for(int i = 0; i < N; ++i){
		if(mark[i] && mark[(i + 1) % N] && mark[(i + 2) % N]){//ȥ�� 
			++E;
//			if(N == 3){//��������������Ļ���E���ֻ����1�������2�����ظ��ģ����ύ��ʾwrong 
//				break;
//			} 
		}
	}
	printf("%d %d %d\n", total, dropNum, E);
	return 0;
} 
