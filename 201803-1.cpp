#include<bits/stdc++.h>
using namespace std;

int main() {
	//freopen("E://a.txt", "r", stdin);
	int num, lastscore = 1, sum = 0;
	while(scanf("%d", &num) != EOF){
		if(num == 0){
			break;
		}
		if(num == 1){//û�������������� 
			lastscore = 1;		
		}
		else{
			if(lastscore == 1){// �ϴ�û�������������Ļ��һ���� 
				lastscore = 2;
			}
			else{//������������ 
				lastscore += 2;
			}
		}
		sum += lastscore;
	}
	printf("%d\n", sum);
	return 0;
}
