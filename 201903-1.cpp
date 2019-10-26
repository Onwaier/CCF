#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 5;
int arr[MAX];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	//freopen("E:\\a.txt", "r", stdin);
	int n, maxNum = INT_MIN, minNum = INT_MAX;//输入n个整数
	double midNum = 0.0;
	scanf("%d", &n);
	if(n == 0){
		printf("0 0 0\n");
		return 0;
	}
	for(int i = 0; i < n; ++i){
		scanf("%d", &arr[i]);
		if(maxNum < arr[i]){
			maxNum = arr[i];
		}
		if(minNum > arr[i]){
			minNum = arr[i];
		}
	} 
	if(n & 1){
		midNum = arr[n / 2];
	}
	else{
		midNum = (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
	}
	if(midNum - int(midNum) == 0)
		printf("%d %d %d", maxNum, (int)midNum, minNum);
	else
		printf("%d %.1f %d", maxNum, midNum, minNum);
	return 0;
} 
