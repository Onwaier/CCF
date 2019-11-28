#include<bits/stdc++.h> 
using namespace std;

#define MAX (20 + 5)
typedef long long int LL ;
string mons[] = {"Jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};//�����ִ�Сд 
string weeks[] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};//�����ִ�Сд 
int range[] = {60, 24, 31, 12, 7};
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<string, int>rela; 
vector<vector<string>>cron(MAX, vector<string>(6));
vector<pair<LL, int>>res;
int begYear, endYear; 

int getWeek(int year, int month, int day){//��ȡĳ�������ڼ� (���ж������Ƿ�Ϸ�)
	days[2] = 28;
	if(year % 4 == 0){//��Ϊ�Ǵ�1970-2099 
		days[2]  = 29;
	}
	if(day > days[month]) {
		return -1;
	}
	int sum = 4;//����������
	int cnt = (year - 1 - 1968) / 4;//������� 
	sum = sum + 365 * (year - 1970) + cnt;//��
	for(int i = 1; i < month; ++i) {//�� 
		sum = sum + days[i];
	}
	sum = sum + day - 1;
	return sum % 7; 
}

int getDay(int year, int month, int day)
{
	days[2] = 28;
	if (year % 4 == 0)
		days[2] = 29;
	if (day > days[month])	// �����ڲ�����
		return -1;
 
	int sum = 4, q = year - 1970;
	sum += q / 4 * 5 + q % 4;	// ÿ�����꣬sumӦ��+5
	if (q % 4 == 3)	// ��ʱ˵�� year-1 Ϊ����
		++sum;
	for (int i = 1; i != month; ++i)
		sum += days[i];
	sum += day - 1;
	return sum % 7;
}

int toNum(string s){
	if(isalpha(s[0])){
		for(int i = 0; i < s.size(); ++i){//ת��Сд 
			s[i] = tolower(s[i]);
		}
		return rela[s];
	}
	else{
		int num = 0;
		for(int i = 0; i < s.size(); ++i){//���ַ���ת������ 
			num = num * 10 + (s[i] - '0');
		}
		return num;
	} 
}
void deal2(string s, set<int>& nums) {
	int idx = 0;
	if((idx = s.find('-')) == -1){
		nums.insert(toNum(s));
	}
	else{
		int beg = toNum(s.substr(0, idx));
		int end = toNum(s.substr(idx + 1));
		for(int i = beg; i <= end; ++i){
			nums.insert(i);
		}
	}
}
void deal(string& s, set<int>& nums, int j){//���ַ�����ȡ���� �����˳��Ϊ��"*"�� "," ��"-" 
	//����"*"
	if(s == "*"){
		for(int i = 0; i < range[j]; ++i){
			if(j == 2 || j == 3){
				nums.insert(i + 1);
			}
			else{
				nums.insert(i);
			}
		}
		return;
	}
	//����","Ϊ����ָ������ַ���s�������","
	s.append(",");
	int idx = 0, tmp;
	string str;
	while((tmp = s.find(',', idx)) != -1){//��","�ָ� 
		str = s.substr(idx, tmp - idx);
		//����"-"�ָ�
		deal2(str, nums);
		idx = tmp + 1;
	} 
}

void calNum(vector<vector<LL>>& v, set<int>& nums, int j, LL mul){
	if(j == 0){
		for(auto it = nums.begin(); it != nums.end(); ++it){
			v[j].push_back(*it);
		}
	}
	else{
		if(j < 4){
			for(auto it = nums.begin(); it != nums.end(); ++it){
				for(int i = 0; i < v[j - 1].size(); ++i){
					v[j].push_back(*it * mul + v[j - 1][i]);
				}
			}
		}
		else{//�����ж� 
			int mark[7] = {0};
			for(auto it = nums.begin(); it != nums.end(); ++it){
				mark[*it] = 1;
			}
			for(int i = begYear; i <= endYear; ++i){
				for(int k = 0; k < v[j - 1].size(); ++k){
					int month = v[j - 1][k] / 1000000;
					int day = v[j - 1][k] / 10000 % 100;
					if(getWeek(i, month, day) != -1 && mark[getWeek(i, month, day)]){
						v[j].push_back(i * mul + v[j - 1][k]);
					}
				}
			}
		}
	}
}
int main(){
//	freopen("E:\\a.txt", "r", stdin);
	int n;
	string str;
	long long s, t; 
	
	//�����·ݺ����ڵ�Ӣ����д ���Ӧ���ֵĹ�ϵ
	for(int i = 0; i < 12; ++i){
		rela[mons[i]] = i + 1;
	}
	for(int i = 0; i < 7; ++i){
		rela[weeks[i]] = i;
	}
	//�������� 
	scanf("%d%lld%lld", &n, &s, &t);
	begYear = s / 100000000;
	endYear = t / 100000000;
	getchar();
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 6; ++j){
			cin >> cron[i][j];
		}
	}
	for(int i = 0; i < n; ++i){
		vector<vector<LL>>v(5, vector<LL>());
		LL mul = 1;
		for(int j = 0; j < 5; ++j){
			set<int>nums;
			deal(cron[i][j], nums, j);
			calNum(v, nums, j, mul);//�������cron������Ϣ��ʱ�� 
			mul = mul * 100;
		}
		for(int j = 0; j < v[4].size(); ++j){ 
			if(v[4][j] >= s && v[4][j] < t){//������������ʱ��ŵ�vector�У�ʹ��pair��Ϊ����ͬʱ�̵�cron�������˳�����  
				res.push_back(make_pair(v[4][j], i));
			}
		}
	} 
	sort(res.begin(), res.end());//���� 
	for(int i = 0; i < res.size(); ++i){//��� 
		cout << res[i].first << " " << cron[res[i].second][5] << endl;
	}
	return 0;
}
