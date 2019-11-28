#include<bits/stdc++.h> 
using namespace std;

#define MAX (1000 + 5)
int arr[MAX];
int main(){
	freopen("E://a.txt", "r", stdin);
	int n, minVal = 1 << 30;
	scanf("%d", &n);
	for(int i = 0; i < n ; ++i){
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+ n);
	for(int i = 0; i < n - 1; ++i){
		if(arr[i + 1] - arr[i] < minVal){
			minVal = arr[i + 1] - arr[i];
		}
	}
	printf("%d\n", minVal);
	return 0;
}
