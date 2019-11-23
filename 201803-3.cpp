#include<bits/stdc++.h> 
using namespace std;

vector<pair<string, vector<string> > >rules;
void split(string s, char ch, vector<string>&words){
	int idx = 0, tmp, len = s.size();
	if(s == "/"){
		return;
	}
	while((tmp = s.find(ch, idx)) != -1){
		if(tmp != idx){
			words.push_back(s.substr(idx, (tmp - idx)));
		}
		idx = tmp + 1;
	}
	if(s[len - 1] == '/') {
		words.push_back("/");
	}
	else{
		words.push_back(s.substr(idx));
	}
}

bool isNum(string s){
	bool flag = true;
	for(int i = 0; i < s.size(); ++i){
		if(!isdigit(s[i])){
			flag = false;
			break;
		}
	}
	return flag;
}
int main(){
	//freopen("E://a.txt", "r",stdin);
	int n, m, ruleIdx;
	string str;
	vector<string>words;
	pair<string, vector<string> >rule;
	scanf("%d%d", &n, &m);
	getchar();
	for(int i = 0; i < n; ++i){
		words.clear();
		getline(cin, str);
		split(str, ' ', words);
		rule.first = words[1];
		string tmp = words[0];
		words.clear();
		split(tmp, '/', words);
		rule.second = words;
//		for(int j = 0; j < words.size(); ++j){
//			cout << words[j] << " ";
//		}
//		cout << endl;
		rules.push_back(rule);
		//cout << str << endl;
	}
	for(int i = 0; i < m; ++i){
		getline(cin, str);
		
		words.clear();
		split(str, '/', words);
//		for(int j = 0; j < words.size(); ++j){
//			cout << words[j] << " ";
//		}
//		cout << endl;
		bool flag = false;
		for(int j = 0; j < n; ++j){
			vector<string>ru(rules[j].second);
			int len1 = words.size(), len2 = ru.size();
			if(len1 < len2){
				continue;
			}
			int k;
			for(k = 0; k < ru.size(); ++k){
				//cout << rules[j].second[k] << endl;
				if(ru[k] == "<int>"){
					if(!isNum(words[k])){
						break;
					}
				}
				else if(ru[k] == "<path>"){
					if(words[k] != "/")
						flag = true;
					break;		
				}
				else if(ru[k] != "<str>" && ru[k] != words[k]){
					break;
				}
			}
			if((!flag && k != len1) || (!flag && k == len1 && k != len2)){
				continue;
			}
			flag = true;
			cout << rules[j].first;
			for(int k = 0; k < rules[j].second.size(); ++k){
				if(rules[j].second[k] == "<int>"){
					int idx = 0;
					while(idx < words[k].size() && words[k][idx] == '0'){
						++idx;
					}
					if(idx == words[k].size()){
						cout << " " << "0";
					}
					else{
						cout << " " << words[k].substr(idx);
					}
				}
				else if(rules[j].second[k] == "<path>"){
					for(int t = k; t < words.size(); ++t){
						if(t == k)
							cout << " " << words[t];
						else if(t == words.size() - 1){
							if(words[t] == "/")
								cout << "/";
							else
								cout << "/" << words[t];
						}
						else{
							cout << "/" << words[t];
						}
					}
					break;
				}
				else if(rules[j].second[k] == "<str>"){
					cout << " " << words[k];
				}	
			}
			cout << endl;
			break;
		}
		if(!flag){
			cout << "404" << endl;
		}
	}
	return 0;
}
