#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;
const long long NUM = (long long)(1e9);
/*
#define NUM 1000000000 »áÒç³ö 
*/
struct Node{
	ll id;
	int score;
	Node(ll id, int score):id(id), score(score){};
	bool operator < (const Node& a)const{
		if(score == a.score) {
			return id < a.id;
		}
		else{
			return score > a.score;
		}
	} 
};
unordered_map<ll, set<Node>::iterator>um;
set<Node>comms;
int cnt[55];
int main(){
	//freopen("E:\\a.txt", "r", stdin);
	int m, n, id, score, op;
	int num, type, comm, sum;
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &id, &score);
		for(int j = 0; j < m; ++j){
			ll no = j * NUM + id; 
			um[no] = comms.insert(Node(no, score)).first;
		}
	}
	scanf("%d", &op);
	for(int i = 0; i < op; ++i){
		scanf("%d", &num);
		if(num == 1){
			scanf("%d%d%d", &type, &comm, &score);
			ll no = type * NUM + comm;
			um[no] = comms.insert(Node(no, score)).first;
		}
		else if(num == 2){
			scanf("%d%d", &type, &comm);
			ll no = type * NUM + comm;
			comms.erase(um[no]);
			um.erase(no);
		}
		else if(num == 3){
			scanf("%d", &sum);
			for(int j = 0; j < m; ++j){
				scanf("%d", &cnt[j]);	
			}
			vector<vector<int> >res(55); 
			for(auto& it:comms){
				type = it.id / NUM;
				comm = it.id % NUM;
				if(cnt[type]){
					res[type].push_back(comm);
					--cnt[type];
					--sum;
					if(sum == 0){
						break;
					}
				}
			}
			for(int j = 0; j < m; ++j){
				if(res[j].size() == 0){
					printf("-1\n");
				}
				else{
					//sort(res[j].begin(), res[j].end());
					for(int t = 0; t < res[j].size(); ++t){
						printf("%s%d", t == 0?"":" ", res[j][t]);
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
}
