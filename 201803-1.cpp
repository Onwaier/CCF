#include<bits/stdc++.h>
using namespace std;

int main() {
	//freopen("E://a.txt", "r", stdin);
	int num, lastscore = 1, sum = 0;
	while(scanf("%d", &num) != EOF){
		if(num == 0){
			break;
		}
		if(num == 1){//没有跳到方块中心 
			lastscore = 1;		
		}
		else{
			if(lastscore == 1){// 上次没有跳到方块中心或第一次跳 
				lastscore = 2;
			}
			else{//连续跳到中心 
				lastscore += 2;
			}
		}
		sum += lastscore;
	}
	printf("%d\n", sum);
	return 0;
}
