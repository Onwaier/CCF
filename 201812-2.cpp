//
// Created by onwaier on 2019/11/6.
//

#include <cstdio>
using namespace std;

int main(){
    freopen("/home/onwaier/CLionProjects/CFFSolutions/a.txt", "r", stdin);
    int last[4];// 空 r, y, g
    for(int i = 1; i <= 3; ++i){
        scanf("%d", &last[i]);
    }
    int n, k, t;
    long long sum = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        scanf("%d%d", &k, &t);
        if(k == 0){
            sum += t;
            continue;
        }
        int tmp = sum % (last[1] + last[2] + last[3]);
        while(t < tmp){
            k = k - 1;
            if(k == 0){
                k = 3;
            }
            t +=  last[k];
        }
        t = t - tmp;
        switch (k){
            case 1://红灯
                sum += t;
                break;
            case 2://黄灯
                sum += (t + last[1]);
                break;
            case 3://绿灯
                break;
            default:
                break;
        }
    }
    printf("%lld\n", sum);
    return 0;
}