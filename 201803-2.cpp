#include<bits/stdc++.h> 
using namespace std;

#define MAX (100 + 5)

struct Node{
	int pos;
	int idx;
	bool operator < (const Node& a)const{
		return pos < a.pos;
	}
};
bool cmp(Node &a, Node &b){
	return a.idx < b.idx;
}
Node res[MAX];
int speed[MAX];
int main(){
	freopen("E:\\a.txt", "r", stdin);
	int n, L, t;//С����Ŀ �߶γ��� t���
	scanf("%d%d%d", &n, &L, &t) ;
	for(int i = 0; i < n; ++i){
		scanf("%d", &res[i].pos);
		res[i].idx = i;
		speed[i] = 1;
	}
	sort(res, res + n);//��pos���� 
	for(int i = 0; i < t; ++i){//t�� 
		for(int j = 0; j < n; ++j){//n��С���λ�� 
			res[j].pos += speed[j];
		}
		for(int j = 0; j < n; ++j){//�������˻���ײ 
			if(res[j].pos == 0 || res[j].pos == L){
				speed[j] = -speed[j];
			}
			else if(j < n - 1 && res[j].pos == res[j + 1].pos){
				speed[j] = -speed[j];
				speed[j + 1] = -speed[j + 1];
				++j;
			}
		}
	}
	sort(res, res +n ,cmp);//��idx���� 
	for(int i = 0; i < n; ++i){
		printf("%s%d", i == 0?"":" ", res[i].pos);
	}
	printf("\n");
	return 0;
}
