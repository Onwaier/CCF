#include<bits/stdc++.h> 
using namespace std;

#define MAX (20 + 5)
typedef long long int LL ;
string mons[] = {"Jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};//不区分大小写 
string weeks[] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};//不区分大小写 
int range[] = {60, 24, 31, 12, 7};
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<string, int>rela; 
vector<vector<string>>cron(MAX, vector<string>(6));
vector<pair<LL, int>>res;
int begYear, endYear; 

int getWeek(int year, int month, int day){//获取某天是星期几 (并判断日期是否合法)
	days[2] = 28;
	if(year % 4 == 0){//因为是从1970-2099 
		days[2]  = 29;
	}
	if(day > days[month]) {
		return -1;
	}
	int sum = 4;//计算总天数
	int cnt = (year - 1 - 1968) / 4;//闰年个数 
	sum = sum + 365 * (year - 1970) + cnt;//年
	for(int i = 1; i < month; ++i) {//月 
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
	if (day > days[month])	// 该日期不存在
		return -1;
 
	int sum = 4, q = year - 1970;
	sum += q / 4 * 5 + q % 4;	// 每隔四年，sum应该+5
	if (q % 4 == 3)	// 这时说明 year-1 为闰年
		++sum;
	for (int i = 1; i != month; ++i)
		sum += days[i];
	sum += day - 1;
	return sum % 7;
}

int toNum(string s){
	if(isalpha(s[0])){
		for(int i = 0; i < s.size(); ++i){//转成小写 
			s[i] = tolower(s[i]);
		}
		return rela[s];
	}
	else{
		int num = 0;
		for(int i = 0; i < s.size(); ++i){//将字符串转成数字 
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
void deal(string& s, set<int>& nums, int j){//从字符串提取数字 处理的顺序为："*"、 "," 和"-" 
	//处理"*"
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
	//处理","为方便分隔，在字符串s后面加上","
	s.append(",");
	int idx = 0, tmp;
	string str;
	while((tmp = s.find(',', idx)) != -1){//以","分隔 
		str = s.substr(idx, tmp - idx);
		//处理"-"分隔
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
		else{//星期判断 
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
	
	//建立月份和星期的英文缩写 与对应数字的关系
	for(int i = 0; i < 12; ++i){
		rela[mons[i]] = i + 1;
	}
	for(int i = 0; i < 7; ++i){
		rela[weeks[i]] = i;
	}
	//数据输入 
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
			calNum(v, nums, j, mul);//计算符合cron配置信息的时间 
			mul = mul * 100;
		}
		for(int j = 0; j < v[4].size(); ++j){ 
			if(v[4][j] >= s && v[4][j] < t){//将符合条件的时间放到vector中，使用pair是为了相同时刻的cron按输入的顺序输出  
				res.push_back(make_pair(v[4][j], i));
			}
		}
	} 
	sort(res.begin(), res.end());//排序 
	for(int i = 0; i < res.size(); ++i){//输出 
		cout << res[i].first << " " << cron[res[i].second][5] << endl;
	}
	return 0;
}
